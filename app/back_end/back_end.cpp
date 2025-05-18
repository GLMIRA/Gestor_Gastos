#include <cstring>
#include <cctype>
#include <chrono>
#include <ctime>
#include <exception>
#include <iostream>
#include <string>
#include <sstream>
#include<vector>

#include <unicode/unistr.h>
#include <unicode/ustream.h>
#include <unicode/uchar.h>

// Modulos  
#include "constantes.hpp"


using namespace std;
using namespace icu;


/*------------------------------Validate Generic------------------------------*/

/// @brief valida se o usuario digitou um valor monetário 0000,00.
/// @param money: salário do usuário
/// @return: true se válido, false se inválido
bool validate_money_qtd(const string &money) {
    try {
        float salary = stof(money);
        if (salary < 0){
            return false;
        }
        return true;
    } catch(const exception& e) {
        return false;
    }
}

/// @brief valida se a string tem o formato de data esperado DD/MM/AAAA
/// @param date: string com a data
/// @return: true se estiver no formato esperado, false caso contrário
bool validate_string_in_format_date(const string &date) {
    if (date.length() != 10) return false;
    for (int i = 0; i < 10; i++) {
        if ((i == 2 || i == 5) && date[i] != '/') return false;
        else if (i != 2 && i != 5 && !isdigit(date[i])) return false;
    }
    return true;
}


/**
 * @brief converte uma string data em time_tt(dd/mm/aaaa -> sec)
 * 
 * @param date: string dd/mm/aaaa
 * 
 * @return retorna a data em segundos
 */
time_t convert_string_date_to_time_t(const string &date_time) {
    int day, month, year, hour = 0, minut = 0, second = 0;
    char bar1, bar2;

    stringstream ss(date_time);
    ss >> day >> bar1 >> month >> bar2 >> year;

    if (ss.fail() || bar1 != '/' || bar2 != '/' || 
        day < 1 || day > 31 || month < 1 || month > 12 || year < 1900) {
        return -1;
    }

    if (date_time.find(":") != string::npos) {
        char colon1 = 0, colon2 = 0, sep = 0;
        ss >> sep >> hour >> colon1 >> minut >> colon2 >> second;

        if (ss.fail() || sep != ':' || colon1 != ':' || colon2 != ':' ||
            hour < 0 || hour > 23 || minut < 0 || minut > 59 || second < 0 || second > 59) {
            return -1;
        }        
    }

    tm tm_date = {};
    tm_date.tm_mday = day;
    tm_date.tm_mon = month - 1;
    tm_date.tm_year = year - 1900;
    tm_date.tm_hour = hour;
    tm_date.tm_min = minut;
    tm_date.tm_sec = second;

    return mktime(&tm_date); // valor em segundos desde 1/1/1970 (epoch Unix)
}

/**
 * @brief Valida se uma string está no formato de data e hora correto e dentro dos intervalos válidos.
 * 
 * Esta função verifica se a string fornecida segue o formato esperado de data e hora:
 * - DD/MM/AAAA:HH:MM:SS
 * 
 * Além de verificar a estrutura do formato, a função também garante que os valores extraídos da string (dia, mês, ano, hora, minuto e segundo) estão dentro dos intervalos válidos:
 * - Dia: 1 a 31
 * - Mês: 1 a 12
 * - Hora: 0 a 23
 * - Minuto: 0 a 59
 * - Segundo: 0 a 59
 * 
 * @param date_time String representando a data e hora no formato "DD/MM/AAAA:HH:MM:SS".
 * 
 * @return true se a string estiver no formato válido e os valores estiverem dentro dos intervalos permitidos.
 * @return false caso contrário.
 */
