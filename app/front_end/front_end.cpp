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
void valuete_entry(string *variebles[],string mensager[],string mensager_erro[],
    int index,bool fist_exe){
    
    if(fist_exe==true){
        for(int i = 0; i < index; i++){
            cout << mensager[i]; 
            getline(cin,*variebles[i]);

        }
    }else{
        cout << mensager_erro[index] << "\n";
        cout << mensager[index];
        getline(cin,*variebles[index]);
    }
}

void menu(){
    int array_range=0;
    int test_user=0;
    bool fist_exe=true;
    int error[4]={0,0,0,0};
    char choice;
    string cpf = "";
    string first_name ="";
    string last_name="";
    string brithdate="";
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
        &first_name,
        &last_name,
        &brithdate
    };
    do{
    cout << "\n\t ┌────────────────────────────────┐";
    cout << "\n\t │ Bem Vindo ao Gestor de Gastos! │";
    cout << "\n\t └────────────────────────────────┘";
    cout << "\n\t ┌────────────────────────────────┐"; 
    cout << "\n\t │Digite:                         │";
    cout << "\n\t |c para criar a conta            |";
    cout << "\n\t │l para entrar na conta          │";     
    cout << "\n\t │s para sair                     │";             
    cout << "\n\t └────────────────────────────────┘\n"; 
    cin >> choice;
    cin.ignore();

        switch (choice){
        case 'c':
        case 'C':
            cout << "\n\t ┌────────────────────────────────┐";
            cout << "\n\t │  Agora vamos criar um usuario! │";
            cout << "\n\t └────────────────────────────────┘\n";

            array_range = 4;
            valuete_entry(variebles, mensager,mensager_erro,array_range,fist_exe);

            while (true){
                
                test_user = 0;
                validate_user(cpf,first_name,last_name,brithdate,error);

                for(int j=0;j<4;j++){
                    fist_exe=false;
                    if(error[j] != 0){
                        valuete_entry(variebles,mensager,mensager_erro,j,fist_exe);
                    }else{
                        test_user++;
                    }  
                }
                if(test_user==4){
                    cout << "Usuario cadastrado com sucesso!\n";
                    fist_exe = true;
                    break;
                }
            };
        break;

        case 'l':
        case 'L':


        break;
        case 's':
        case 'S':
            cout<< "Saindo"<<"\n";
        break;
        default:
        cout << "valor errado!";
            break;
        } 
    }while (choice!='s' && choice!='S');
        
}