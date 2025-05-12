//Lib google_test
#include <gtest/gtest.h>

//modulo
#include<back_end/back_end.hpp>

TEST(validateFirstNameUserT, validFirstName){
    EXPECT_TRUE(validate_first_name("Gabriel"));
    EXPECT_TRUE(validate_first_name("João"));
    EXPECT_TRUE(validate_first_name("Ana Julia"));
}
TEST(validateFirstNameUserF, invalidFIrstName){
    EXPECT_FALSE(validate_first_name("456"));
    EXPECT_FALSE(validate_first_name("aaaa15234"));
    EXPECT_FALSE(validate_first_name(" "));
    EXPECT_FALSE(validate_first_name("' '"));
    EXPECT_FALSE(validate_first_name("/**/ {}"));
    EXPECT_FALSE(validate_first_name("t3stand0 !ss()"));
}