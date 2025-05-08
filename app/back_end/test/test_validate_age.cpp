#include <gtest/gtest.h>

#include<back_end.hpp>

//TODO: REFATORAR OS TESTES, para que aceitem a função
TEST(validateAge, validAge){
    EXPECT_TRUE(validate_age("10/12/2000"));
    EXPECT_TRUE(validate_age("01/01/1901"));
}

TEST(validadteAge, invalidAge){
    EXPECT_FALSE(validate_age("letras"));
    EXPECT_FALSE(validate_age(",.;~´'][12]"));
    EXPECT_FALSE(validate_age(" ;. /?!@#$567890"));
    EXPECT_FALSE(validate_age("12"));
    EXPECT_FALSE(validate_age("01/01/2015"));
    EXPECT_FALSE(validate_age("01/01/2035"));
    EXPECT_FALSE(validate_age("1/1/2035"));
}

