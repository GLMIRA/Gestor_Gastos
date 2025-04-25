//Bibliotecas
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

//Modulos
#include "dados/estructs_dados.hpp"
#include "constantes.hpp"

using namespace std;

//Codigo☺
void menu(){

    // Variaveis
    char option;
    int response;
    string fist_name,last_name,age,salary,cpf;


    switch (option)
    {
    case 'c':
    case 'C':

        cout << "\nBem Vindo!\n";

        //Aqui sera o lugar onde o Usuario ira digitar as suas informações

        cout << "Digite o CPF:\t";
        getline(cin,cpf);

        cout << "Digite o Primeiro Nome:\t";
        getline(cin,fist_name);

        cout << "Digite o Sobrenome:\t";
        getline(cin,last_name);

        cout << "Digite a Idade:\t";
        getline(cin,age);

        cout << "Digite o Salario:\t";
        getline(cin,salary);

        //codigo que envia as informações do usuario para a funcao validate_user
        response=validate_user(cpf,fist_name,last_name,age,salary);



        switch (response)
        {
            //TODO: Edita isso response nao guarda nada 
        case 1:
            response = 'CPF invalido ou fora do padrao xxx.xxx.xxx-xx';
        break;

        case 2:
            response = 'Nome tem numeros ou caracteres especiais';
        break;

        case 3:
            response = 'Idade tem letras o caracteres especiais ';
        break;

        case 4:
            response = 'Salario tem letras, caracteres especiais ou nao esta no formato 0000,00';
        break;
        }

        if(response>0){
            cout << "\n!ERRO: " << response << " !\n";
        }else{
            cout << "\n Usuario Criado com Sucesso!\n";
        }
        
    break;

    case 'l':
    case 'L':

    break;

        

    default:
    printf("\n|**************|\n| Wrong value! |\n**************\n");   
    break;
    }

}