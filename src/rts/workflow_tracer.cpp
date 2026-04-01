#include "workflow_tracer.h"
#include "record_format.h"


#ifdef ADD_DEBUG_INFO
WorkflowTracer::WorkflowTracer(
	int rank,
	size_t max_id_info_size,
	size_t max_cf_info_size
) :
	  id_info_(max_id_info_size, "id." + std::to_string(rank) + ".map.list"),
	  cf_info_(max_cf_info_size, "cf." + std::to_string(rank) + ".json.list"),
	  remaining_cfs_file_name_("pending." + std::to_string(rank) + ".json.list")
{}

void WorkflowTracer::cf_created(const CF *cf)
{
	cf_tracker_.cf_created(cf);
}

void WorkflowTracer::cf_info_ready(
	const CF *cf,
	const DependencyInfo &dependency_info
)
{
	cf_info_.add(format_cf_info(*cf, dependency_info));
}

void WorkflowTracer::cf_destroyed(const CF *cf)
{
	cf_tracker_.cf_destroyed(cf);
}

void WorkflowTracer::id_created(
	const Id &id,
	const std::string &name,
	int block_id
)
{
	id_info_.add(format_id_info(id, name, block_id));
}

size_t WorkflowTracer::cfs_remaining() const
{
	return cf_tracker_.cfs_remaining();
}

void WorkflowTracer::write_remaining()
{
	if (cf_tracker_.cfs_remaining()) {
		cf_tracker_.write_remaining(remaining_cfs_file_name_);
	}

	id_info_.flush();
	cf_info_.flush();
}
#endif
