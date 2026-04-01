#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <functional>


namespace json
{
    struct object final
    {
        std::string str;
    };

    template<typename T>
    object serialize(const T &value)
    {
        return value.json();
    }

    object serialize(const std::string &value);

    object serialize(const int &value);

    object serialize(const std::vector<int> &vector);

    class object_builder final
    {
        std::ostringstream result;
        bool empty = true;

        void reset();
    
    public:
        object_builder();

        object_builder &add(
            const std::string &key, 
            const object &value,
            bool omit_empty = true
        );

        template<typename T>
        object_builder &add(
            const std::string &key,
            const T &value,
            bool omit_empty = true
        )
        {
            return add(key, serialize(value), omit_empty);
        }

        object build();
    };

    class list_builder final
    {
        std::ostringstream result;
        bool empty = true;

        void reset();
    
    public:
        list_builder();

        list_builder &add(
            const object &value,
            bool omit_empty = true
        );

        template<typename T>
        list_builder &add(
            const T &value,
            bool omit_empty = true
        )
        {
            return add(serialize(value), omit_empty);
        }

        template<typename T>
        list_builder &add(const std::vector<T> &items)
        {
            for (const auto &it : items) {
                add(it);
            }

            return *this;
        }

        object build();
    };
}
