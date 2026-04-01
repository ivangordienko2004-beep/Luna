#pragma once

#include "common.h"

#include <string>

#include "id.h"
#include "cf.h"


std::string format_id_info(
    const Id &id,
    const std::string &name,
    int block_id
);

std::string format_cf_info(
	const CF &cf,
	const DependencyInfo &dependency_info
);

std::string format_unfinished_cf_info(const CF &cf);
