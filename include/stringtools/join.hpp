#ifndef _0be72e07_d229_4b79_981d_61812416f783
#define _0be72e07_d229_4b79_981d_61812416f783

#include <string>

namespace str{

class join
{
    std::string const seperator;

public:
    join(std::string const& seperator):
        seperator(seperator)
    {}

    template<typename Strings>
    std::string operator () (Strings const& strings) const
    {
        std::string joined;
        for(std::string const& s: strings){
            if(joined.size()){
                joined += seperator;
            }
            joined += s;
        }
        return joined;
    }
};

}

#endif
