#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){

  Arvore a;
  inicializar(&a);

  printf("---- Inserindo ----\n");

  inserir(&a, 1);
  printf("A <- %d\n", 1);
  inserir(&a, 2);
  printf("A <- %d\n", 2);
  inserir(&a, 3);
  printf("A <- %d\n", 3);
  inserir(&a, 4);
  printf("A <- %d\n", 4);
  inserir(&a, 5);
  printf("A <- %d\n", 5);
  inserir(&a, 6);
  printf("A <- %d\n", 6);
  inserir(&a, 7);
  printf("A <- %d\n", 7);
  inserir(&a, 9);
  printf("A <- %d\n", 9);
  inserir(&a, 8);
  printf("A <- %d\n", 8);


  printf("---- OK! ----\n");

  printf("---- Removendo ----\n");
  while (!arvoreVazia(a))
  {
    int m = menor(a);
    int r = remover(&a, m);
    printf("A -> %d\n", r);
  }
  printf("---- OK! ----\n");

  return 0;

}
