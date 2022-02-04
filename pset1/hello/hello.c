#include <stdio.h>
#include <cs50.h>

int main(void){
    string nome = get_string("Qual é o seu nome? \n");
    printf("Olá %s!\n", nome);
}