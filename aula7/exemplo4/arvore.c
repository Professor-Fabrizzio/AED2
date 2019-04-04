#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

#define esquerda 0
#define direita 1

void inicializar(No** a)
{
  (*a) = NULL;
}

int arvoreVazia(No** a)
{
  return ((*a) == NULL);
}

int menor(No** a){

  if ((*a) == NULL)
    return -1;
  else
    if ((*a)->filho[esquerda] == NULL)
      return (*a)->chave;
    else
      return menor(&(*a)->filho[esquerda]);
}

No *criarNo(int chave){
  No *n = malloc(sizeof(No));
  n->chave = chave;
  n->filho[esquerda] = NULL;
  n->filho[direita] = NULL;
  return n;
}

void inserir(No** p, int chave)
{
  if ((*p) == NULL){
    (*p) = criarNo(chave);
  } else {
    if (chave != (*p)->chave)
      if ((*p)->filho[(chave > (*p)->chave)] == NULL)
        (*p)->filho[(chave > (*p)->chave)] = criarNo(chave);
      else
        inserir(&((*p)->filho[chave > (*p)->chave]), chave);
    else { // chave == p->chave
      printf("Nó já existe!");
    }
  }
}

