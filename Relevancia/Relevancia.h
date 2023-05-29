#include "../Patricia/Patricia.h"

// calcula a relevância de cada arquivo
void relevancia(int *vRelevancia, Aptd_Pat *A, int N, String *termos, int quantT);

float peso(int arq, Aptd_Pat A, int N, String *termos, int quantT);