#include "record_buffer.h"

#include <fstream>
#include <cstdio>


RecordBuffer::RecordBuffer(
    size_t max_size,
    const std::string &file_name
) : max_size_(max_size), file_name_(file_name)
{
    std::remove(file_name.c_str());
}

void RecordBuffer::add(const std::string &record)
{
    std::lock_guard<std::mutex> lk(m_);

    records_.push_back(record);
    current_size_ += record.size();

    if (full()) {
        flush_no_lock();
    }
}

bool RecordBuffer::full() const
{
    return current_size_ >= max_size_;
}

bool RecordBuffer::empty() const
{
    return 0 == current_size_;
}

void RecordBuffer::flush()
{
	std::lock_guard<std::mutex> lk(m_);

	flush_no_lock();
}

void RecordBuffer::flush_no_lock()
{
	if (empty()) {
		return;
	}

	std::ofstream file(file_name_, std::ios::app);

	for (const auto &record : records_) {
		file << record << '\n';
	}

	file.flush();
	records_.clear();
	current_size_ = 0;
}