#ifndef ESTRUTURA_DADOS_HPP
#define ESTURUTRA_DADOS_HPP


#include <string>

#include "constantes.hpp"

using namespace std;
struct Expense{
    int id;
    bool typeExpense; // se é obrigatoria ou nao (sendo TRUE obrigatoria e FALSE nao obrigatoria) 
    char nameExpense[50]; // nome exp: LUZ,AGUA,NET
    float amount = 0.0;// valor da conta 
    
};

struct User{
    int id;
    string name;
    string last_name;
    char cpf[14];
    int age = 0;
    float salary = 0.0;
    Expense expense[NUM_MAX_EXPENSE];
};

#endif