#include <ctime>
#include <iomanip>
#include <string>

#include <gtest/gtest.h>

#include<back_end.hpp>

string crete_date_today(){
    
    
    time_t now = time(nullptr); 
    tm* date_today = localtime(&now);

    ostringstream oss;
    oss << put_time(date_today, "%d/%m/%Y:%H:%M:%S" );

    string date_to_test_true = oss.str();

    return date_to_test_true;
    
}

TEST(validateDateTime, validDateTime){
    EXPECT_TRUE(validate_date_time(crete_date_today()));
    EXPECT_TRUE(validate_date_time(crete_date_today()));
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