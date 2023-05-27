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

void lerPalavras(Aptd_Pat *A) {

    int N, i, idDoc;
    char nomeArq[50];
    char palavra[50];
    
    FILE *entrada = fopen("entrada.txt", "r");
    FILE *arquivo;

    if(entrada == NULL){
		printf("Não foi possível abrir o arquivo de entrada\n");
        return;
    }

    fscanf(entrada, "%d\n", &N);

    // gera um vetor de idDoc para o indice invertido
    int vetorIdDoc[N]; 
    for(i = 0;i<N;i++){
        vetorIdDoc[i] += 1;
    }

    for (i = 0; i< N; i++){   
        fscanf(entrada, "%s", nomeArq); 
        arquivo = fopen(nomeArq, "r");
        idDoc = vetorIdDoc[i];

        if(arquivo == NULL){
            printf("Não foi possível abrir o arquivo\n");
            return;
        }
        while (!feof(arquivo)){
            fscanf(arquivo, "%s", palavra); 
            tratamentoDePalavras(palavra);

            InserePatricia(palavra, A, idDoc);
        }
        fclose(arquivo);
    }

    fclose(entrada);
    
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
