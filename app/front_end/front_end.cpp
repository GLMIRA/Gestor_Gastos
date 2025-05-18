// Bibliotecas
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

// Módulos
#include "back_end/back_end.hpp"
#include "constantes.hpp"

using namespace std;

// Funções auxiliares
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

// Criar usuário
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
                valid_fields_count++;
            }
        }
        if (valid_fields_count == 4) {
            cout << "Usuario cadastrado com sucesso!\n";
            break;
        }
    }
}

// Criar gasto
void create_expense(string *variables[], string messages[], string error_messages[], int size){
    cout << "\n\t ┌─────────────────────────────────┐";
    cout << "\n\t │    Vamos adicionar um gasto!    │";
    cout << "\n\t └─────────────────────────────────┘\n";

    input_all_fields(variables, messages, size);
    int valid_fields_count = 0;
    int error[4] = {0, 0, 0, 0};

    while (true) {
        valid_fields_count = 0;
        validate_expense(*variables[0], *variables[1], *variables[2], *variables[3], error); 
        for (int j = 0; j < 4; j++) {
            if (error[j] != 0) {
                input_field_with_error(variables[j], messages[j], error_messages[j]);
            } else {
                valid_fields_count++;
            }
        }
        if (valid_fields_count == 4) {
            cout << "Gasto cadastrado com sucesso!\n";
            break;
        }
    }
}

// Criar receita (income)
void create_income(string *variables[], string messages[], string error_messages[], int size){
    cout << "\n\t ┌──────────────────────────────────┐";
    cout << "\n\t │   Vamos adicionar uma receita!   │";
    cout << "\n\t └──────────────────────────────────┘\n";

    input_all_fields(variables, messages, size);
    int valid_fields_count = 0;
    int error[4] = {0, 0, 0, 0};

    while (true) {
        valid_fields_count = 0;
        validate_source_income(*variables[0], *variables[1], *variables[2], error); 
        for (int j = 0; j < 4; j++) {
            if (error[j] != 0) {
                input_field_with_error(variables[j], messages[j], error_messages[j]);
            } else {
                valid_fields_count++;
            }
        }
        if (valid_fields_count == 4) {
            cout << "Receita cadastrada com sucesso!\n";
            break;
        }
    }
}

// Menu principal
void menu(){
    //global variables
    char validate_entry;
    int array_range = 4;

    // ---------------------- User ---------------------- //
    string cpf = "", first_name = "", last_name = "", birthdate = "";
    string *variables_user[4] = { &cpf, &first_name, &last_name, &birthdate };

    string error_messages[4] = {
        "Erro: Digite o CPF No formato xxx.xxx.xxx-xx ",
        "Erro: Nome tem números ou caracteres especiais ",
        "Erro: Sobrenome tem números ou caracteres especiais ",
        "Erro: Idade tem letras ou caracteres especiais ",
    };
    
    string messages_user[4] = {
        "Digite o CPF, no formato xxx.xxx.xxx-xx: ",
        "Digite o Primeiro Nome: ",
        "Digite o Sobrenome: ",
        "Digite a sua Idade, no formato dia/mes/ano: ",
    };

    // ---------------------- Expense ---------------------- //
    string name_expense = "", choice_obligatory_expense = "", value_expense = "", date_expense = "";
    string *variables_expense[4] = { &name_expense, &choice_obligatory_expense, &value_expense, &date_expense };

    string messages_expense[4] = {
        "Digite o nome deste gasto: ",
        "Esse gasto é obrigatório [S]im ou [N]ão?: ",
        "Digite o valor deste gasto: ",
        "Digite a Data deste gasto dia/mes/ano: "
    };

    string messages_error_expense[4] = {
        "Erro: Gastos têm caracteres especiais ou números: ",
        "Erro: Digite somente S ou N: ",
        "Erro: Valor tem que estar assim 0000.00 ou assim 0000: ",
        "Erro: A data tem que estar neste formato dia/mes/ano: "
    };

    // ---------------------- Income ---------------------- //
    string name_income = "", type_income = "", amount_monthly = "";
    string *variables_income[3] = { &name_income, &type_income, &amount_monthly };

    string messages_income[4] = {
        "Digite o nome desta receita: ",
        "Essa receita é fixa [S]im ou [N]ão?: ",
        "Digite o valor mensal: ",
        "Digite a data da receita dia/mes/ano: "
    };

    string messages_error_income[4] = {
        "Erro: Nome da receita inválido (não pode conter caracteres especiais ou números): ",
        "Erro: Digite apenas S ou N: ",
        "Erro: Valor deve estar no formato 0000.00 ou 0000: ",
        "Erro: A data deve estar no formato dia/mes/ano: "
    };

    char choice;
    do {
        cout << "\n\t ┌────────────────────────────────┐";
        cout << "\n\t │ Bem Vindo ao Gestor de Gastos! │";
        cout << "\n\t └────────────────────────────────┘";
        cout << "\n\t ┌────────────────────────────────┐"; 
        cout << "\n\t │Digite:                         │";
        cout << "\n\t │c para criar a conta            │";
        cout << "\n\t │l para entrar na conta          │";     
        cout << "\n\t │s para sair                     │";             
        cout << "\n\t └────────────────────────────────┘\n"; 
        cin >> choice;
        cin.ignore();

        switch (choice){
        case 'c':
        case 'C':{
            create_user(variables_user, messages_user, error_messages, array_range);
            create_income(variables_income, messages_income, messages_error_income, array_range=3);
            cout << "\n\t ┌─────────────────────────────────┐";
            cout << "\n\t │    Vamos adicionar um gasto?    │";
            cout << "\n\t └─────────────────────────────────┘\n";
            bool test = true;
            do{
                cin >> validate_entry;
                switch (validate_entry)
                {
                case 'S':
                case 's':
                    create_expense(variables_expense, messages_expense, messages_error_expense, array_range);
                    break;
                case 'N':
                case 'n':
                    //logica pra passar informções default 
                break;                
                default:
                    cout << "Digite S ou N" << "\n";
                break;
                }
                

            }while (test != true);
            
        }break;

        case 'l':
        case 'L':
            // Função de login (ainda não implementada)
            break;

        case 's':
        case 'S':
            cout << "Saindo...\n";
            break;

        default:
            cout << "Opção inválida!\n";
            break;
        }
    } while (choice != 's' && choice != 'S');
}
