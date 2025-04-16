//Bibliotecas
#include <stdio.h>

//Modulos
#include "dados/estructs_dados.hpp"
#include "constantes.hpp"

//Codigo☺
void menu(){

    //variaveis
    char option;

    printf("");//aqui vai ficar a apresentação de tela

    printf("");//aqui ira ficar a mensagem "DIGITE UM VALOR" -> obs: a mensagem so serve para dar um noção do que fazer depois 

    scanf("%c",&option);

    switch (option)
    {
    case 'C':
        /*aqui ira ficar o codigo quando o usuario for criar uma nova conta*/
        break;
    
    case 'L':
        /*aqui ira ficar o codigo quando o usuario for logar na sua conta*/
        break;

        

    default:
    break;
}
printf("\n|**************|\n| Wrong value! |\n**************\n");☺☻↨
}