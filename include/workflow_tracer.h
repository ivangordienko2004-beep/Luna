#pragma once

#include "cf_tracker.h"
#include "record_buffer.h"
#include "dependency_info.h"


class Id;
class CF;


class WorkflowTracer final
{
	CFTracker cf_tracker_;
	RecordBuffer id_info_;
	RecordBuffer cf_info_;

	const std::string remaining_cfs_file_name_;

public:
	WorkflowTracer(int rank, size_t max_id_info_size, size_t max_cf_info_size);

	void cf_created(const CF *);

	void cf_info_ready(
		const CF *,
		const DependencyInfo &
	);

	void cf_destroyed(const CF *);

	void id_created(
		const Id &,
		const std::string &name,
		int block_id
	);

	size_t cfs_remaining() const;

	void write_remaining();
};
