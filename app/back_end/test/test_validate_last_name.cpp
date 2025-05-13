//Lib google_test
#include <gtest/gtest.h>

//modulo
#include<back_end/back_end.hpp>

TEST(validateFirstLastUserT, validLasttName){
    EXPECT_TRUE(validate_last_name("Gabriel"));
    EXPECT_TRUE(validate_last_name("João"));
    EXPECT_TRUE(validate_last_name("Ana Julia"));
}
TEST(validateLastNameUserF, invalidLastName){
    EXPECT_FALSE(validate_last_name("456"));
    EXPECT_FALSE(validate_last_name("aaaa15234"));
    EXPECT_FALSE(validate_last_name(" "));
    EXPECT_FALSE(validate_last_name("' '"));
    EXPECT_FALSE(validate_last_name("/**/ {}"));
    EXPECT_FALSE(validate_last_name("t3stand0 !ss()"));
}