#include <gtest/gtest.h>

#include<back_end.hpp>

//TODO: REFATORAR OS TESTES, para que aceitem a função
TEST(validateAge, validAge){
    EXPECT_TRUE(validate_age("102"));
    EXPECT_TRUE(validate_age("20"));
}

TEST(validadteAge, invalidAge){
    EXPECT_FALSE(validate_age("letras"));
    EXPECT_FALSE(validate_age(",.;~´'][12]"));
    EXPECT_FALSE(validate_age(" ;. /?!@#$567890"));
}
