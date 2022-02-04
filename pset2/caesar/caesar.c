#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[]){

    if(argc != 2){
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for(int i = 0; i < strlen(argv[1]); i++){
        if(!isdigit(argv[1][i])){
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int k = atoi(argv[1]) % 26;


    string textoSimples = get_string("plaintext: ");
    string textoCifrado = textoSimples;

    for(int i = 0; i < strlen(textoSimples); i++){
        if(isalpha(textoSimples[i])){
            textoCifrado[i] = textoSimples[i] + k;
            if(!isalpha(textoCifrado[i])){
                textoCifrado[i] -= 26;
            }
        }else if(!isalpha(textoSimples[i]) || isspace(textoSimples[i])){
            textoCifrado[i] = textoSimples[i];
        }
    }
    printf("ciphertext: %s\n", textoCifrado);

    return 0;
}