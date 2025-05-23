#ifndef BACK_END
#define BACK_END

#include <string>

using namespace std;

/*-----------------------validate user-----------------------*/
/** 
* @brief: função pra validar um usuario com base nas outras
* funçoes de validação seguindo uma tebala de erro 
* |1 -> erro de cpf           |
* |2 -> erro de primeiro nome | 
* |3 -> erro de sobrenome     |
* |4 -> erro de idade         |
* |0 -> SEM ERRO TUDO PASSOU  |
* @param: type all string: nome, sobrenome, cpf, idade
* 
* @return: altera os valores do vetor erro .
*/ 
void validate_user(const string &cpf_formatted, const string &first_name,
    const string &last_name, const string &age_user, int *error);
/*-----------------------validate expense-----------------------*/
void validate_expense(const string &type_expense,const string &name_expense,
    const string &amount, const string &date_time, int *error);
/*-----------------------validate income-----------------------*/
void validate_source_income(const string &name_income, const string &type_income,
    const string &amount_monthly,int *error);
/*-----------------------funcutions to test-----------------------*/
bool validate_date_time(const string &date_time);
bool validate_type(const string &type);
bool validate_money_qtd(const string &money);
bool validate_string_type_name(const string &name);
bool validate_cpf(const string &cpf_formatado);
bool validate_birthdate(const string &age_user);
#endif