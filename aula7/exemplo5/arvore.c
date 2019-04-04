#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

#define esquerda 0
#define direita 1

typedef struct no
{
  int chave;
  struct no*filho[2]; // 0 - Esquerda; 1 - Direita
  struct no* pai;
} No;

No *criarNo(int chave){
  No *n = malloc(sizeof(No));
  n->chave = chave;
  n->pai = NULL;
  n->filho[esquerda] = NULL;
  n->filho[direita] = NULL;
  return n;
}

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

void inserirNo(No *p, No *n)
{
  if (n->chave != p->chave)
    if (p->filho[(n->chave > p->chave)] == NULL){
      p->filho[(n->chave > p->chave)] = n;
      n->pai = p;
    } else
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

No *removerSucessor(No *p, No *n)
{

  if (n->filho[esquerda] == NULL)
  {
    n->filho[direita]->pai = p;
    p->filho[n->chave > p->chave] = n->filho[direita];
    return n;
  }
  else
    return removerSucessor(n, n->filho[esquerda]);
}

No *removerNo(No *n, int chave)
{
  if (chave != n->chave)
    if (n->filho[(chave > n->chave)] == NULL)
      return NULL;
    else
      return removerNo(n->filho[(chave > n->chave)], chave);
  else // chave == n->chave
  {
    if ((n->filho[esquerda] == NULL) && (n->filho[direita] == NULL))
      n->pai->filho[chave > n->pai->chave] = NULL;
    else if (n->filho[esquerda] == NULL){
      n->pai->filho[chave > n->pai->chave] = n->filho[direita];
      n->filho[direita]->pai = n->pai;
    }else if (n->filho[direita] == NULL){
      n->pai->filho[chave > n->pai->chave] = n->filho[esquerda];
      n->filho[esquerda]->pai = n->pai;
    } else
    { // n->esquerda !=NULL && n->direita != NULL
      No *suc = removerSucessor(n, n->filho[direita]);
      suc->filho[esquerda] = n->filho[esquerda];
      suc->filho[direita] = n->filho[direita];
      n->pai->filho[chave > n->pai->chave] = suc;
      suc->pai = n->pai->filho[chave > n->pai->chave];
    }
    return n;
  }
}

int remover(Arvore *a, int chave)
{
  int i = -1;
  No *aux = NULL;
  if (a->raiz == NULL) return 0;

  if (a->raiz->chave != chave)
    aux = removerNo(a->raiz->filho[(chave > a->raiz->chave)], chave);
  else // raiz->chave == chave
  {
    aux = a->raiz;
    if ((a->raiz->filho[esquerda] == NULL) || (a->raiz->filho[direita] == NULL))
      a->raiz = a->raiz->filho[(a->raiz->filho[esquerda] == NULL)];
    else
    { // raiz->esquerda != NULL && raiz->direita != NULL
      No *suc = removerSucessor(a->raiz, a->raiz->filho[direita]);
      suc->filho[esquerda] = a->raiz->filho[esquerda];
      suc->filho[direita] = a->raiz->filho[direita];
      suc->pai = NULL;
      a->raiz = suc;
    }
  }

  if (aux != NULL)  {
    i = aux->chave;
    free(aux);
  } else
    printf("Chave não encontrada!");

  return i;
}
