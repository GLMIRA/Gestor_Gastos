#include <cstring>
#include <cctype>
#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <exception>

// Modulos  
#include "constantes.hpp"

using namespace std;

bool validate_cpf(const string &cpf_formatado) {
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
    // Verifica se o tamanho é 14
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


bool validate_name(const string &name_user){

    /** 
     * @brief valida o primeiro Nome 
     * 
     * @param name_usaer Primeiro nome.
     * 
     * @return retorna verdadeiro for validos falso se 
     * for invalido.
     */
    

    for(char c_name : name_user){
        if(!isalpha(c_name) && c_name != ' '){
            return false;
        }
    }
    return true;

}
bool validate_last_name(const string &last_name){

    /** 
     * @brief valida o Ultimo nome  
     * 
     * @param name_usaer Ultimo nome.
     * 
     * @return retorna verdadeiro for valido falso se 
     * for invalido.
     */
    
    for(char c_lastName : last_name){
        if(!isalpha(c_lastName) && c_lastName != ' '){
            return false;
        }
    }

    return true;
}

time_t convert_string_date_to_time_t(const string &date) {
    /** 
    * @brief converte uma string data em time_tt(dd/mm/aaaa -> sec)
    * 
    * @param date:string dd/mm/aaaa
    * 
    * @return retorna a data em segundos
    * 
    */
    int day, month, year;
    char bar1, bar2;

    stringstream ss(date);
    ss >> day >> bar1 >> month >> bar2 >> year;

    if (ss.fail() || bar1 != '/' || bar2 != '/' || 
        day < 1 || day > 31 || month < 1 || month > 12 || year < 1900) {
        return - 1;
    }

    tm tm_date = {};
    tm_date.tm_mday = day;
    tm_date.tm_mon = month - 1;     
    tm_date.tm_year = year - 1900;  

    time_t result_in_int = mktime(&tm_date);

    return result_in_int; // valor em segundos desde 1/1/1970 (epoch Unix)
}

bool validate_string_in_format_date(const string &date){
    /**
     * @brief: valida se a string tem o formato de data esperado DD/MM/AAAA.
     * 
     * @param date: string com a data.
     * 
     * @return: verdadeiro se estiver no formato esperado falso se nao estiver.
     */

    if (date.length() != 10) return false;
    for (int i = 0; i < 10; i++) {
        if ((i == 2 || i == 5) && date[i] != '/') return false;
        else if (i != 2 && i != 5 && !isdigit(date[i])) return false;
    }
    return true;
}

bool validate_birthdate(const string &birthdate){

    /** 
     * @brief valida a data de nacimento de um usuario .
     * 
     * @param birthdate idade do usuario.
     * 
     * @return retorna verdadeiro for valido, falso se 
     * for invalido.
     */
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

bool validate_salary(const string &salary_user){
    /** 
     * @brief valida se o usuario digitou o salario corretamente 0000,00.
     * 
     * @param salary salario do usaurio -> string
     * @var cont_virgula verifica se tem mais de uma virgula -> int
     * 
     * @return retorna verdadeiro for valido falso se 
     * for invalido.
     */
    
    try
    {
        float salary = stof(salary_user);
        if (salary < 0){
            return false;
        }
        return true;
    }
    catch(const exception& e)
    {
        return false;
    }
    

}
int validate_user(const string &cpf_formatted, const string &first_name,
const string &last_name, const string &birthdate, const string &salary){

    /*
    */ 

    int error;

    if(!validate_cpf(cpf_formatted)) return error = 1; 
    if(!validate_name(first_name))return error = 2;
    if(!validate_last_name(last_name)) return error = 2;
    if(!validate_birthdate(birthdate)) return error = 3;
    if(!validate_salary(salary))return error = 4;
    else return error = 0;
    
}

