#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){

  No* raiz;
  inicializar(&raiz);

  printf("---- Inserindo ----\n");

  inserir(&raiz, 10);
  printf("A <- %d\n", 10);
  inserir(&raiz, 1);
  printf("A <- %d\n", 1);
  inserir(&raiz, 9);
  printf("A <- %d\n", 9);
  inserir(&raiz, 111);
  printf("A <- %d\n", 111);
  inserir(&raiz, 98);
  printf("A <- %d\n", 98);

  printf("---- OK! ----\n");
  
  return 0;

}
