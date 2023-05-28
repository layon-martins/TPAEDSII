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

void ImprimeIndice(Lista_Indice lista){
    Apontador aux;
    aux = lista.primeiro->proximo;
    while(aux != NULL){
        printf("Quantidade: %d\n", aux->quantidade);
        printf("idDoc: %d\n", aux->idDocumento);

        aux = aux->proximo;
    }
}

void IncrementaQuantidade(int idDoc, Lista_Indice lista){
    Apontador aux;
    aux = lista.primeiro->proximo;
    while(aux != NULL){
        if(aux->idDocumento == idDoc)
            aux->quantidade = aux->quantidade + 1;
        aux = aux->proximo;
    }
    /*
        Como a Função IncrementaQuantidade está sendo chamada apenas quando a 
        palavra já existe na árvore se o idDoc não for o mesmo ao percorrer para incrementar a quantidade 
        precisa-se criar a célula com o novo idDoc
    */
    //InsereLista(idDoc, &lista); 

}
