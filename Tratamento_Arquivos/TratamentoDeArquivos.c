
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
#include <ctype.h>

#include "TratamentoDeArquivos.h"
#include "../Patricia/Patricia.h"

void lerPalavras(Aptd_Pat *A){

  FILE *entrada = fopen("entrada.txt", "r");
  FILE *arquivo;
  int N = 0;
  int idDoc;
  char nomeArq[50];
  char palavra[50];


  if(entrada == NULL){
		printf("Não foi possível abrir o arquivo de entrada\n");
	}
  else {
    fscanf(entrada, "%d\n", &N);
    int *vetorIdDoc = (int*) malloc(N * sizeof(int)); 

    for(int i = 0;i<N;i++){
        vetorIdDoc[i] = i;
    }

    for (int i = 0; i< N; i++){   
        fscanf(entrada, "%s", nomeArq); 
        arquivo = fopen(nomeArq, "r");
        idDoc = vetorIdDoc[i] + 1;
      for (int i = 0; i< N; i++){   
          fscanf(entrada, "%s", nomeArq); 
          arquivo = fopen(nomeArq, "r");
          if(arquivo == NULL){
            printf("Nao foi possivel abrir o arquivo\n");
          }
          else {
            while (!feof(arquivo)){
              fscanf(arquivo, "%s", palavra); 
              tratamentoDePalavras(palavra);
                
              *A = InserePatricia(palavra, A, idDoc);
            }
            fclose(arquivo);
          }
      }
      fclose(entrada);
    }
  }
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
