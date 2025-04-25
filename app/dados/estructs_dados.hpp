#ifndef ESTRUTURA_DADOS_HPP
#define ESTURUTRA_DADOS_HPP

#include <string>

using namespace std;
struct User{
    string name;
    string last_name;
    char cpf[14];
    int age = 0;
    float salary = 0.0;
};

struct Expense{
    bool typeExpense; // se é obrigatoria ou nao (sendo TRUE obrigatoria e FALSE nao obrigatoria) 
    char nameExpense[50]; // nome exp: LUZ,AGUA,NET
    float amount = 0.0;// valor da conta 
    
};
#endif