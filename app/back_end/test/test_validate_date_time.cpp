
#include <gtest/gtest.h>

#include<back_end.hpp>


TEST(validateDateTime, validDateTime){
    EXPECT_TRUE(validate_date_time("10/05/2025:12:30:12"));
    EXPECT_TRUE(validate_date_time("13/05/2025:00:30:12"));
}

TEST(validadteDateTime, invalidDateTime){
    EXPECT_FALSE(validate_date_time("letras"));
    EXPECT_FALSE(validate_date_time(",.;~´'][12]"));
    EXPECT_FALSE(validate_date_time(" ;. /?!@#$567890"));
    EXPECT_FALSE(validate_date_time("12"));
    EXPECT_FALSE(validate_date_time("01/01/2015:123456"));
    EXPECT_FALSE(validate_date_time("01/01/2035:24:64:65"));
    EXPECT_FALSE(validate_date_time("1/1/2035:123:123:-12"));
}