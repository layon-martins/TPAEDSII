#include "Relevancia.h"

void relevancia(int *vRelevancia, Aptd_Pat *A, int N, String *termos, int quantT){
    //Ni - Numero de termos distintos do documento
    for(int i = 0; i < N; i++){
        vRelevancia[i] = (1/qtdTermosTexto(A, i)) * peso(i, A, N, termos, quantT);
    }
}

float peso(int arq, Aptd_Pat A, int N, String *termos, int quantT){
    //peso do termo = f(i,j) (log(Numero de documentos) / (Numero de documentos que contem o termo))
    int Dj = 0;
    float Fij = 0;
    float  Wij = 0;
    for(int j = 0; j < quantT; j++){   //Dj = Numero de documentos que aparece o termo 
                                            //Fij = ocorrencias do termo no documento
        Aptd_Pat *Aptd_Termo = Pesquisa(termos[j], A); 
        Lista_Indice *aux  = &(*Aptd_Termo)->NO.NExterno.listaIndiceInvertido;

        while(aux->primeiro != NULL){
            Dj++;
            if(aux->primeiro->idDocumento == arq){
                Fij = aux->primeiro->quantidade;
            } 
            aux = aux->primeiro->proximo;
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