#include "record_format.h"

#include <sstream>

#include "json.h"


std::string format_id_info(
    const Id &id,
    const std::string &name,
    int block_id
)
{
    std::ostringstream out;

    const auto &indices = id.indices();
    assert(!indices.empty());

    auto i = 0;
    out << indices[i++];
    while (i < indices.size()) {
        out << ' ' << indices[i++];
    }

    out << '>' << name << ' ' << block_id;

    return out.str();
}

std::string format_cf_info(
	const CF &cf,
	const DependencyInfo &dependency_info
)
{
	const auto in_ids =
		json::list_builder()
			.add(dependency_info.in)
			.build();

	const auto out_ids =
		json::list_builder()
			.add(dependency_info.out)
			.build();

	const auto cf_info =
		json::object_builder()
#ifdef ADD_DEBUG_INFO
			.add("id", cf.cf_id())
			.add("h", cf.call_stack())
			.add("i", in_ids)
			.add("o", out_ids)
#endif // ADD_DEBUG_INFO
			.build();

    return cf_info.str;
}

std::string format_unfinished_cf_info(const CF &cf)
{
    json::list_builder awaited_list_builder;

#ifdef ADD_DEBUG_INFO
    for (const auto &it : cf.awaited()) {
        const auto &id = it.first;
        const auto &name = it.second;
        
        awaited_list_builder.add(
            json::object_builder()
                .add("i", id)
                .add("n", name)
                .build()
        );
    }
#endif // ADD_DEBUG_INFO

    const auto cf_description = 
        json::object_builder()
#ifdef ADD_DEBUG_INFO
            .add("id", cf.cf_id())
#endif // ADD_DEBUG_INFO
            .add("w", awaited_list_builder.build())
            .build();

    return cf_description.str;
}
