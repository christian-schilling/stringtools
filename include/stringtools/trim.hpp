#ifndef _89a91afc_eea6_43ab_81a3_95b148dc7af5
#define _89a91afc_eea6_43ab_81a3_95b148dc7af5

#include <string>

namespace str{

class trim_right
{
    std::string const chars;

public:
    trim_right(std::string const& chars):
        chars(chars)
    {}

    trim_right():
        trim_right(" ")
    {}

    std::string operator () (std::string const& string) const
    {
        size_t end = string.find_last_not_of(chars);
        if( std::string::npos != end )
        {
            return string.substr( 0, end+1 );
        }
        else{
            return string;
        }
    }
};

class trim_left
{
    std::string const chars;

public:
    trim_left(std::string const& chars):
        chars(chars)
    {}

    trim_left():
        trim_left(" ")
    {}

    std::string operator () (std::string const& string) const
    {
        size_t start = string.find_first_not_of(chars);
        if( std::string::npos != start )
        {
            return string.substr(start);
        }
        else{
            return string;
        }
    }
};

class trim
{
    std::string const chars;

public:

    trim(std::string const& chars):
        chars(chars)
    {}

    trim():
        trim(" ")
    {}

    std::string operator () (std::string const& string) const
    {
        return trim_right(chars)(trim_left(chars)(string));
    }
};


}

#endif
