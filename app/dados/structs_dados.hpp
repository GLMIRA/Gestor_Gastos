#ifndef ESTRUTURA_DADOS_HPP
#define ESTURUTRA_DADOS_HPP

#include <string>
#include <ctime>
#include <chrono>
#include "constantes.hpp"

using namespace std;

struct Expense{
    int id;
    bool typeExpense; // se é obrigatoria ou nao (sendo TRUE obrigatoria e FALSE nao obrigatoria) 
    string nameExpense; // nome exp: LUZ,AGUA,NET 
    float amount = 0.0;// valor da gasto
    char dateTime[19];// recebe em formato:AAAA-MM-DD HH:MM:SS
    string description; // texto sobre o gasto, ou breve comentário -> Atributo opcional
};

struct SourceIncome{ // atributo opcional em user
    int id; // PK
    string name; // nome da renda -> EX: Investimentos 
    bool salary; // verificar se é salário de outro emprego, ou não -> TRUE se sim, FALSE se não
    float amount_monthly; // Quantidade de reais que essa renda traz mensalmente
    string description; // breve comentário -> Atributo opcional
};

struct User{
    int id; // PK
    string name;
    string last_name; 
    float total_amount; // montante da renda + salario mensalmente
    char cpf[14];
    char birth_date[10]; // data de nascimento -> DD-MM-AAAA
    int total_expenses = 0; // numero de gastos do usuário mensalmente -> incrementado  
    float total_amount_expenses; // deve ser a soma de todos os expense.amount
    Expense expense[NUM_MAX_EXPENSE]; // outra table
    SourceIncome source[NUM_MAX_SOURCESOFINCOME]; // idem
};
//TODO: Fazer workbench
#endif