#ifndef _adb801ae_ad74_49c2_b5c1_d3071b5b794e
#define _adb801ae_ad74_49c2_b5c1_d3071b5b794e

#include "stringtools/split.hpp"
#include "stringtools/join.hpp"
#include <string>

namespace str{

class replace
{
    split const original;
    join const replacement;

public:
    replace(std::string const& original,std::string const& replacement):
        original(original),
        replacement(replacement)
    {}

    std::string operator () (std::string const& string) const
    {
        return replacement(original(string));
    }
};

}


#endif
