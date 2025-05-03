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
    char nameExpense[50]; // nome exp: LUZ,AGUA,NET ->
    float amount = 0.0;// valor da conta 
    char dateTime[19];// recebe em formato:AAAA-MM-DD HH:MM:SS 
    char description[100]; // texto sobre o gasto, ou breve comentário -> Atributo opcional
    // TODO : depois de adicionar essa linha eu vou ler a documentação git e gitflow
};

struct ExtraSourceIncome{ // atributo opcional em user
    int id;
    string name; // nome da renda -> EX: Investimentos 
    bool other_salary; // verificar se é salário de outro emprego, ou não -> TRUE se sim, FALSE se não
    float amount_monthly; // Quantidade de reais que essa renda traz mensalmente
};

struct User{
    int id;
    string name;
    string last_name; 
    char cpf[14];
    int age = 0;
    float salary = 0.0;
    float total_amount; // montante da renda + salario
    Expense expense[NUM_MAX_EXPENSE];
    ExtraSourceIncome source[NUM_MAX_SOURCESOFINCOME];
};

#endif