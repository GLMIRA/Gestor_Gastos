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
void entrada(string response[],string mensager[],int i){
    

    for(i=0;i<=4;i++){
        cout << mensager[i]; 
        getline(cin,response[i]); 
    }
}
void valores_mensager(string response[],string mensager[],int i){
    mensager[]={
                "\n\t ┌────────────────────────────────┐\n\t │    Digite o Primeiro Nome:     │\n\t └────────────────────────────────┘",
                "\n\t ┌────────────────────────────────┐\n\t │      Digite o Sobrenome:       │\n\t └────────────────────────────────┘",
                "\n\t ┌────────────────────────────────┐\n\t │      Digite a sua Idade:       │\n\t │    No formato dia/mes/ano      │\n\t └────────────────────────────────┘",
                "\n\t ┌────────────────────────────────┐\n\t │         Digite o CPF:          │\n\t │   No formato xxx.xxx.xxx-xx    │\n\t └────────────────────────────────┘",
    };
}

void menu(){
    char choice;
    
    cout << "\n\t ┌────────────────────────────────┐";
    cout << "\n\t │ Bem Vindo ao Gestor de Gastos! │";
    cout << "\n\t └────────────────────────────────┘";
    cout << "\n\t ┌────────────────────────────────┐"; 
    cout << "\n\t │Digite:                         │";
    cout << "\n\t |       c para criar   a conta   |";
    cout << "\n\t │       l para entrar na conta   │";                
    cout << "\n\t └────────────────────────────────┘"; 
    switch (choice)
    {
    case 'c':
    case 'C':
        cout << "\n\t ┌────────────────────────────────┐";
        cout << "\n\t │  Agora vamos criar um usuario! │";
        cout << "\n\t └────────────────────────────────┘";

    
    break;

    case 'l':
    case 'L':


    break;

    default:
    cout << "valor errado!";
        break;
    }









    // Variaveis

    // int i=4;
    // int response[i];

    // string fist_name,last_name,birthdate,/*salary,*/cpf;
    // string menssager;


    // for(i=4;i>=1;i--){


    //     

    //     case 5:
    //     case 2:
    //         cout << "\n\t ┌────────────────────────────────┐";
    //         cout << "\n\t │    Digite o Primeiro Nome:     │";
    //         cout << "\n\t └────────────────────────────────┘";
    //         cout << "\n\t Nome:";
    //         getline(cin,fist_name);
    //     break;

    //     case 5:
    //     case 3:
    //         cout << "\n\t ┌────────────────────────────────┐";
    //         cout << "\n\t │      Digite o Sobrenome:       │";
    //         cout << "\n\t └────────────────────────────────┘";
    //         cout << "\n\t Sobrenome:";
    //         getline(cin,last_name);
    //     break;

    //     case 5:
    //     case 4:
    //         cout << "\n\t ┌────────────────────────────────┐";
    //         cout << "\n\t │      Digite a sua Idade        │";
    //         cout << "\n\t │    no formato dia/mes/ano      │";
    //         cout << "\n\t └────────────────────────────────┘";
    //         cout << "\n\t Idade:";
    //         getline(cin,birthdate);
    //     break;

    //     default:
    //         break;
    //     }
    //     if(response[i]==1 || response[i]==5){
    //         cout << "\n\t ┌────────────────────────────────┐";
    //         cout << "\n\t │         Digite o CPF           │";
    //         cout << "\n\t │   No formato xxx.xxx.xxx-xx    │";
    //         cout << "\n\t └────────────────────────────────┘";
    //         cout << "\n\t CPF:";
    //         getline(cin, cpf);

    //     }
    //     if(response[i]==2 || response[i]==5){

    //     }

    //     response[i] = validate_user(cpf,fist_name,last_name,birthdate/*,salary*/);

    //     switch (response[i])
    //         {
    //         case 1:
    //             menssager = "Digite o CPF No formato xxx.xxx.xxx-xx";
    //         break;

    //         case 2:
    //             menssager = "Nome tem numeros ou caracteres especiais";
    //         break;

    //         case 3:
    //             menssager = "\nIdade tem letras o caracteres especiais ";
    //         break;

    //         /*case 4:
    //             menssager = "Salario tem letras, caracteres especiais ou nao esta no formato 0000,00";
    //         break;
    //         */
    //         }
    //         if(response[i]>0 && response[i]<5){
    //             cout << "\n\t ┌────────────────────────────────┐";
    //             cout << "\n\t │!ERRO:                          |";
    //             cout << "\n\t | " << menssager <<             "|";
    //             cout << "\n\t └────────────────────────────────┘";
    //         }else{
    //         cout << "\n\t ┌────────────────────────────────┐";
    //         cout << "\n\t │   Usuario Criado com Sucesso!  │";
    //         cout << "\n\t └────────────────────────────────┘";
    //         }
    // }
    
    
    // /*
    // cout << "\n\t ┌────────────────────────────────┐";
    // cout << "\n\t │      Digite o Salario:         │";
    // cout << "\n\t └────────────────────────────────┘";
    // cout << "\n\t Salario:";
    // getline(cin,salary);
    // */


    //     /*TODO: mudança de planos, o usuario n pode ter menos que 14 anos e vai inserir a data
    //     nascimento no formato dd/mm/aaaa(back-end espera receber dessa forma blzz ??)
    //     vou retornar dois possiveis erros 
    //     data_nacimento invalida ou usuario com idadde menor que a permitida blzz??
    //     */


    //     //codigo que envia as informações do usuario para a funcao validate_user          
}