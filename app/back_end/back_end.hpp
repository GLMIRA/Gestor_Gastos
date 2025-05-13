#ifndef BACK_END
#define BACK_END

#include <string>

using namespace std;

void validate_user(const string &cpf_formatted, const string &first_name,
    const string &last_name, const string &age_user, int ((&error)[4]));
bool validate_cpf(const string &cpf_formatado);
bool validate_birthdate(const string &age_user);
bool validate_money_qtd(const string &salary_user);
bool validate_string_type_name(const string &first_name);
/*-----------------------validate expense--------------------------------*/
void validate_expense(const string &type_expense,const string &name_expense,
    const string &amount, const string &date_time, int((&error)[4]));
bool validate_date_time(const string &date_time);
bool validate_type_expense(const string &type_expense);
#endif
