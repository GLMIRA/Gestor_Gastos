//Bibliotecas
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

//Modulos
#include  "back_end/back_end.hpp"
#include "constantes.hpp"
using namespace std;

//Codigo
void input_all_fields(string* variables[], const string messages[], int size) {
    for (int i = 0; i < size; i++) {
        cout << messages[i];
        getline(cin, *variables[i]);
    }
}

void input_field_with_error(string* variable, const string& message, const string& error_message) {
    cout << error_message << "\n";
    cout << message;
    getline(cin, *variable);
}

void create_user(string *variables[], string messages[], string error_messages[], int size) {
    cout << "\n\t ┌─────────────────────────────────┐";
    cout << "\n\t │  Agora vamos criar um usuario!  │";
    cout << "\n\t └─────────────────────────────────┘\n";

    input_all_fields(variables, messages, size);

    int valid_fields_count  = 0;
    int error[4] = {0, 0, 0, 0};

    while (true) {
        valid_fields_count  = 0;
        validate_user(*variables[0], *variables[1], *variables[2], *variables[3], error); 
        for (int j = 0; j < 4; j++) {
            if (error[j] != 0) {
                input_field_with_error(variables[j], messages[j], error_messages[j]);
            } else {
                valid_fields_count ++;
            }
        }
        if (valid_fields_count  == 4) {
            cout << "Usuario cadastrado com sucesso!\n";
            break;
        }
    }
}

void create_expense(string *variables[], string messages[], string error_messages[], int size){
    cout << "\n\t ┌─────────────────────────────────┐";
    cout << "\n\t │    vamos adicionar um gasto!    │";
    cout << "\n\t └─────────────────────────────────┘\n";

    input_all_fields(variables, messages, size);
        int valid_fields_count  = 0;
    int error[4] = {0, 0, 0, 0};

    while (true) {
        valid_fields_count  = 0;
        validate_expense(*variables[0], *variables[1], *variables[2], *variables[3], error); 
        for (int j = 0; j < 4; j++) {
            if (error[j] != 0) {
                input_field_with_error(variables[j], messages[j], error_messages[j]);
            } else {
                valid_fields_count ++;
            }
        }
        if (valid_fields_count  == 4) {
            cout << "Gasto cadastrado com sucesso!\n";
            break;
        }
    }
}

void menu(){
    int array_range = 4;
//----------------------User----------------------// 
    string cpf = "";
    string first_name = "";
    string last_name = "";
    string brithdate = "";
    
    string *variables_user[4] = {
        &cpf,
        &first_name,
        &last_name,
        &brithdate
    };

    string error_messages[4] = {
        "Erro: Digite o CPF No formato xxx.xxx.xxx-xx ",
        "Erro: Nome tem numeros ou caracteres especiais ",
        "Erro: Sobrenome tem numeros ou caracteres especiais ",
        "Erro: Idade tem letras ou caracteres especiais ",
    };
    
    string mensager_user[4] = {
        "Digite o CPF, no formato xxx.xxx.xxx-xx: ",
        "Digite o Primeiro Nome: ",
        "Digite o Sobrenome: ",
        "Digite a sua Idade, no formato dia/mes/ano: ",
    };

//----------------------Expense----------------------//
    string name_expense = "";
    string choice_obrigatory = "";
    string value_expense = "";
    string date_expense = "";

    string *variables_expense[4] = {
        &cpf,
        &choice_obrigatory,
        &value_expense,
        &date_expense,
    };

    string menssager_expense[4]{
        "Digite o nome deste gasto: ",
        "Esse gasto é obrigatorio [S]im ou [N]âo?: ",
        "Digite o valor deste gasto: ",
        "Digite a Data deste gastos dia/mes/ano: "
    };

    string menssager_error_expense[4]{
        "Erro: Gastos tem caracteres especias ou numero: ",
        "Erro: Digite somente S ou N: ",
        "Erro: Valor tem que estar assim 0000.00 ou assim 0000: ",
        "Erro: A data tem que estar neste formato dia/mes/ano: "
    };


    char choice;
    do {
        cout << "\n\t ┌────────────────────────────────┐";
        cout << "\n\t │ Bem Vindo ao Gestor de Gastos! │";
        cout << "\n\t └────────────────────────────────┘";
        cout << "\n\t ┌────────────────────────────────┐"; 
        cout << "\n\t │Digite:                         │";
        cout << "\n\t |c para criar a conta            |";
        cout << "\n\t │l para entrar na conta          │";     
        cout << "\n\t │s para sair                     │";             
        cout << "\n\t └────────────────────────────────┘\n"; 
        cin >> choice;
        cin.ignore();

        switch (choice){
        case 'c':
        case 'C':
            create_user(variables_user, mensager_user, error_messages, array_range);
            create_expense(variables_expense, menssager_expense, menssager_error_expense, array_range);
            break;

        case 'l':
        case 'L':
            // Função de login (ainda não implementada)
            break;

        case 's':
        case 'S':
            cout << "Saindo" << "\n";
            break;

        default:
            cout << "valor errado!" << "\n";
            break;
        }
    } while (choice != 's' && choice != 'S');
}
