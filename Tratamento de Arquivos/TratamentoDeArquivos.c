#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void tratamentoDePalavras(char *palavra);

int main(){
    FILE *arquivo = fopen("arquivo1.txt", "r");
    char palavra[100];
    char *ptr_palavra;

    if(arquivo == NULL){
		  printf("Nao foi possivel abrir o arquivo\n");
		  return 0;
	  }

    while(!feof(arquivo)){   
        fscanf(arquivo, "%s", palavra); 
        tratamentoDePalavras(palavra);
        //Quando existem dois caracteres seguidos ele guarda um espaco em branco
        printf("%s\n", palavra);
    }
    fclose(arquivo);

    return 0;

}

void tratamentoDePalavras(char *palavra){
  int i;  
  int ascii;  
  for (i = 0; i < strlen(palavra); i++){
    // tolower funciona em caracter
    palavra[i] = tolower(palavra[i]);

    //transforma a palavra para um valor na tabela ascii
    ascii = (int)palavra[i];
    if (ascii < 97 || ascii > 122){
      //caso o caracter nao esteja entre a e z minusculos, ele coloca como fim de string
      palavra[i] = '\0';
    }
  }
}