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
void valuete_entry(string *variebles[],string mensager[],string mensager_erro[],int cont,bool fist_exe){
    getchar();
    if(fist_exe==true){
        for(int i = 0 ;i < cont; i ++){
            cout << mensager[i]; 
            getline(cin,*variebles[i]);

        }
    }else{
        cout << mensager_erro[cont] << "\n";
        cout << mensager[cont];
        getline(cin,*variebles[cont]);
    }
}

void menu(){
    int cont=0;
    int test_user=0;
    bool fist_exe=true;
    int error[4]={0,0,0,0};
    char choice;
    string cpf,fist_name,last_name,brithdate;
    string response[4];
    string mensager_erro[4]={
        "Erro: Digite o CPF No formato xxx.xxx.xxx-xx ",
        "Erro: Nome tem numeros ou caracteres especiais ",
        "Erro: Sobrenome tem numeros ou caracteres especiais ",
        "Erro: Idade tem letras o caracteres especiais ",
    };
    string mensager[4] = {
        "Digite o CPF, no formato xxx.xxx.xxx-xx: ",
        "Digite o Primeiro Nome: ",
        "Digite o Sobrenome: ",
        "Digite a sua Idade, no formato dia/mes/ano: ",
        };
    string *variebles[4]={
        &cpf,
        &fist_name,
        &last_name,
        &brithdate
    };
    do{
    cout << "\n\t ┌────────────────────────────────┐";
    cout << "\n\t │ Bem Vindo ao Gestor de Gastos! │";
    cout << "\n\t └────────────────────────────────┘";
    cout << "\n\t ┌────────────────────────────────┐"; 
    cout << "\n\t │Digite:                         │";
    cout << "\n\t |       c para criar a conta     |";
    cout << "\n\t │       l para entrar na conta   │";     
    cout << "\n\t │       s para sair              │";             
    cout << "\n\t └────────────────────────────────┘\n"; 
    cin >> choice;
        switch (choice)
        {
        case 'c':
        case 'C':
            cout << "\n\t ┌────────────────────────────────┐";
            cout << "\n\t │  Agora vamos criar um usuario! │";
            cout << "\n\t └────────────────────────────────┘\n";
            valuete_entry(variebles, mensager,mensager_erro,cont=4,fist_exe);

            validate_user(cpf,fist_name,last_name,brithdate,error);

            while (true)
            {
                test_user = 0;
                if(test_user==4){
                    cout << "Usuario cadastrado com sucesso!";
                    break;
                }else{
                    validate_user(cpf,fist_name,last_name,brithdate,error);
                }
                for(int j=0;j<4;j++){
                    fist_exe=false;
                    if(error[j] != 0){
                        cont = j;
                        valuete_entry(variebles,mensager,mensager_erro,cont,fist_exe);
                    }else{
                        test_user++;
                    }  
                }
                 if(test_user==4){
                    cout << "Usuario cadastrado com sucesso!\n";
                    break;
                }else{
                    validate_user(cpf,fist_name,last_name,brithdate,error);
                }
            };


        break;

        case 'l':
        case 'L':


        break;
        
        default:
        cout << "valor errado!";
            break;
        } 
    }while (choice!='s' && choice!='S');
        
}