#ifndef BACK_END
#define BACK_END

#include <string>

using namespace std;

int validate_user(const string &cpf_formatted, const string &first_name,
    const string &last_name, const string &age_user, const string &salary);

bool validate_cpf(const string &cpf_formatado);
bool validate_first_name(const string &name_user);
bool validate_last_name(const string &last_name);
bool validate_birthdate(const string &age_user);
bool validate_money_qtd(const string &salary_user);

#endif
