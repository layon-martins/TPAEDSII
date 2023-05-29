/* Trabalho Prático 1 - Disciplina AEDS 2 - UFV CAF
 * Integrantes:
 * Ana Carolina Fernandes - 5094
 * Bárbara Pagnocca - 5061
 * Jéssica Cristina Carvalho - 4686
 * Layon Fonseca Martins - 4220
*/

#include "../Indice_Invertido/IndiceInvertido.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Patricia.h"

boolean EExterno(Aptd_Pat p){
    return (p->nt == Externo)?TRUE:FALSE;
}

boolean ComparaLetra(int i, char letra, String s){
    return(s[i] <= letra)?TRUE:FALSE;
}

//Encontra indice do primeiro caractere diferente entre duas strings
int Indice(String S, String P, int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("%c - %c\n", S[i], P[i]);
        if(S[i] != P[i])
            return i;
    }
    return i;
}

//Compara duas strings usando tam da menor e a funcao anterior
int ComparaChaves(String S, String P){
    return(strlen(S)<strlen(P))?Indice(S,P,strlen(S)):Indice(S,P,strlen(P));
}

//achar primeiro caractere diferente
char AchaLetra(Aptd_Pat *A, int i, String Palavra){
    while(!EExterno(*A)){
        if(ComparaLetra((*A)->NO.NInterno.Index,(*A)->NO.NInterno.Caractere,Palavra)){
            A = &(*A)->NO.NInterno.Dir;
        }
        else A = &(*A)->NO.NInterno.Esq;
    }
    if(ComparaLetra(i, (*A)->NO.Chave[i], Palavra))return (*A)->NO.Chave[i];
    return Palavra[i];
}

Aptd_Pat CriaNoInt(short i, Aptd_Pat *Esq, Aptd_Pat *Dir, char Caractere){
    Aptd_Pat N;
    N =(Aptd_Pat)malloc(sizeof(NoPatricia));
    N->nt = Interno;
    N->NO.NInterno.Esq = *Esq;
    N->NO.NInterno.Dir = *Dir;
    N->NO.NInterno.Index = i;
    N->NO.NInterno.Caractere = Caractere;
    printf("Criando um nó interno\n");
    //printf("Indice: %d\n",N->NO.NInterno.Index);
    //printf("Caracter: %c\n",N->NO.NInterno.Caractere);
    return N;
}

Aptd_Pat CriaNoExt(String S, int idDoc){
    //printf("CHAVE %s\n", S);
    Aptd_Pat N;
    //Lista_Indice lista;
    //FLVazia(&lista);
    N = (Aptd_Pat)malloc(sizeof(NoPatricia));
    N->nt = Externo;
    strcpy(N->NO.Chave, S);
    //InsereLista(idDoc, &lista);
    //N->NO.listaIndiceInvertido = lista;
    printf("Criando um nó externo\n");
    //printf("Chave: %s\n", N->NO.Chave);
    return N;
}

Aptd_Pat InsereEntre(String S, Aptd_Pat *A, int i, int idDoc){
    Aptd_Pat p;//Apontador auxiliar que recebera o endereco do no externo criado para a palavra a ser inserida
    if(EExterno(*A) || i < (*A)->NO.NInterno.Index){
        p = CriaNoExt(S,idDoc);
        if(EExterno(*A)){
                //printf("CAR: %c\n",(*A)->NO.Chave[i]);
            if(ComparaLetra(i, (*A)->NO.Chave[i], S)){
                //printf("Indice que se difere: %d\n", i);
                return(CriaNoInt(i, A, &p, S[i]));
            }
            return (CriaNoInt(i, &p, A, (*A)->NO.Chave[i]));
        }
        if(AchaLetra(A, i, S) == S[i])return(CriaNoInt(i, &p, A, S[i]));
        return (CriaNoInt(i, A, &p, AchaLetra(A, i, S)));
    }
    if(ComparaLetra((*A)->NO.NInterno.Index, (*A)->NO.NInterno.Caractere, S)){
        (*A)->NO.NInterno.Dir = InsereEntre(S, &(*A)->NO.NInterno.Dir, i, idDoc);
    }
    (*A)->NO.NInterno.Esq = InsereEntre(S, &(*A)->NO.NInterno.Esq, i, idDoc);
    return (*A);
}

Aptd_Pat InserePatricia(String S, Aptd_Pat *t, int idDoc){
    Aptd_Pat *p;
    int i;
    if(*t == NULL)return (CriaNoExt(S, idDoc));
    p = t;//Ponteiro auxiliar recebe ponteiro da arvore
    while(!EExterno(*p)){

        if(strlen(S) < (*p)->NO.NInterno.Index)p = AchaNoExterno(p);
        else{
            if(ComparaLetra((*p)->NO.NInterno.Index, (*p)->NO.NInterno.Caractere, S)){
                p = &(*p)->NO.NInterno.Esq;
            }else 
                p = &(*p)->NO.NInterno.Dir;
        }
    }
    i = ComparaChaves((*p)->NO.Chave, S);
    if(strlen((*p)->NO.Chave) == strlen(S)){
        if(i == strlen((*p)->NO.Chave)){ //Aqui vemos que a palavra ja existe na arvore
            //momento de incrementar lista de indice invertido
        return (*t);
        }
    }
    return (InsereEntre(S, t, i, idDoc));;
    
}

//Retorna o no externo contendo a chave a se comparar com a palavra
Aptd_Pat *AchaNoExterno(Aptd_Pat *A){
    while(!EExterno(*A))A = &(*A)->NO.NInterno.Esq;
    return A;
}

//Retorna NULL quando o no externo onde ela deveria estar tem uma palavra diferente
//Retorna o no quando a palavra esta la
Aptd_Pat Pesquisa(String S, Aptd_Pat A){
    if(EExterno(A)){
        if(strcmp(S, A->NO.Chave))
            return NULL;
        return A;
    }
    if(ComparaLetra(A->NO.NInterno.Index, A->NO.NInterno.Caractere, S))
        return Pesquisa(S, A->NO.NInterno.Dir);
    return Pesquisa(S, A->NO.NInterno.Esq);
}

void ImprimeEmOrdem(Aptd_Pat A){
    if(A == NULL){
        printf("\nArvore vazia.");
        return;
    }
    if(EExterno(A)){
        printf("\n %s\n", (A)->NO.Chave);
    }
    else{
        ImprimeEmOrdem(A->NO.NInterno.Esq);
        ImprimeEmOrdem(A->NO.NInterno.Dir);
    }
}
