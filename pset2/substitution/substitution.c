#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[]){
    int count = 0, itera = 0;
    if(argc != 2){
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if(strlen(argv[1]) != 26){
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for(int i = 0; i < strlen(argv[1]); i++){
        if(!isalpha(argv[1][i])){
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    for(int i = 0; i < strlen(argv[1]); i++){
        for(int j = 0; j <= i; j++){
            if(argv[1][j] == argv[1][i]){
                count++;
            }
            if(count >= 2){
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
        count = 0;
    }
    count = 0;
    string textoSimples = get_string("plaintext: "), alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", textoCifrado = textoSimples, cifra = argv[1];
    while(count < strlen(textoSimples)){
        if(isupper(textoSimples[count])){
            if(alfabeto[itera] == textoSimples[count]){
                textoCifrado[count] = toupper(cifra[itera]);
                count++;
                itera = 0;
                continue;
            }
        }else if(islower(textoSimples[count])){
            if(tolower(alfabeto[itera]) == textoSimples[count]){
                textoCifrado[count] = tolower(cifra[itera]);
                count++;
                itera = 0;
                continue;
            }
        }else if(!isalpha(textoSimples[count]) || isspace(textoSimples[count])){
            textoCifrado[count] = textoSimples[count];
            itera = 0;
            count++;
            continue;
        }
        itera++;
    }

    printf("ciphertext: %s\n", textoCifrado);
    return 0;
}