#include <gtest/gtest.h>

#include "stringtools/format.hpp"
#include "stringtools/split.hpp"
#include "stringtools/join.hpp"

using SV = std::vector<std::string>;

TEST(String, splitting)
{

    {
        auto const s = split(",");
        auto expected = SV{"a","b"};
        EXPECT_EQ(expected,s("a,b"));
    }

    {
        auto const s = split(",");
        auto expected = SV{"a","b","c"};
        EXPECT_EQ(expected,s("a,b,c"));
    }

    {
        auto const s = split("##");
        auto expected = SV{"a","b","c"};
        EXPECT_EQ(expected,s("a##b##c"));
    }
}

TEST(String, joining)
{

    {
        auto const j = join(",");
        EXPECT_EQ("a,b",j(std::vector<std::string>{"a","b"}));
    }

    {
        EXPECT_EQ(
            "a##b##ab",
            join("##")(std::vector<std::string>{"a","b","ab"})
        );
    }

}

TEST(String, formating)
{
    auto s = std::string("bla %d") % format(5);

    EXPECT_EQ("bla 5",s);

    EXPECT_EQ("hello world","hello %s" %format("world"));

    auto const f = format("hello");
    EXPECT_EQ("hello world","%s world" % f);
    EXPECT_EQ("hello world",f(std::string("%s world")));
    EXPECT_EQ("hello world",f("%s world"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
