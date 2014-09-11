#ifndef _7df49b46_cfba_4b93_95ed_8a062f5a3c4b
#define _7df49b46_cfba_4b93_95ed_8a062f5a3c4b

#include <string>
#include <cstdio>

namespace str{

namespace _{

template<typename T>
struct FilterArgs
{
    static T const& filter(T const& t)
    {
        return t;
    }
};

template<>
struct FilterArgs<std::string>
{
    static char const* filter(std::string const& t)
    {
        return t.c_str();
    }
};

template<typename T>
auto filter_args(T const& t) -> decltype(FilterArgs<T>::filter(t))
{
    return FilterArgs<T>::filter(t);
}

}

struct format
{
    std::string const formatstring;

    format(std::string const& formatstring):
        formatstring(formatstring)
    {}

    template<typename... Args>
    std::string operator () (Args const&... args) const
    {
        auto const l = std::snprintf(
            nullptr,
            0,
            formatstring.c_str(),
            _::filter_args(args)...
        );
        if (l > 0) {
            std::vector<char> out(l+1);
            std::snprintf(
                out.data(),
                l + 1,
                formatstring.c_str(),
                _::filter_args(args)...
            );
            return out.data();
        }
        return "";
    }
};

}

#endif
