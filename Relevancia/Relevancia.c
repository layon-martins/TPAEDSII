
/* Trabalho Prático 1 - Disciplina AEDS 2 - UFV CAF
 * Integrantes:
 * Ana Carolina Fernandes - 5094
 * Bárbara Pagnocca - 5061
 * Jéssica Cristina Carvalho - 4686
 * Layon Fonseca Martins - 4220
*/



#include "Relevancia.h"

void relevancia(int *vRelevancia, Aptd_Pat *A, int N, String *termos, int quantT){
    //Ni - Numero de termos distintos do documento
    for(int i = 0; i < N; i++){
        vRelevancia[i] = (1/qtdTermosTexto(A, i)) * peso(i, A, N, termos, quantT);
    }
}

float peso(int arq, Aptd_Pat A, int N, String *termos, int quantT){
    //peso do termo j no doc i = f(i,j)*(log(Número total de documentos) / (Número de documentos com o termo))
    int Dj = 0;
    float Fij = 0;
    float  Wij = 0;
    for(int j = 0; j < quantT; j++){    
        Aptd_Pat *Aptd_Termo = Pesquisa(termos[j], A); 
        Lista_Indice *aux  = &(*Aptd_Termo)->NO.NExterno.listaIndiceInvertido;

        while(aux->primeiro != NULL){ // Dj = Número de documentos que aparece o termo 
            Dj++;
            if(aux->primeiro->idDocumento == arq){
                Fij = aux->primeiro->quantidade;    // Fij = Ocorrências do termo no documento
            } 
            aux = aux->primeiro->proximo;
        }
        // Pesquisa na Patricia(Termo): ver no índice invertido se o documento i está presente 
        // Se ele estiver presente, pegar a quantidade de vezes no índice invertido
        // Fij = frequência do termo j no documento i
        if (Dj == 0){
            return Wij + 0;
        }
        else {
            Wij = Fij * log(N) / Dj;   
        }
    }
    return Wij;
}