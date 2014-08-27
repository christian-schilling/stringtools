#ifndef _7df49b46_cfba_4b93_95ed_8a062f5a3c4b
#define _7df49b46_cfba_4b93_95ed_8a062f5a3c4b

#include <string>
#include <functional>
#include <cstdio>

namespace stringtools{
template<typename... Args>
struct Format
{
    Format(Args... args)
    {
        f = std::bind([](char const*const s, Args... args)->std::string{
            auto l = snprintf(nullptr, 0, s, args...);
            if (l > 0) {
                std::vector<char> out(l+1);
                snprintf(out.data(), l + 1, s, args...);
                return out.data();
            }
            return "";
        },std::placeholders::_1,args...);
    }
    std::function<std::string(char const*)> f;

    std::string operator () (std::string const& s) const
    {
        return f(s.c_str());
    }
};

}

template<typename... Args>
stringtools::Format<Args...> format(Args... args)
{
    return stringtools::Format<Args...>(args...);
}


template<typename F>
std::string operator % (std::string const& s, F const& f)
{
    return f(s);
}

template<typename F>
std::string operator % (char const*const s, F const& f)
{
    return f(s);
}

#endif
