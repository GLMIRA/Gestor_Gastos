#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

#include "dados/structs_dados.hpp"

using namespace std;


int change_string_to_int(const string &age_user){
    int age = 0;
    age = stoi(age_user);
    return age;
}

float change_string_to_float(const string &salary_user){
    float salary = 0.0;
    salary = stof(salary_user);
    return salary;
}

bool add_user_in_struct(const string &cpf_formatted, const string &first_name,
const string &last_name, const string &age_user, const string &salary){
    
    return true;

}