bool validate_string_in_format_date_time(const std::string &date_time) {
    if (date_time.length() != 19) return false;

    // Verificação do formato: DD/MM/AAAA:HH:MM:SS
    if (date_time[2] != '/' || date_time[5] != '/' ||
        date_time[10] != ':' || date_time[13] != ':' || date_time[16] != ':') {
        return false;
    }

    // Verificação de dígitos
    for (int i = 0; i < 19; ++i) {
        if (i == 2 || i == 5 || i == 10 || i == 13 || i == 16) continue; // separadores
        if (!isdigit(date_time[i])) return false;
    }

    // Extração dos valores numéricos
    int dia = stoi(date_time.substr(0, 2));
    int mes = stoi(date_time.substr(3, 2));
    int ano = stoi(date_time.substr(6, 4));
    int hora = stoi(date_time.substr(11, 2));
    int minuto = stoi(date_time.substr(14, 2));
    int segundo = stoi(date_time.substr(17, 2));

    // Verificação de intervalos válidos
    if (dia < 1 || dia > 31) return false;
    if (mes < 1 || mes > 12) return false;
    if (hora < 0 || hora > 23) return false;
    if (minuto < 0 || minuto > 59) return false;
    if (segundo < 0 || segundo > 59) return false;

    return true;
}

/// @brief valida se a string está correta para representar um nome
/// @param string_name: primeiro nome
/// @return: true se for válido, false caso contrário
bool validate_string_type_name(const string &string_name){
    

    UnicodeString uName(string_name.c_str(), "UTF-8");
    for (int i = 0; i < uName.length(); ++i) {
        UChar32 c = uName.char32At(i);
        if (!u_isalpha(c) && c != ' ') {
            return false; 
        }
    }

    return !string_name.empty() && string_name.find_first_not_of(' ') != string::npos;
}

/// @brief valida o tipo de despesa informado ("S" ou "N")
/// @param type: string com o tipo
/// @return: true se válido, false se inválid
bool validate_type(const string &type){
    
    string yes[2]{"s","S"};
    string no[2] ={ "n","N"};

    for(int i = 0; i<2; i++){
        if(type == yes[i]){
            return true;
        }
        else if(type == no[i]){
        return true;
        }
    }
    return false;
}

/*------------------------------Validate User------------------------------*/

/**
 * @brief recebe uma variavel com um cpf e verifica se é valido
 * 
 * @param cpf_formatado -> string
 * recebe uma string com verifica se ela tem 14 caracteres
 * verifica se não é um cpf invalido conhecido(por comparacao) 
 * transforma ela em um vetor de inteiros de 11 caracters 
 * valida os digitos verificadores 
 * 
 * @return verdadeiro se for valido falso se for invalido 
 */
