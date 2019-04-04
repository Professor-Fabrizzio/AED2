#include <stdio.h>
#include "pilha.h"

void main(){

  Pilha p;
  inicializaPilha(&p);

  printf("---- Inserindo ----\n");

  inserir(&p, 10);
  printf("P <- %d\n", verTopo(p));
  inserir(&p, 1);
  printf("P <- %d\n", verTopo(p));
  inserir(&p, 9);
  printf("P <- %d\n", verTopo(p));
  inserir(&p, 111);
  printf("P <- %d\n", verTopo(p));
  inserir(&p, 98);
  printf("P <- %d\n", verTopo(p));

  printf("---- Removendo ----\n");
  while (!pilhaVazia(p))
    printf("P -> %d\n", remover(&p));

}
