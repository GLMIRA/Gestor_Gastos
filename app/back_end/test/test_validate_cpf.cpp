#include <gtest/gtest.h>

#include <back_end.hpp>


TEST(validateCPFTest, ValidCPFs){
    EXPECT_TRUE(validate_cpf("078.974.360-47"));
}

TEST(ValidateCPFTest, InvalidFormat) {
    EXPECT_FALSE(validate_cpf("12345678909"));
    EXPECT_FALSE(validate_cpf("123.456.789.09"));
    EXPECT_FALSE(validate_cpf("123-456-789-09"));
    EXPECT_FALSE(validate_cpf("123.456.789-0a"));
}

TEST(ValidateCPFTest, InvalidKnownCPFs) {
    EXPECT_FALSE(validate_cpf("000.000.000-00"));
    EXPECT_FALSE(validate_cpf("111.111.111-11"));
}

TEST(ValidateCPFTest, InvalidCheckDigits) {
    EXPECT_FALSE(validate_cpf("529.982.247-26")); // Alterado último dígito
}