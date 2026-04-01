#include "replicating_locator.h"

#include "comm.h"

ReplicatingLocator::ReplicatingLocator(const int nodes_number, const int frequency)
					: frequency_(frequency)
{
	if (frequency_ == REPLICATE_TO_ALL) {
		destination_ranks_.resize(nodes_number);
		std::iota(destination_ranks_.begin(), destination_ranks_.end(), 0);
	} else {
		for (int i = 0; i < nodes_number; i += frequency_) {
			destination_ranks_.push_back(i);
		}
	}
	assert(!destination_ranks_.empty());
}

int ReplicatingLocator::get_next_rank(Comm &comm) const noexcept
{	
	auto current_node_rank = comm.rank();
	return (frequency_ == REPLICATE_TO_ALL) 
			? current_node_rank 
			: calculate_next_rank(current_node_rank, comm.size());
}

int ReplicatingLocator::calculate_next_rank(
		const int current_rank, const int nodes_number) const noexcept
{
	int calculateed_rank = ((current_rank + frequency_ / 2) / frequency_) * frequency_;
	if (calculateed_rank >= nodes_number) {
		calculateed_rank -= frequency_;
	}
	return calculateed_rank;
}

iterator ReplicatingLocator::begin() 
{
	return destination_ranks_.begin(); 
}

iterator ReplicatingLocator::end() 
{
	return destination_ranks_.end(); 
}

const_iterator ReplicatingLocator::cbegin() const
{
	return destination_ranks_.cbegin(); 
}

const_iterator ReplicatingLocator::cend() const
{
	return destination_ranks_.cend(); 
}


