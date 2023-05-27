#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../Tratamento_Arquivos/TratamentoDeArquivos.h"
#include "../Patricia/Patricia.h"



int main(){

    Aptd_Pat A;

    lerPalavras(&A);
    ImprimeEmOrdem(A);
    

    return 0;
}