#pragma once

#include "locator.h"

#include <vector>
#include <numeric>
#include <cassert>

using rank_type = int;
using ranks_container = std::vector<rank_type>;

using iterator = ranks_container::iterator;
using const_iterator = ranks_container::const_iterator;

class ReplicatingLocator : public Locator
{
private:
	ranks_container destination_ranks_;

	int frequency_;

    static const int REPLICATE_TO_ALL = -1;

    int calculate_next_rank(int current_rank, int nodes_number) const noexcept;

public:

	~ReplicatingLocator() override = default;

	ReplicatingLocator(int nodes_number, int frequency);

	int get_next_rank(Comm &comm) const noexcept override;

	iterator begin();

	iterator end();

	const_iterator cbegin() const;

	const_iterator cend() const;


};
