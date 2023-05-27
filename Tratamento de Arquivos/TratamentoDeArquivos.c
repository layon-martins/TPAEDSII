/* Trabalho Prático 1 - Disciplina AEDS 2 - UFV CAF
 * Integrantes:
 * Ana Carolina Fernandes - 5094
 * Bárbara Pagnocca - 5061
 * Jéssica Cristina Carvalho - 4686
 * Layon Fonseca Martins - 4220
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // para usar a função tolower

void tratamentoDePalavras(char *palavra);

int main(){
    FILE *entrada = fopen("entrada.txt", "r");
    FILE *arquivo;
    int N;
    char nomeArq[50];
    char palavra[50];
    /* fazer vetor das linhas do entrada.txt para retornar iddoc em função */

    if(entrada == NULL){
		  printf("Não foi possível abrir o arquivo\n");
		  return 0;
	  }
    fscanf(entrada, "%d\n", &N);

    for (int i = 0; i< N; i++){   
        fscanf(entrada, "%s", nomeArq); 
        arquivo = fopen(nomeArq, "r");
        if(arquivo == NULL){
		      printf("Não foi possível abrir o arquivo\n");
		      return 0;
	      }
        while (!feof(arquivo)){
          fscanf(arquivo, "%s", palavra); 
          tratamentoDePalavras(palavra);
          printf("%s\n", palavra);
        }
        fclose(arquivo);
    }
    fclose(entrada);

    return 0;

}

void tratamentoDePalavras(char *palavra){
  int i;  
  int ascii;  
  for (i = 0; i < strlen(palavra); i++){
    // tolower funciona em caractere
    palavra[i] = tolower(palavra[i]);

    //transforma a palavra para um valor na tabela ascii
    ascii = (int)palavra[i];
    if (ascii < 97 || ascii > 122){
      //caso o caracter não esteja entre a e z minúsculos, ele coloca como fim de string
      palavra[i] = '\0';
    }
  }
}
