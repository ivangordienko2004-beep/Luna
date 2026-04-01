#pragma once


#include <vector>
#include "id.h"


struct DependencyInfo {
	std::vector<Id> in;
	std::vector<Id> out;
};
