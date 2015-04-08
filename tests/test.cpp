#include <gtest/gtest.h>

#include "stringtools/all.hpp"

TEST(String, splitting)
{

    {
        auto const s = str::split(",");
        auto expected = std::vector<std::string>{"a","b"};
        EXPECT_EQ(expected,s("a,b"));
    }

    {
        auto const s = str::split(",");
        auto expected = std::vector<std::string>{"a","b","c"};
        EXPECT_EQ(expected,s("a,b,c"));
    }

    {
        auto const s = str::split("##");
        auto expected = std::vector<std::string>{"a","b","c"};
        EXPECT_EQ(expected,s("a##b##c"));
    }
}

TEST(String, joining)
{
    auto const j = str::join(",");
    EXPECT_EQ("a,b",j(std::vector<std::string>{"a","b"}));

    EXPECT_EQ(
        "a##b##ab",
        str::join("##")(std::vector<std::string>{"a","b","ab"})
    );
}

TEST(String, formating)
{
    auto s = str::format("bla %d")(5);

    EXPECT_EQ("bla 5",s);

    EXPECT_EQ("hello world",str::format("hello %s")("world"));

    auto const f = str::format("%s world");
    EXPECT_EQ("hello world",f("hello"));
    EXPECT_EQ("hello world",f(std::string("hello")));
}

TEST(dump, dump)
{
    EXPECT_EQ("hello",str::dump("hello"));
    EXPECT_EQ("hello world",str::dump("hello","world"));
    EXPECT_EQ("hello world 6",str::dump("hello","world", 6));

    std::vector<int> v{1,2,3,4};
    EXPECT_EQ("[1, 2, 3, 4]",str::dump(v));

    std::map<int,float> m{{1,5},{4,7.7}};
    EXPECT_EQ("{1: 5, 4: 7.7}",str::dump(m));

    std::pair<bool,std::string> p{true,"abc"};
    EXPECT_EQ("(true, \"abc\")",str::dump(p));
}


TEST(Print, print)
{
    str::print("hello");
    str::print("hello","world");
    str::print("hello","world",6);

    std::vector<int> v{1,2,3,4};
    str::print("values:",v);

    std::map<int,float> m{{1,5},{4,7.7}};
    str::print("map:",m);

    std::pair<bool,std::string> p{true,"abc"};
    str::print("pair:",p);
}

TEST(Trim,
trim)
{
    std::string s = " ...hello world! ";
    EXPECT_EQ(" ...hello world!",str::trim_right(" ")(s));
    EXPECT_EQ(" ...hello world!",str::trim_right()(s));
    EXPECT_EQ(" ...hello world",str::trim_right(" !")(s));
    EXPECT_EQ(" ...he",str::trim_right(" ! world")(s));

    EXPECT_EQ("...hello world! ",str::trim_left(" ")(s));
    EXPECT_EQ("...hello world! ",str::trim_left()(s));
    EXPECT_EQ("hello world! ",str::trim_left(" .")(s));
    EXPECT_EQ("hello world! ",str::trim_left(" . world")(s));
    EXPECT_EQ("world! ",str::trim_left(" . hello")(s));

    EXPECT_EQ("...hello world!",str::trim(" ")(s));
    EXPECT_EQ("...hello world!",str::trim()(s));
    EXPECT_EQ("...hello world",str::trim(" !")(s));
    EXPECT_EQ("hello world",str::trim(" .!")(s));
    EXPECT_EQ("he",str::trim(" . world!")(s));
    EXPECT_EQ("world!",str::trim(" . hello")(s));
}

TEST(Slice,slice)
{
    char buf[10];

    str::slice(buf,5) = "Hello World!";
    EXPECT_EQ(std::string("Hell"),buf);

    str::slice(buf) = "Hello World!";
    EXPECT_EQ(std::string("Hello Wor"),buf);

    str::slice(buf) = "";
    EXPECT_EQ(std::string(""),buf);

    str::slice(buf) += "H";
    EXPECT_EQ(std::string("H"),buf);
    str::slice(buf) += "W";
    EXPECT_EQ(std::string("HW"),buf);

    str::slice(buf) = std::string("X");
    EXPECT_EQ(std::string("X"),buf);

    str::slice(buf) += std::string("Y");
    EXPECT_EQ(std::string("XY"),buf);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
