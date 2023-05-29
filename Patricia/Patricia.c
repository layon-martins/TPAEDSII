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
    if(ComparaLetra(i, (*A)->NO.NExterno.Chave[i], Palavra))return (*A)->NO.NExterno.Chave[i];
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
    //printf("Indice %d Caractere %c\n", N->NO.NInterno.Index, N->NO.NInterno.Caractere);
    return N;
}

Aptd_Pat CriaNoExt(String S, int idDoc){
    Aptd_Pat N;
    Lista_Indice lista;
    FLVazia(&lista);
    N = (Aptd_Pat)malloc(sizeof(NoPatricia));
    N->nt = Externo;
    strcpy(N->NO.NExterno.Chave, S);
    InsereLista(idDoc, &lista);
    N->NO.NExterno.listaIndiceInvertido = lista;
    //printf("NO EXTERNO: %s\n", N->NO.NExterno.Chave);
    return N;
}

Aptd_Pat InsereEntre(String S, Aptd_Pat *A, int i, int idDoc){
    Aptd_Pat p;
    if (EExterno(*A) || i < (*A)->NO.NInterno.Index){
    p = CriaNoExt(S, idDoc);
    if (EExterno(*A)){
      if ((*A)->NO.NExterno.Chave[i] < p->NO.NExterno.Chave[i])
        return (CriaNoInt(i, A, &p, (*A)->NO.NExterno.Chave[i]));
      else{
        return (CriaNoInt(i, &p, A, p->NO.NExterno.Chave[i]));
      }
    }
    else {
      Aptd_Pat aux;
      aux = (*A);
      while (!EExterno(aux)){
        aux = aux->NO.NInterno.Esq;
      }

      if (aux->NO.NExterno.Chave[i] < p->NO.NExterno.Chave[i])
        return (CriaNoInt(i, A, &p, aux->NO.NExterno.Chave[i]));
      else{
        return (CriaNoInt(i, &p, A,  p->NO.NExterno.Chave[i]));
      }
    }
  }
  else{
    if ((*A)->NO.NInterno.Caractere < S[(*A)->NO.NInterno.Index])
      (*A)->NO.NInterno.Dir = InsereEntre(S, &(*A)->NO.NInterno.Dir, i, idDoc);
    else
      (*A)->NO.NInterno.Esq = InsereEntre(S, &(*A)->NO.NInterno.Esq, i, idDoc);
    return (*A);
  }
}

int retornaMaior(char index, char caractere){
    if(index <= caractere){
        return 0;
    }else{
        return 1;
    }
}


Aptd_Pat InserePatricia(String S, Aptd_Pat *t, int idDoc){
  Aptd_Pat p;
  int i;
  if (*t == NULL){
    return (CriaNoExt(S, idDoc));
  } else{
    p = *t;
    while (!EExterno(p)){
      if (retornaMaior(S[p->NO.NInterno.Index], p->NO.NInterno.Caractere) == 1){
        p = p->NO.NInterno.Dir;
      } else{
        p = p->NO.NInterno.Esq;
      }
    }
     i = 0;
    while((i<=strlen(S)) & (S[i]) == (p->NO.NExterno.Chave[i])){
        i++;
    }
    if(i > strlen(S)){
        IncrementaQuantidade(idDoc, (p->NO.NExterno.listaIndiceInvertido));
        return(*t);
    }else
        return (InsereEntre(S, t, i, idDoc));
  }
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
        if(strcmp(S, A->NO.NExterno.Chave))
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
    if(A->nt == Externo){
        if(strlen(A->NO.NExterno.Chave)>0){
            printf("Palavra: %s \n",A->NO.NExterno.Chave);
            //ImprimeIndice(A->NO.NExterno.listaIndiceInvertido);

        }
    }
    else{
        ImprimeEmOrdem(A->NO.NInterno.Esq);
        ImprimeEmOrdem(A->NO.NInterno.Dir);
    }
}
