/* Trabalho Prático 1 - Disciplina AEDS 2 - UFV CAF
 * Integrantes:
 * Ana Carolina Fernandes - 5094
 * Bárbara Pagnocca - 5061
 * Jéssica Cristina Carvalho - 4686
 * Layon Fonseca Martins - 4220
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef char String[50];
typedef short boolean;

typedef enum{
    Interno, Externo
}TipoNo;

typedef struct NoPatricia *Aptd_Pat;
typedef struct NoPatricia{
    TipoNo nt;
    union
    {
        struct{
            short Index;
            char Caractere;
            Aptd_Pat Esq, Dir;
        }NInterno;
        String Chave;
        //Indice Invertido aqui
    }NO;
}NoPatricia;

Aptd_Pat InserePatricia(String S, Aptd_Pat *A, int idDoc);
Aptd_Pat InsereEntre(String S, Aptd_Pat *A, int i, int idDoc);
Aptd_Pat CriaNoExt(String S, int idDoc);
Aptd_Pat CriaNoInt(short i, Aptd_Pat *Esq,  Aptd_Pat *Dir, char Caractere);
Aptd_Pat*AchaNoExterno(Aptd_Pat *A);
Aptd_Pat Pesquisa(String S, Aptd_Pat A);
char AchaLetra(Aptd_Pat *A, int i, String Palavra);
boolean EExterno(Aptd_Pat A);
boolean ComparaLetra(int i, char letra, String S);
int Indice(String S, String P, int tam);
int ComparaChaves(String S, String P);
void ImprimeEmOrdem(Aptd_Pat A);
