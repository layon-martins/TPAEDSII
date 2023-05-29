
/* Trabalho Prático 1 - Disciplina AEDS 2 - UFV CAF
 * Integrantes:
 * Ana Carolina Fernandes - 5094
 * Bárbara Pagnocca - 5061
 * Jéssica Cristina Carvalho - 4686
 * Layon Fonseca Martins - 4220
*/



#include "../Patricia/Patricia.h"

// calcula a relevância de cada arquivo para a busca
void relevancia(int *vRelevancia, Aptd_Pat *A, int N, String *termos, int quantT);

//função auxiliar da relevância, calcula o termo Wij
float peso(int arq, Aptd_Pat A, int N, String *termos, int quantT);