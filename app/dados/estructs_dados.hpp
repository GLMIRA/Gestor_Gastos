#ifndef ESTRUTURA_DADOS_HPP
#define ESTURUTRA_DADOS_HPP

struct User{
    char name[50];
    char cpf[11];
    int age = 0;
    float salary = 0.0;
};

struct Expense{
    bool typeExpense; // se é obrigatoria ou nao (sendo TRUE obrigatoria e FALSE nao obrigatoria) 
    char nameExpense[50]; // nome exp: LUZ,AGUA,NET
    float amount = 0.0;// valor da conta 
    
};
#endif