#ifndef ESTRUTURA_DADOS_HPP
#define ESTURUTRA_DADOS_HPP

struct User
{
    char name[50];
    char cpf[11];
    int age = 0;
    float salary = 0.0;
};

struct Expense {
    bool typeExpense; 
    char nameExpene[50];
    float amount = 0.0;
    
};
#endif