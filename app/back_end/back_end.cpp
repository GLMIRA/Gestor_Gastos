#include <iostream>
#include <cstring>
#include <cctype>

// Modulos
#include "dados/estructs_dados.hpp"
#include "constantes.hpp"

bool validate_cpf(User user[], int* range_user) {
    const char* cpf_formatado = user[*range_user].cpf;

    // Verifica se o tamanho é 14
    if (std::strlen(cpf_formatado) != 14) return false;

    // Verifica formato: XXX.XXX.XXX-XX
    for (int i = 0; i < 14; i++) {
        if ((i == 3 || i == 7) && cpf_formatado[i] != '.') return false;
        else if (i == 11 && cpf_formatado[i] != '-') return false;
        else if (i != 3 && i != 7 && i != 11 && !std::isdigit(cpf_formatado[i])) return false;
    }

    // Verifica CPFs inválidos conhecidos
    const char* invalidos[] = {
        "000.000.000-00", "111.111.111-11", "222.222.222-22",
        "333.333.333-33", "444.444.444-44", "555.555.555-55",
        "666.666.666-66", "777.777.777-77", "888.888.888-88",
        "999.999.999-99"
    };
    for (const char* invalido : invalidos) {
        if (std::strcmp(cpf_formatado, invalido) == 0) return false;
    }

    // Extrai apenas os números
    int cpf[11], j = 0;
    for (int i = 0; i < 14; i++) {
        if (std::isdigit(cpf_formatado[i])) {
            cpf[j++] = cpf_formatado[i] - '0';
        }
    }

    // Verifica se extraiu 11 dígitos
    if (j != 11) return false;

    // Validação do 1º dígito
    int soma = 0;
    for (int i = 0; i < 9; i++) soma += cpf[i] * (10 - i);
    int dig1 = (soma % 11 < 2) ? 0 : 11 - (soma % 11);
    if (dig1 != cpf[9]) return false;

    // Validação do 2º dígito
    soma = 0;
    for (int i = 0; i < 10; i++) soma += cpf[i] * (11 - i);
    int dig2 = (soma % 11 < 2) ? 0 : 11 - (soma % 11);
    if (dig2 != cpf[10]) return false;

    return true; // CPF válido
}


