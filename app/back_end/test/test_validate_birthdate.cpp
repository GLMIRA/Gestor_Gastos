#include <gtest/gtest.h>

#include<back_end.hpp>

//TODO: REFATORAR OS TESTES, para que aceitem a função
TEST(validateBirthdate, validAge){
    EXPECT_TRUE(validate_birthdate("10/12/2000"));
    EXPECT_TRUE(validate_birthdate("01/01/1901"));
}

TEST(validadteBirthdate, invalidAge){
    EXPECT_FALSE(validate_birthdate("letras"));
    EXPECT_FALSE(validate_birthdate(",.;~´'][12]"));
    EXPECT_FALSE(validate_birthdate(" ;. /?!@#$567890"));
    EXPECT_FALSE(validate_birthdate("12"));
    EXPECT_FALSE(validate_birthdate("01/01/2015"));
    EXPECT_FALSE(validate_birthdate("01/01/2035"));
    EXPECT_FALSE(validate_birthdate("1/1/2035"));
}

