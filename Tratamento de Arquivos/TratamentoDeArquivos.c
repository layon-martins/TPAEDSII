  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h> // para usar a função tolower

  void tratamentoDePalavras(char *palavra);

  int main(){
      FILE *arquivo = fopen("entrada.txt", "r");
      char palavra[50];
      char *ptr_palavra;

      if(arquivo == NULL){
        printf("Não foi possivel abrir o arquivo\n");
        return 0;
      }

      while(!feof(arquivo)){   
          fscanf(arquivo, "%s", palavra); 
          tratamentoDePalavras(palavra);
          //Quando existem dois caracteres seguidos ele guarda um espaco em branco
          printf("%s\n", palavra);
      }
      fclose(arquivo);

      return 0;

  }

  void tratamentoDePalavras(char *palavra){
    int i;  
    int ascii;  
    for (i = 0; i < strlen(palavra); i++){
      // tolower funciona em caractere
      palavra[i] = tolower(palavra[i]);

      //transforma a palavra para um valor na tabela ascii
      ascii = (int)palavra[i];
      if (ascii < 97 || ascii > 122){
        //caso o caracter não esteja entre a e z minúsculos, ele coloca como fim de string
        palavra[i] = '\0';
      }
    }
  }