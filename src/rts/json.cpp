#include "json.h"

namespace {
    bool is_empty(const json::object &value)
    {
        return 
            "" == value.str
            || "{}" == value.str
            || "[]" == value.str;
    }
}

json::object json::serialize(const std::string &value)
{
    return {"\"" + value + "\""};
}

json::object json::serialize(const int &value)
{
    return {std::to_string(value)};
}

json::object json::serialize(const std::vector<int> &vector)
{
    return json::list_builder()
        .add(vector)
        .build();
}

void json::object_builder::reset()
{
    result.clear();
    result << "{";
    empty = true;
}

json::object_builder::object_builder() { reset(); }

json::object_builder &json::object_builder::add(
    const std::string &key, 
    const json::object &value,
    bool omit_empty
)
{
    if (omit_empty && is_empty(value)) {
        return *this;
    }

    if (!empty) {
        result << ",";
    }
    empty = false;

    result << serialize(key).str << ":" << value.str;

    return *this;
}

json::object json::object_builder::build()
{
    result << "}";

    const auto obj = json::object{result.str()};

    reset();

    return obj;
}

void json::list_builder::reset()
{
    result.clear();
    result << "[";
    empty = true;
}

json::list_builder::list_builder() { result << "["; }

json::list_builder &json::list_builder::add(
    const json::object &value,
    bool omit_empty
)
{
    if (omit_empty && is_empty(value)) {
        return *this;
    }

    if (!empty) {
        result << ",";
    }
    empty = false;

    result << value.str;

    return *this;
}

json::object json::list_builder::build()
{
    result << "]";

    const auto obj = json::object{result.str()};

    reset();

    return obj;
}