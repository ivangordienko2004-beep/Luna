#include "cf_tracker.h"

#include <fstream>

#include "common.h"
#include "cf.h"
#include "record_format.h"

void CFTracker::cf_created(const CF *cf)
{
    std::lock_guard<std::mutex> lk(m_);

    cfs_.insert(cf);
}

void CFTracker::cf_destroyed(const CF *cf)
{
    std::lock_guard<std::mutex> lk(m_);

    cfs_.erase(cf);
}

size_t CFTracker::cfs_remaining() const
{
    std::lock_guard<std::mutex> lk(m_);

    return cfs_.size();
}

void CFTracker::write_remaining(const std::string &file_name) const
{
    std::lock_guard<std::mutex> lk(m_);
    
    std::ofstream out(file_name);

    for (const auto &cf : cfs_) {
        out << format_unfinished_cf_info(*cf) << '\n';
    }

    out.flush();
}
