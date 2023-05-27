#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IndiceInvertido.h"



void FLVazia(Lista_Indice *lista){
    lista->primeiro = (Apontador) malloc(sizeof(IndiceInvertido));
    lista->ultimo = lista->primeiro;
    lista->primeiro->proximo = NULL; 
}

void InsereLista(int idDoc, Lista_Indice *lista){
    lista->ultimo->proximo = (Apontador) malloc(sizeof(IndiceInvertido));
    lista->ultimo = lista->ultimo->proximo;
    lista->ultimo->quantidade = 1;
    lista->ultimo->idDocumento = idDoc;
    lista->ultimo->proximo = NULL;
}

void Imprime(Lista_Indice lista){
    Apontador aux;
    aux = lista.primeiro->proximo;
    while(aux != NULL){
        printf("Documento: %d\n", aux->idDocumento);
        aux = aux->proximo;
    }
}

void IncrementaQuantidade(Lista_Indice *lista, int idDoc){
    Apontador aux;
    aux = lista.primeiro->proximo;
    while(aux != NULL){
        if(aux->idDoc == idDoc)
            aux->quant = aux->quant + 1;
        aux = aux->proximo;
    }

}
