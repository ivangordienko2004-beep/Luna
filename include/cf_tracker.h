#pragma once

#include "common.h"

#include <set>
#include <mutex>


class CF;


class CFTracker 
{
    mutable std::mutex m_;

    std::set<const CF*> cfs_;

public:
    void cf_created(const CF*);

    void cf_destroyed(const CF*);

    size_t cfs_remaining() const;
    
    void write_remaining(const std::string &file_name) const;
};
