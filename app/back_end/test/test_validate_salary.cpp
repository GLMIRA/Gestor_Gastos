#include <gtest/gtest.h>

#include <back_end.hpp>


TEST(validateSalaryTest, validateSalary){
    EXPECT_TRUE(validate_salary("1234,45"));
    EXPECT_TRUE(validate_salary("1000000"));
}
TEST(validateSalaryTest, invalidSalary){
    EXPECT_FALSE(validate_salary("letras"));
    EXPECT_FALSE(validate_salary("~´];~´-#$@"));
    EXPECT_FALSE(validate_salary(" "));
}


