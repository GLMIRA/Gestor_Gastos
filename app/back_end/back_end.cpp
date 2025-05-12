#include <cstring>
#include <cctype>
#include <chrono>
#include <ctime>
#include <exception>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <unicode/unistr.h>
#include <unicode/ustream.h>
#include <unicode/uchar.h>

// Modulos  
#include "constantes.hpp"


using namespace std;
using namespace icu;


/*------------------------------Validate Generic------------------------------*/

bool validate_money_qtd(const string &money){
    /** 
     * @brief valida se o usuario digitou o um valor monetario 0000,00.
     * 
     * @param money salario do usaurio -> string
     * @var cont_virgula verifica se tem mais de uma virgula -> int
     * 
     * @return retorna verdadeiro for valido falso se 
     * for invalido.
     */
    
    try
    {
        float salary = stof(money);
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

time_t convert_string_date_to_time_t(const string &date_time) {
    /** 
    * @brief converte uma string data em time_tt(dd/mm/aaaa -> sec)
    * 
    * @param date:string dd/mm/aaaa
    * 
    * @return retorna a data em segundos
    * 
    */
    int day, month, year, hour = 0, minut = 0, second = 0;
    char bar1, bar2;


    stringstream ss(date_time);
    ss >> day >> bar1 >> month >> bar2 >> year;

    if (ss.fail() || bar1 != '/' || bar2 != '/' || 
        day < 1 || day > 31 || month < 1 || month > 12 || year < 1900) {
        return - 1;
    }
    if(date_time.find(":")!= string::npos){
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

    time_t result_in_int = mktime(&tm_date);

    return result_in_int; // valor em segundos desde 1/1/1970 (epoch Unix)
}

bool validate_string_in_format_date_time(const string &date_time){
    /**
     * @brief: valida se a string tem o formato de data esperado DD/MM/AAAA:HH:MM:SS.
     * 
     * @param date_time: string com a data e hora.
     * 
     * @return: verdadeiro se estiver no formato esperado falso se nao estiver.
     */

    if (date_time.length() != 19) return false;
    for (int i = 0; i < 19; i++) {
        if ((i == 2 || i == 5) && date_time[i] != '/') return false;
        else if (i != 2 && i != 5 && !isdigit(date_time[i])) return false;
        else if((i == 10 || i == 13 || i == 16) && date_time[i] != ':') return false;
        else if (i != 10 && i != 13 && i!= 16 && !isdigit(date_time[i])) return false;
    }
    return true;
}
/*------------------------------Validate User------------------------------*/
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

bool validate_first_name(const string &name_user){

    /** 
     * @brief valida o primeiro Nome 
     * 
     * @param name_user Primeiro nome.
     * 
     * @return retorna verdadeiro for validos falso se 
     * for invalido.
     */
    
    // Converte a string para Unicode (UTF-8)
    UnicodeString uName(name_user.c_str(), "UTF-8");

    // Verifica se o nome não contém caracteres inválidos
    for (int i = 0; i < uName.length(); ++i) {
        UChar32 c = uName.char32At(i);
        if (!u_isalpha(c) && c != ' ') {
            return false; // Retorna falso se o caractere não for alfabético ou espaço
        }
    }

    // Se o nome estiver vazio ou for composto apenas por espaços, retorna falso
    return !name_user.empty() && name_user.find_first_not_of(' ') != string::npos;
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
    UnicodeString uName(last_name.c_str(), "UTF-8");
    for (int i = 0; i < uName.length(); ++i) {
        UChar32 c = uName.char32At(i);
        if (!u_isalpha(c) && c != ' '){
            return false; 
        }
    }

    return !last_name.empty() && last_name.find_first_not_of(' ') != string::npos;
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

void validate_user(const string &cpf_formatted, const string &first_name,
const string &last_name, const string &birthdate, const string &salary, int ((&error)[4])){

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

    // Validação e atribuição dos códigos de erro
    error[0] = validate_cpf(cpf_formatted) ? 0 : 1;
    error[1] = validate_first_name(first_name) ? 0 : 2;
    error[2] = validate_last_name(last_name) ? 0 : 3;
    error[3] = validate_birthdate(birthdate) ? 0 : 4;
}

/*------------------------------Validate Expense------------------------------*/
bool validate_name_expense(const string &name_expense){
    
    /** 
     * @brief valida o Nome do gasto 
     * 
     * @param name_expense Primeiro nome.
     * 
     * @return retorna verdadeiro for validos falso se 
     * for invalido.
     */
    
    // Converte a string para Unicode (UTF-8)
    UnicodeString uName(name_expense.c_str(), "UTF-8");

    // Verifica se o nome não contém caracteres inválidos
    for (int i = 0; i < uName.length(); ++i) {
        UChar32 c = uName.char32At(i);
        if (!u_isalpha(c) && c != ' ') {
            return false; // Retorna falso se o caractere não for alfabético ou espaço
        }
    }

    // Se o nome estiver vazio ou for composto apenas por espaços, retorna falso
    return !name_expense.empty() && name_expense.find_first_not_of(' ') != string::npos;
}

bool validate_type_expense(const string &type_expense){
    /**
    * @brief Valida o tipo de despesa informado.
    * 
    * Esta função verifica se a string fornecida representa um tipo de despesa válido.
    * O tipo de despesa deve ser representado por "S" (sim) ou "N" (não).
    * 
    * @param type_expense Uma string representando o tipo de despesa ("S" ou "N").
    * 
    * @return true se o tipo de despesa for válido ("S" ou "N").
    * @return false se o tipo de despesa não for válido.
    */
    string yes = "S";
    string no = "N";
    if(type_expense == yes){
        return true;
    }
    else if(type_expense == no){
        return true;
    }
    return false;
}

bool validate_date_time(const string &date_time){
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

int validate_expense(const string &type_expense,const string &name_expense,
    const string &amount, const string &date_time, int((error)[4])){
            /** 
    * @brief: função pra validar um gasto com base nas outras
    * funçoes de validação seguindo uma tebala de erro 
    * |1 -> erro de nome          |
    * |2 -> erro do tipo          | 
    * |3 -> valor errado          |
    * |4 -> erro de data          |
    * |0 -> SEM ERRO TUDO PASSOU  |
    * @param: type all string: nome, sobrenome, cpf, idade
    * 
    * @return: altera os valores do vetor erro .
    */ 

    // Validação e atribuição dos códigos de erro
    error[0] = validate_name_expense(name_expense)? 0 : 1;
    error[1] = validate_type_expense(type_expense) ? 0 : 2;
    error[2] = validate_money_qtd(amount) ? 0 : 3;
    error[3] = validate_date_time(date_time) ? 0 : 4;
}
        
