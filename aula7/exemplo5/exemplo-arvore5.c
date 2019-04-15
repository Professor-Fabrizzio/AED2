#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){

  Arvore a;
  inicializar(&a);

  printf("---- Inserindo ----\n");

  inserir(&a, 10);
  printf("A <- %d\n", 10);
  inserir(&a, 1);
  printf("A <- %d\n", 1);
  inserir(&a, 9);
  printf("A <- %d\n", 9);
  inserir(&a, 111);
  printf("A <- %d\n", 111);
  inserir(&a, 98);
  printf("A <- %d\n", 98);

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