bool validate_cpf(const string &cpf_formatado) {

    if (cpf_formatado.length() != 14) return false;

    // Verifica formato: XXX.XXX.XXX-XX
    for (int i = 0; i < 14; i++) {
        if ((i == 3 || i == 7) && cpf_formatado[i] != '.') return false;
        else if (i == 11 && cpf_formatado[i] != '-') return false;
        else if (i != 3 && i != 7 && i != 11 && !isdigit(cpf_formatado[i])) return false;
    }

    // Verifica CPFs inválidos conhecidos
    const char* invalidos[] = {
        "000.000.000-00", "111.111.111-11", "222.222.222-22",
        "333.333.333-33", "444.444.444-44", "555.555.555-55",
        "666.666.666-66", "777.777.777-77", "888.888.888-88",
        "999.999.999-99","123.456.789-09"
    };
    for (const char* invalido : invalidos) {
        if (strcmp(cpf_formatado.c_str(), invalido) == 0) return false;
    }

    // Extrai apenas os números
    int cpf[11], j = 0;
    for (int i = 0; i < 14; i++) {
        if (isdigit(cpf_formatado[i])) {
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

///@brief valida a data de nacimento de um usuario .
///@param birthdate idade do usuario.
///@return retorna verdadeiro for valido, falso se for invalido
bool validate_birthdate(const string &birthdate){
    try
    {
        time_t now = time(nullptr);
        tm* date = localtime(&now);
        time_t date_today = mktime(date);
        
        if(!validate_string_in_format_date(birthdate)) return false;

        time_t date_user = convert_string_date_to_time_t(birthdate);
        if (date_user == -1) return false;


        if((date_today - date_user) < MINIMUM_AGE_SECONDS) return false;
        if(date_user >= date_today) return false;
        return true;

    }
    catch(const exception& e)
    {
        return false;
    }
     
}

/** 
* @brief: função pra validar um usuario com base nas outras
* funçoes de validação seguindo uma tebala de erro 
* |1 -> erro de cpf           |
* |2 -> erro de primeiro nome | 
* |3 -> erro de sobrenome     |
* |4 -> erro de idade         |
* |0 -> SEM ERRO TUDO PASSOU  |
* @param: type all string: nome, sobrenome, cpf, idade
* 
* @return: altera os valores do vetor erro .
*/ 
void validate_user(const string &cpf_formatted, const string &first_name,
const string &last_name, const string &birthdate, int ((&error)[4])){

    // Validação e atribuição dos códigos de erro
    error[0] = validate_cpf(cpf_formatted) ? 0 : 1;
    error[1] = validate_string_type_name(first_name) ? 0 : 2;
    error[2] = validate_string_type_name(last_name) ? 0 : 3;
    error[3] = validate_birthdate(birthdate) ? 0 : 4;
}
/*------------------------------Validate Expense------------------------------*/

/**
* @brief Valida se uma string de data está no formato correto e dentro do intervalo permitido.
* 
* Esta função verifica se a string fornecida representa uma data válida
* e se essa data está dentro de um intervalo de uma semana (7 dias) em relação à data atual.
* O formato aceito deve ser validado previamente pelas funções auxiliares
* (ex: validate_string_in_format_date ou validate_string_in_format_date_time).
* 
* @param date_time Uma string representando a data (com ou sem hora).
* 
* @return true se a data for válida e estiver entre 7 dias no passado e 7 dias no futuro.
* @return false se a data for inválida ou estiver fora do intervalo permitido.
*/
bool validate_date_time(const string &date_time){
    time_t date_today = time(nullptr); 

    if(!validate_string_in_format_date_time(date_time))return false;

    time_t limit_past = date_today - ONE_WEEK;
    time_t limit_future  = date_today + ONE_WEEK;

    time_t expense_day = convert_string_date_to_time_t(date_time);

    if(expense_day >=  limit_past && expense_day <= limit_future){
        return true;
    }
    return false;

}

/** 
* @brief: função pra validar um gasto com base nas outras
* funçoes de validação seguindo uma tebala de erro 
* |1 -> erro de nome          |
* |2 -> erro do tipo          | 
* |3 -> valor errado          |
* |4 -> erro de data          |
* |0 -> SEM ERRO TUDO PASSOU  |
* @param: type all string: nome, tipo, amont, data
* @return: altera os valores do vetor erro .
*/ 
void validate_expense(const string &name_expense,const string &type_expense,
    const string &amount, const string &date_time, int((&error)[4])){

    // Validação e atribuição dos códigos de erro
    error[0] = validate_string_type_name(name_expense)? 0 : 1;
    error[1] = validate_type(type_expense) ? 0 : 2;
    error[2] = validate_money_qtd(amount) ? 0 : 3;
    error[3] = validate_date_time(date_time) ? 0 : 4;
}

/*------------------------------Source Income------------------------------*/

/** 
* @brief: função pra validar uma renda com base nas outras
* funçoes de validação seguindo uma tebala de erro 
* |1 -> erro de nome          |
* |2 -> erro do tipo          | 
* |3 -> valor errado          |   
* |0 -> SEM ERRO TUDO PASSOU  |
* @param: type all string: nome, tipo, dinheiro
* 
* @return: altera os valores do vetor erro .
*/   
void validate_source_income(const string name_income, const string type_income,
    const string amount_monthly, int((&error)[4])){
 
    error[0] = validate_string_type_name(name_income)? 0 : 1;
    error[1] = validate_type(type_income) ? 0 : 2;
    error[2] = validate_money_qtd(amount_monthly) ? 0 : 3;
    }
/*------------------------------------------------------------------------------*/
/*--------------------- functions to change type variables ---------------------*/
/*------------------------------------------------------------------------------*/

