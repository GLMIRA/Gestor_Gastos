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

void menu(){

    // Variaveis
    int i=4;
    int response[i];
    string fist_name,last_name,birthdate,/*salary,*/cpf;
    
    cout << "\n\t ┌────────────────────────────────┐";
    cout << "\n\t │ Bem Vindo ao Gestor de Gastos! │";
    cout << "\n\t └────────────────────────────────┘";
    cout << "\n\t ┌────────────────────────────────┐";
    cout << "\n\t │  Agora vamos criar um usuario! │";
    cout << "\n\t └────────────────────────────────┘";
    cout << "\n\t ┌────────────────────────────────┐";
    cout << "\n\t │         Digite o CPF           │";
    cout << "\n\t │   No formato xxx.xxx.xxx-xx    │";
    cout << "\n\t └────────────────────────────────┘";
    cout << "\n\t CPF:";
    getline(cin, cpf);    
    cout << "\n\t ┌────────────────────────────────┐";
    cout << "\n\t │    Digite o Primeiro Nome:     │";
    cout << "\n\t └────────────────────────────────┘";
    cout << "\n\t Nome:";
    getline(cin,fist_name);
    cout << "\n\t ┌────────────────────────────────┐";
    cout << "\n\t │      Digite o Sobrenome:       │";
    cout << "\n\t └────────────────────────────────┘";
    cout << "\n\t Sobrenome:";
    getline(cin,last_name);
    cout << "\n\t ┌────────────────────────────────┐";
    cout << "\n\t │      Digite a sua Idade        │";
    cout << "\n\t │    no formato dia/mes/ano      │";
    cout << "\n\t └────────────────────────────────┘";
    cout << "\n\t Idade:";
    getline(cin,birthdate);
    /*
    cout << "\n\t ┌────────────────────────────────┐";
    cout << "\n\t │      Digite o Salario:         │";
    cout << "\n\t └────────────────────────────────┘";
    cout << "\n\t Salario:";
    getline(cin,salary);
    */


        /*TODO: mudança de planos, o usuario n pode ter menos que 14 anos e vai inserir a data
        nascimento no formato dd/mm/aaaa(back-end espera receber dessa forma blzz ??)
        vou retornar dois possiveis erros 
        data_nacimento invalida ou usuario com idadde menor que a permitida blzz??
        */


        //codigo que envia as informações do usuario para a funcao validate_user
        response[i] = validate_user(cpf,fist_name,last_name,birthdate/*,salary*/);

        //switch que apresenta a variavel response que recebe um valor em int que vai de 1 a 4, onde cada valor apresenta um erro diferente.

        /*Logica para receber o codigo: recap: eu vou mandar os valores que o usuario digitou e então envio para a funcao que valida esses dados,
        apos isso vou receber um vetor de cinco espaço que cada espaço ira ter um numero de 1 a 4, então o que vou terque fazer:
        [1> criar um for que ira diminuindo as casas do vetor e que vai entrando nas condições do switch!]*/

        for(i=4;i>=1;i--){


            switch (response[i])
            {
            case 1:
                cout << "\n\t ┌────────────────────────────────┐";
                cout << "\n\t │!ERRO: CPF invalido              ";
                cout << "\n\t |ou fora do padrao xxx.xxx.xxx-xx│";
                cout << "\n\t └────────────────────────────────┘";
                cout << "\n\t ┌────────────────────────────────┐";
                cout << "\n\t │         Digite o CPF           │";
                cout << "\n\t │   No formato xxx.xxx.xxx-xx    │";
                cout << "\n\t └────────────────────────────────┘";
                cout << "\n\t CPF:";
                getline(cin, cpf);   
            break;

            case 2:
                menssager = "Nome tem numeros ou caracteres especiais";
            break;

            case 3:
                menssager = "\nIdade tem letras o caracteres especiais ";
            break;

            /*case 4:
                menssager = "Salario tem letras, caracteres especiais ou nao esta no formato 0000,00";
            break;
            */
            }
        }

        if(response>0){

        }else{
            cout << "\n\t ┌────────────────────────────────┐";
            cout << "\n\t │   Usuario Criado com Sucesso!  │";
            cout << "\n\t └────────────────────────────────┘";
        }
        
}