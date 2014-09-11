#ifndef _3b62481f_13d3_43ff_af72_fc09f41df448
#define _3b62481f_13d3_43ff_af72_fc09f41df448

#include <iostream>
#include "stringtools/dump.hpp"

namespace str{


template<typename... Args>
void print(Args const&... args)
{
    std::cout << dump(args...) << std::endl;
}

}

#endif
