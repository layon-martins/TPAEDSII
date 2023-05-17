#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
        strcpy(palavra, tolower(&palavra));     
        printf("%s\n", palavra);
    }


    

    fclose(arquivo);

    return 0;

}

// transforma para minúsculo e remove caracteres especiais.
void TransformarParaMinusculo(char *palavra){
  int i;
  int ascii;
  for (i = 0; i < strlen(palavra); i++){
    palavra[i] = tolower(palavra[i]);

    ascii = (int)palavra[i];

    if (ascii < 97 || ascii > 122)
      palavra[i] = '\0';
  }
}