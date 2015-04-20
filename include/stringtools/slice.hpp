#ifndef _b488f8c3_da4e_4d97_bf61_a5899d1987ca
#define _b488f8c3_da4e_4d97_bf61_a5899d1987ca

#include <string>

namespace str {
struct Slice
{
    size_t const length;
    char* const buf;

    Slice(char* const buf, size_t const length):
        length(length-1),
        buf(buf)
    {}

    Slice& operator+=(char const*const src)
    {
        strncat(buf,src,length);
        return *this;
    }

    Slice& operator+=(std::string const src)
    {
        return *this += src.c_str();
    }

    template<typename S>
    Slice& operator=(S const& src)
    {
        buf[0] = 0;
        *this += src;
        return *this;
    }
};

template<size_t L>
Slice slice(char (&buf)[L])
{
    return Slice(buf,L);
}

inline Slice slice(char* const buf, size_t const length)
{
    return Slice(buf,length);
}

}


#endif
