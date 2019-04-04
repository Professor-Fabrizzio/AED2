#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

typedef struct no
{
  int chave;
  struct no *esquerda;
  struct no *direita;
} No;

void inicializar(Arvore *a)
{
  a->raiz = NULL;
}

int arvoreVazia(Arvore a)
{
  return (a.raiz == NULL);
}

int menorNo(No *n)
{

  if (n->esquerda == NULL)
    return n->chave;
  else
    return menorNo(n->esquerda);
}

int menor(Arvore a)
{
  if (arvoreVazia(a))
    return -1;
  else
    return menorNo(a.raiz);
}

No *criarNo(int chave)
{

  No *n = malloc(sizeof(No));
  n->chave = chave;
  n->esquerda = NULL;
  n->direita = NULL;

  return n;

}

void inserirNo(No *p, No *n)
{

  if (n->chave < p->chave)
    if (p->esquerda == NULL)
      p->esquerda = n;
    else
      inserirNo(p->esquerda, n);
  else if (n->chave > p->chave)
    if (p->direita == NULL)
      p->direita = n;
    else
      inserirNo(p->direita, n);
  else
  {
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

  if (n->esquerda == NULL)
  {
    if (n->chave < p->chave)
      p->esquerda = n->direita;
    else
      p->direita = n->direita;
    return n;
  }
  else
    return removerSucessor(n, n->esquerda);
}

No *removerNo(No *p, No *n, int chave)
{

  if (chave < n->chave)
    if (n->esquerda == NULL)
      return NULL;
    else
      return removerNo(n, n->esquerda, chave);
  else if (chave > n->chave)
    if (n->direita == NULL)
      return NULL;
    else
      return removerNo(n, n->direita, chave);

  else // chave == n->chave
  {
    if ((n->esquerda == NULL) && (n->direita == NULL))
    {
      if (chave < p->chave)
      {
        p->esquerda = NULL;
      }
      else if (chave > p->chave)
      {
        p->direita = NULL;
      }
    }
    else if (n->esquerda == NULL)
    {
      if (chave < p->chave)
      {
        p->esquerda = n->direita;
      }
      else if (chave > p->chave)
      {
        p->direita = n->direita;
      }
    }
    else if (n->direita == NULL)
    {
      if (chave < p->chave)
      {
        p->esquerda = n->esquerda;
      }
      else if (chave > p->chave)
      {
        p->direita = n->esquerda;
      }
    }
    else
    { // n->esquerda !=NULL && n->direita != NULL
      No *suc = removerSucessor(n, n->direita);
      suc->esquerda = n->esquerda;
      suc->direita = n->direita;
      if (chave < p->chave)
        p->esquerda = suc;
      else
        p->direita = suc;
    }
    return n;
  }
}

int remover(Arvore *a, int chave)
{

  int i = -1;
  No *aux = NULL;
  if (a->raiz == NULL)
    return 0;

  if (a->raiz->chave != chave)
    if (chave < a->raiz->chave)
      aux = removerNo(a->raiz, a->raiz->esquerda, chave);
    else
      aux = removerNo(a->raiz, a->raiz->direita, chave);
  else // raiz->chave == chave
  {
    aux = a->raiz;
    if ((a->raiz->esquerda == NULL) && (a->raiz->direita == NULL))
      a->raiz = NULL;
    else if (a->raiz->esquerda == NULL)
      a->raiz = a->raiz->direita;
    else if (a->raiz->direita == NULL)
      a->raiz = a->raiz->esquerda;
    else
    { // raiz->esquerda != NULL && raiz->direita != NULL
      No *suc = removerSucessor(a->raiz, a->raiz->direita);
      suc->esquerda = a->raiz->esquerda;
      suc->direita = a->raiz->direita;
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
