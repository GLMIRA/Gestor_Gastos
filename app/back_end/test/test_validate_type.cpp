//Lib google_test
#include <gtest/gtest.h>

//modulo
#include<back_end/back_end.hpp>

TEST(validatTypeT, validType){
    EXPECT_TRUE(validate_type("s"));
    EXPECT_TRUE(validate_type("S"));
    EXPECT_TRUE(validate_type("N"));
    EXPECT_TRUE(validate_type("n"));
}

TEST(validatTypeF, validType){
    EXPECT_FALSE(validate_type("456"));
    EXPECT_FALSE(validate_type("aaaa15234"));
    EXPECT_FALSE(validate_type(" "));
    EXPECT_FALSE(validate_type("' '"));
    EXPECT_FALSE(validate_type("/**/ {}"));
    EXPECT_FALSE(validate_type("t3stand0 !ss()"));
    EXPECT_FALSE(validate_type("nao"));
    EXPECT_FALSE(validate_type("sim"));
}