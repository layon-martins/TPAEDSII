#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../Tratamento_Arquivos/TratamentoDeArquivos.c"
#include "../Patricia/Patricia.c"



int main(){

    Aptd_Pat A = NULL;

    lerPalavras(&A);
    ImprimeEmOrdem(A);
    

    return 0;
}