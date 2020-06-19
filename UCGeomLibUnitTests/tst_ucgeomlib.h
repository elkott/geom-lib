#ifndef TST_UCGEOMLIB_H
#define TST_UCGEOMLIB_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>


using namespace std;
using namespace testing;

TEST(UCGeomLib, Test1)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

#endif // TST_UCGEOMLIB_H
