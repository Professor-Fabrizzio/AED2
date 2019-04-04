#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

#define esquerda 0
#define direita 1

typedef struct no
{
  int chave;
  struct no *filho[2]; // 0 - Esquerda; 1 - Direita
} No;

void inicializar(Arvore *a)
{
  a->raiz = NULL;
}

int arvoreVazia(Arvore a)
{
  return (a.raiz == NULL);
}

int menorNo(No *n){

  if (n->filho[esquerda] == NULL)
    return n->chave;
  else
    return menorNo(n->filho[esquerda]);
}

int menor(Arvore a){
  if (arvoreVazia(a))
    return -1;
  else
    return menorNo(a.raiz);
}

No *criarNo(int chave){
  No *n = malloc(sizeof(No));
  n->chave = chave;
  n->filho[esquerda] = NULL;
  n->filho[direita] = NULL;
  return n;
}

void inserirNo(No *p, No *n)
{
  if (n->chave != p->chave)
    if (p->filho[(n->chave > p->chave)] == NULL)
      p->filho[(n->chave > p->chave)] = n;
    else
      inserirNo(p->filho[n->chave > p->chave], n);
  else { // n->chave == p->chave
    printf("Nó já existe!");
    free(n);
    return;
  }
}

void inserir(Arvore *a, int chave)
{

  No *n = criarNo(chave);

  if (a->raiz == NULL)
    a->raiz = n;
  else
    inserirNo(a->raiz, n);
}

