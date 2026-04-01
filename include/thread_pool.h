#pragma once

#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <unordered_map>

enum ThreadPoolType {
	WORKERS_POOL,
	COMM_RECEIVE_POOL,
	COMM_REQUEST_POOL
};

class ThreadPool
{
public:
	ThreadPool();

	// start (more) threads
	// Note: must not start while stop() is in progress
	void start(ThreadPoolType type, size_t threads_num, bool cpu_usage_info);

	// request threads stop and join them (also waits for the queue to
	// become empty)
	void stop();

	// add job
	void submit(std::function<void()>);

	void on_empty(std::function<void()>);

	void on_submit(std::function<void()>);

	bool has_jobs();

	virtual std::string to_string() const;

private:
	mutable std::mutex m_;
	std::condition_variable cv_;
	std::vector<std::thread*> threads_;
	std::vector<bool> cpu_usage_flags_;
	std::queue<std::function<void()> > jobs_;
	std::function<void()> on_empty_handler_;
	std::function<void()> on_submit_handler_;
	std::unordered_map<size_t, size_t> cores_occupancy_;
	size_t running_jobs_;
	bool stop_flag_;
	ThreadPoolType type_;

	void routine();

	std::unordered_map<int, std::string> types_to_strings_ = {
		{WORKERS_POOL, "Workers thread pool"},
		{COMM_RECEIVE_POOL, "Comm receive thread pool"},
		{COMM_REQUEST_POOL, "Comm request thread pool"}
	};
};

