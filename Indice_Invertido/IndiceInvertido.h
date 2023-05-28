/*
    Ana Carolina     - 5094
    Bárbara Pagnocca - 5061
    Jéssica Carvalho - 4686
    Layon Martins    - 4220
*/
#ifndef INDICE_INVERTIDO_H
#define INDICE_INVERTIDO_H

//Estrutura de Lista encadeada baseada nas implementações do livro texto da disciplina
typedef struct IndiceInvertido *Apontador;

typedef struct IndiceInvertido{
    int quantidade;
    int idDocumento;
    Apontador proximo;
}IndiceInvertido;

typedef struct{
    Apontador primeiro, ultimo;
}Lista_Indice;


void FLVazia(Lista_Indice *lista);

void InsereLista(int idDoc, Lista_Indice *lista);

void ImprimeIndice(Lista_Indice lista);

void IncrementaQuantidade(int idDoc, Lista_Indice lista);


#endif
