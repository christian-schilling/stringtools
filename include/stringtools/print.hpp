#ifndef _3b62481f_13d3_43ff_af72_fc09f41df448
#define _3b62481f_13d3_43ff_af72_fc09f41df448

#include <iostream>
#include <map>
#include <vector>

namespace str{

namespace _{

template<typename T>
struct Do
{
    static void print(T const& t)
    {
        std::cout << t;
    }
};

template<typename T>
struct Do<std::vector<T>>
{
    static void print(std::vector<T> const& v)
    {
        std::cout << "[";
        size_t i = 0;
        for(auto const& x: v){
            if(i){
                std::cout << ", ";
            }
            Do<T>::print(x);
            i++;
        }
        std::cout << "]";
    }
};

template<>
struct Do<bool>
{
    static void print(bool const b)
    {
        std::cout << (b ? "true":"false");
    }
};

template<>
struct Do<std::string>
{
    static void print(std::string const& s)
    {
        std::cout << "\"" << s << "\"";
    }
};

template<typename T,typename T2>
struct Do<std::pair<T,T2>>
{
    static void print(std::pair<T,T2> const& p)
    {
        std::cout << "[";
        Do<T>::print(p.first);
        std::cout << ", ";
        Do<T2>::print(p.second);
        std::cout << "]";
    }
};

template<typename T,typename T2>
struct Do<std::map<T,T2>>
{
    static void print(std::map<T,T2> const& m)
    {
        std::cout << "{";
        size_t i = 0;
        for(auto const& x: m){
            if(i){
                std::cout << ", ";
            }
            Do<T>::print(x.first);
            std::cout << ": ";
            Do<T2>::print(x.second);
            i++;
        }
        std::cout << "}";
    }
};


template<typename T>
void expand_print(T const& t)
{
    Do<T>::print(t);
    std::cout << std::endl;
}

template<typename T,typename... Args>
void expand_print(T const& t, Args const&...args)
{
    Do<T>::print(t);
    std::cout << " ";
    expand_print(args...);
}

}

template<typename... Args>
void print(Args const&... args)
{
    _::expand_print(args...);
}

}

#endif
