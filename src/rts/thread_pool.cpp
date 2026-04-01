#include "thread_pool.h"

#include <cassert>
#include <sched.h>
#include <sstream>

#include "common.h"

ThreadPool::ThreadPool()
	: on_empty_handler_([](){}), on_submit_handler_([](){}), running_jobs_(0), stop_flag_(false)
{
	stop();
}

void ThreadPool::start(ThreadPoolType type, size_t threads_num, bool cpu_usage_info)
{
	std::lock_guard<std::mutex> lk(m_);
	if (stop_flag_) {
		throw std::runtime_error("start while stopping ThreadPool");
	}
	type_ = type;
	if (cpu_usage_info) {
		cpu_usage_flags_.resize(std::thread::hardware_concurrency());
	}

	for (auto i=0u; i<threads_num; i++) {
		threads_.push_back(new std::thread([this](){
			this->routine();
		}));
	}
}

void ThreadPool::stop()
{
	std::unique_lock<std::mutex> lk(m_);
	if (stop_flag_) {
		throw std::runtime_error("stop while stopping ThreadPool");
	}

	stop_flag_=true;
	cv_.notify_all();

	while (!threads_.empty()) {

		std::thread *t=threads_.back();
		threads_.pop_back();

		lk.unlock();

		t->join();
		delete t;

		lk.lock();
	}

	if (!cpu_usage_flags_.empty()) {
		std::ostringstream cpu_usage_stream;
		cpu_usage_stream << types_to_strings_[type_] << " (cpu usage): [\t";
		for (int i = 0; i < cpu_usage_flags_.size(); ++i) {
			cpu_usage_stream << i << " cpu" << " : " << (cpu_usage_flags_[i] ? "yes" : "no") << "\t";
		}
		cpu_usage_stream << "]\n";
		INFO(cpu_usage_stream.str());
	}

#ifdef CORES_OCCUPANCY
	if (cores_occupancy_.size() > 0) {
		size_t counter = 0;
		for (const auto &kv : cores_occupancy_) {
			const auto freq = kv.second;
			counter += freq;
		}

		std::ostringstream out;
		out << std::fixed;
		out.precision(5);

		out << types_to_strings_[type_];
		out << " [\t";
		for (const auto &kv : cores_occupancy_) {
			const auto cpu = kv.first;
			const auto freq = kv.second;
			out << cpu << " cpu" << " : " << freq << " tasks" << " (" << (double) freq / counter << "%)" << "\t";
		}
		out << "]" << std::endl;
		SHOW_CORES(out.str());
	}
#endif

	stop_flag_=false;
}

void ThreadPool::submit(std::function<void()> job)
{
	std::lock_guard<std::mutex> lk(m_);
	jobs_.push(job);

    on_submit_handler_();

	cv_.notify_one();
}

void ThreadPool::on_empty(std::function<void()> on_empty_handler)
{
    std::lock_guard<std::mutex> lk(m_);
    on_empty_handler_ = on_empty_handler;
}

void ThreadPool::on_submit(std::function<void()> on_submit_handler)
{
    std::lock_guard<std::mutex> lk(m_);
    on_submit_handler_ = on_submit_handler;
}

std::string ThreadPool::to_string() const
{
	std::lock_guard<std::mutex> lk(m_);
	return std::to_string(threads_.size()) + "Th "
		+ std::to_string(jobs_.size()) + "Jb "
		+ std::to_string(running_jobs_) + " RJ "
		+ (stop_flag_? "S": "");
}

bool ThreadPool::has_jobs()
{
    std::lock_guard<std::mutex> lk(m_);
    return !jobs_.empty();
}

void ThreadPool::routine()
{
	std::unique_lock<std::mutex> lk(m_);
	while (!stop_flag_ || !jobs_.empty() || running_jobs_>0) {
		if (jobs_.empty()) {
            on_empty_handler_();
			cv_.wait(lk);
			continue;
		}
		
		auto job=jobs_.front();
		jobs_.pop();
		running_jobs_++;

		const int cpu = sched_getcpu();
		if (!cpu_usage_flags_.empty()) {
			cpu_usage_flags_[cpu] = true;
		}
		
#ifdef CORES_OCCUPANCY
		cores_occupancy_[cpu]++;
#endif
		
		lk.unlock();

		job();

		lk.lock();

		assert(running_jobs_>0);
		running_jobs_--;
		if (running_jobs_==0 && stop_flag_) {
			cv_.notify_all();
		}
	}
}
