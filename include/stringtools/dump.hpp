#ifndef _8ddd5810_f8f6_4205_8fea_43a456886fde
#define _8ddd5810_f8f6_4205_8fea_43a456886fde

#include <sstream>
#include <map>
#include <vector>

namespace str{

namespace _{

template<typename T>
struct Dump
{
    static void to_string(std::string& output,T const& t)
    {
        std::stringstream ss;
        ss << t;
        output += ss.str();
    }
};

template<typename T>
struct Dump<std::vector<T>>
{
    static void to_string(std::string& output,std::vector<T> const& v)
    {
        output += "[";
        size_t i = 0;
        for(auto const& x: v){
            if(i){
                output += ", ";
            }
            Dump<T>::to_string(output,x);
            i++;
        }
        output += "]";
    }
};

template<>
struct Dump<bool>
{
    static void to_string(std::string& output,bool const b)
    {
        output += (b ? "true":"false");
    }
};

template<>
struct Dump<std::string>
{
    static void to_string(std::string& output,std::string const& s)
    {
        output += "\"" + s + "\"";
    }
};

template<typename T,typename T2>
struct Dump<std::pair<T,T2>>
{
    static void to_string(std::string& output,std::pair<T,T2> const& p)
    {
        output += "(";
        Dump<T>::to_string(output,p.first);
        output += ", ";
        Dump<T2>::to_string(output,p.second);
        output += ")";
    }
};

template<typename T,typename T2>
struct Dump<std::map<T,T2>>
{
    static void to_string(std::string& output,std::map<T,T2> const& m)
    {
        output += "{";
        size_t i = 0;
        for(auto const& x: m){
            if(i){
                output += ", ";
            }
            Dump<T>::to_string(output,x.first);
            output += ": ";
            Dump<T2>::to_string(output,x.second);
            i++;
        }
        output += "}";
    }
};


template<typename T>
void expand_string(std::string& output,T const& t)
{
    Dump<T>::to_string(output,t);
}

template<typename T,typename... Args>
void expand_string(std::string& output, T const& t, Args const&...args)
{
    Dump<T>::to_string(output,t);
    output += " ";
    expand_string(output,args...);
}

}

template<typename... Args>
std::string dump(Args const&... args)
{
    std::string output;
    _::expand_string(output,args...);
    return output;
}

}


#endif
