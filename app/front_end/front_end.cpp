//Bibliotecas
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

//Modulos
#include  "back_end/back_end.hpp"
#include "dados/structs_dados.hpp"
#include "constantes.hpp"

using namespace std;

//Codigo☺
void menu(){

    // Variaveis
    char option;
    int response;
    string menssager;
    string fist_name,last_name,age,salary,cpf;

    scanf("%c",&option);
    getchar();
    switch (option){

    case 'c':
    case 'C':

        cout << "\nBem Vindo!\n";

        //Aqui sera o lugar onde o Usuario ira digitar as suas informações

        cout <<"Digite o CPF: ";
        getline(cin,cpf);

        cout <<"Digite o Primeiro Nome: ";
        getline(cin,fist_name);

        cout <<"Digite o Sobrenome: ";
        getline(cin,last_name);

        /*TODO: mudança de planos, o usuario n pode ter menos que 14 anos e vai inserir a data
        nascimento no formato dd/mm/aaaa(back-end espera receber dessa forma blzz ??)
        vou retornar dois possiveis erros 
        data_nacimento invalida ou usuario com idadde menor que a permitida blzz??
        */
        cout <<"Digite a Idade: ";
        getline(cin,age);

        cout <<"Digite o Salario: ";
        getline(cin,salary);

        //codigo que envia as informações do usuario para a funcao validate_user
        response = validate_user(cpf,fist_name,last_name,age,salary);


        switch (response)
        {
        case 1:
            menssager = "CPF invalido ou fora do padrao xxx.xxx.xxx-xx";
        break;

        case 2:
            menssager = "Nome tem numeros ou caracteres especiais";
        break;

        case 3:
            menssager = "Idade tem letras o caracteres especiais ";
        break;

        case 4:
            menssager = "Salario tem letras, caracteres especiais ou nao esta no formato 0000,00";
        break;
        }

        if(response>0){
            cout << "\n!ERRO: " <<menssager << " !\n";
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