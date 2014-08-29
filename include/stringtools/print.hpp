#ifndef _3b62481f_13d3_43ff_af72_fc09f41df448
#define _3b62481f_13d3_43ff_af72_fc09f41df448

#include <iostream>

namespace str{

namespace _{

template<typename T>
void do_print(T const& t)
{
    std::cout << t << std::endl;
}

template<typename T,typename... Args>
void do_print(T const& t, Args const&...args)
{
    std::cout << t << " ";
    do_print(args...);
}

}

template<typename... Args>
void print(Args const&... args)
{
    _::do_print(args...);
}

}

#endif
