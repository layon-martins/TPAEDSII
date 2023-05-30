
/* Trabalho Prático 1 - Disciplina AEDS 2 - UFV CAF
 * Integrantes:
 * Ana Carolina Fernandes - 5094
 * Bárbara Pagnocca - 5061
 * Jéssica Cristina Carvalho - 4686
 * Layon Fonseca Martins - 4220
*/



#include "Relevancia.h"

void relevancia(float *vRelevancia, Aptd_Pat *A, int N, String *termos, int quantT){
    float pesoF;
    int quant = qtdTermosTexto(*A, 1);
    //Ni - Numero de termos distintos do documento
    for(int i = 0; i < N; i++){
        pesoF = peso(i, A, N, termos, quantT);
        vRelevancia[i] = (1/quant) * pesoF;
    }
}

float peso(int arq, Aptd_Pat *A, int N, String *termos, int quantT){
    //peso do termo = f(i,j) (log(Numero de documentos) / (Numero de documentos que contem o termo))
    int Dj = 0;
    float Fij = 0;
    float  Wij = 0;
    for(int j = 0; j < quantT; j++){   //Dj = Numero de documentos que aparece o termo 
                                        //Fij = ocorrencias do termo no documento
        Aptd_Pat Aptd_Termo = Pesquisa(termos[j], *A); 
        Apontador aux;
        aux = Aptd_Termo->NO.NExterno.listaIndiceInvertido.primeiro->proximo;
        if(Aptd_Termo == NULL){
            Dj = 0;
        } else{
            while(aux != NULL){
                Dj++;
                if(aux->idDocumento == arq){
                    Fij = aux->idDocumento;
                } 
                aux = aux->proximo;
            }
        }
        //Pesquisa na Patricia(Termo), olhar no indice invertido se o documento
        // i esta presente 
        // Se eles estiver presente, pegar quantidade no indice invertido
        // Fij = quantidade 
        //Se for 0, d += 0
        //Se for != 0, d+=1
        if (Dj == 0){
            return Wij + 0;
        }
        else {
            Wij = Fij * log(N) / Dj;   
        }
    }
    return Wij;
}