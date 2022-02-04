#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(){
    float L = 0.0, S = 0.0, indice = 0.0, letra = 0.0, palavra = 0.0, sentenca = 0.0;
    string sentencas = get_string("Digite a sentença: ");

    for(int i = 0; i < strlen(sentencas); i++){
      if(isalpha(sentencas[i])){
        letra++;
      }else if(isspace(sentencas[i])){
        palavra++;
      }else if(sentencas[i] == '.' || sentencas[i] == '!' || sentencas[i] == '?'){
        sentenca++;
      }
    }

    palavra++;

    L = (letra / palavra) * 100.0;
    S = (sentenca / palavra) * 100.0;
    indice = ((0.0588 * L) - (0.296 * S)) - 15.8;

    if(indice < 1){
      printf("Before Grade 1\n");
    }else if(indice >= 16){
      printf("Grade 16+\n", round(indice));
    }else{
      printf("Grade %.0f\n", round(indice));
    }
}