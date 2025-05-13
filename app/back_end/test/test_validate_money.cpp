#include <gtest/gtest.h>

#include <back_end.hpp>


TEST(validateSalaryTestT, validateSalary){
    EXPECT_TRUE(validate_money_qtd("1234,45"));
    EXPECT_TRUE(validate_money_qtd("1000000"));
}
TEST(validateSalaryTestF, invalidSalary){
    EXPECT_FALSE(validate_money_qtd("letras"));
    EXPECT_FALSE(validate_money_qtd("~´];~´-#$@"));
    EXPECT_FALSE(validate_money_qtd("  "));
}


