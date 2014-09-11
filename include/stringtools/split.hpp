#ifndef _fb10edcd_3762_476a_88d3_6adf6b4796df
#define _fb10edcd_3762_476a_88d3_6adf6b4796df

#include <string>

namespace str{

class split
{
    std::string const seperator;

    void _split(std::vector<std::string>& v,std::string const& s) const
    {
        auto const spos = s.find(seperator);
        v.push_back(s.substr(0,spos));
        if(spos != std::string::npos){
            _split(v,s.substr(spos+seperator.size()));
        }
    }

public:
    split(std::string const& seperator):
        seperator(seperator)
    {}

    std::vector<std::string> operator () (std::string const& s) const
    {
        std::vector<std::string> v;
        _split(v,s);
        return v;
    }
};

}

#endif
