#include <gtest/gtest.h>

#include<back_end.hpp>

TEST(validateAge, validAge){
    EXPECT_TRUE(validate_age("102"));
    EXPECT_TRUE(validate_age("20"));
}

