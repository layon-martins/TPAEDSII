
/* Trabalho Prático 1 - Disciplina AEDS 2 - UFV CAF
 * Integrantes:
 * Ana Carolina Fernandes - 5094
 * Bárbara Pagnocca - 5061
 * Jéssica Cristina Carvalho - 4686
 * Layon Fonseca Martins - 4220
*/



#ifndef TRATAMENTO_ARQUIVOS_H
#define TRATAMENTO_ARQUIVOS_H

#include "../Indice_Invertido/IndiceInvertido.h"
#include "../Patricia/Patricia.h"

// Prepara as palavras para inserção na PATRICIA
void tratamentoDePalavras(char *palavra);

// insere todas as palavras dos arquivos na PATRICIA
void lerPalavras(Aptd_Pat *A);


#endif