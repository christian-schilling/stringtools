#include <gtest/gtest.h>

#include "snprintf-ex/format.hpp"

TEST(String, formating)
{
    auto s = std::string("bla %d") % format(5);

    EXPECT_EQ("bla 5",s);

    EXPECT_EQ("hello world","hello %s" %format("world"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
