// Bibliotecas
#include <iostream>
#include <cstring>
#include <cctype>
#include <ctime>
#include <string>
#include <iostream>


// Módulos
#include "back_end/back_end.hpp"
#include "constantes.hpp"

using namespace std;


void input_and_validate_fields(
    string* campos,
    const string mensagens[],
    const string mensagens_erro[],
    int quantidade,
    void (*validador)(const string&, const string&, const string&, const string&, int*) = nullptr,
    void (*validador3)(const string&, const string&, const string&, int*) = nullptr
) {
    int* erros = new int[quantidade];

    // Entrada inicial
    for (int i = 0; i < quantidade; ++i) {
        cout << mensagens[i];
        getline(cin, campos[i]);
    }

    while (true) {
        // validação específica
        if (quantidade == 4 && validador) {
            validador(campos[0], campos[1], campos[2], campos[3], erros);
        } else if (quantidade == 3 && validador3) {
            validador3(campos[0], campos[1], campos[2], erros);
        }

        int validos = 0;
        for (int i = 0; i < quantidade; ++i) {
            if (erros[i] != 0) {
                cout << mensagens_erro[i] << "\n" << mensagens[i];
                getline(cin, campos[i]);
            } else {
                validos++;
            }
        }
        if (validos == quantidade) break;
    }

    delete[] erros;
}
string* criar_usuario_campos() {
    string* campos = new string[4];

    string mensagens[4] = {
        "Digite o CPF (xxx.xxx.xxx-xx): ",
        "Digite o primeiro nome: ",
        "Digite o sobrenome: ",
        "Digite sua data de nascimento (dd/mm/aaaa): "
    };

    string mensagens_erro[4] = {
        "Erro: CPF inválido.",
        "Erro: Nome inválido.",
        "Erro: Sobrenome inválido.",
        "Erro: Data de nascimento inválida."
    };

    input_and_validate_fields(campos, mensagens, mensagens_erro, 4, validate_user);
    return campos;
}
string* criar_renda_campos() {
    string* campos = new string[3];

    string mensagens[3] = {
        "Digite o nome da renda: ",
        "É fixa? [S/N]: ",
        "Valor mensal: "
    };

    string mensagens_erro[3] = {
        "Erro: Nome inválido.",
        "Erro: Tipo inválido.",
        "Erro: Valor inválido."
    };

    input_and_validate_fields(campos, mensagens, mensagens_erro, 3, nullptr, validate_source_income);
    return campos;
}
string* criar_gasto_campos() {
    string* campos = new string[4];

    string mensagens[4] = {
        "Nome do gasto: ",
        "É obrigatório? [S/N]: ",
        "Valor: ",
        "Data (dd/mm/aaaa:hh:mm:ss): "
    };

    string mensagens_erro[4] = {
        "Erro: Nome inválido.",
        "Erro: Tipo inválido.",
        "Erro: Valor inválido.",
        "Erro: Data fora do intervalo permitido."
    };

    input_and_validate_fields(campos, mensagens, mensagens_erro, 4, validate_expense);
    return campos;
}

// Menu principal
void menu() {
    char opcao;

    do {
        cout << "\n=== MENU ===\n";
        cout << "c - Criar Conta\n";
        cout << "l - Login (em breve)\n";
        cout << "s - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;
        cin.ignore();

        if (opcao == 'c') {
            // Coletar dados do usuário
            string* dados_usuario = criar_usuario_campos();

            // Coletar renda
            string* dados_renda = criar_renda_campos();

            // Perguntar se quer adicionar gasto
            char deseja_gasto;
            cout << "Deseja adicionar um gasto? [S/N]: ";
            cin >> deseja_gasto;
            cin.ignore();

            string* dados_gasto = nullptr;
            if (deseja_gasto == 'S' || deseja_gasto == 's') {
                dados_gasto = criar_gasto_campos();
            }

            cout << "\nCadastro concluído! (armazenamento virá depois)\n";

            // Liberação da memória
            delete[] dados_usuario;
            delete[] dados_renda;
            if (dados_gasto) delete[] dados_gasto;

        }

    } while (opcao != 's');
}
