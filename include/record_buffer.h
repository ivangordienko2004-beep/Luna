#pragma once

#include <vector>
#include <string>
#include <mutex>


class RecordBuffer final
{
    mutable std::mutex m_;

    size_t max_size_;
    size_t current_size_ = 0;

    std::string file_name_;

    std::vector<std::string> records_;

public:
    RecordBuffer(
        size_t max_size,
        const std::string &file_name
    );

    void add(const std::string &record);

    void flush();

private:
	void flush_no_lock();

    bool full() const;

    bool empty() const;
};
