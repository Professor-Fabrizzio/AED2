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

int menor(Arvore a)
{
  if (arvoreVazia(a))
    return -1;

  No* aux = a.raiz;
  while(aux->esquerda != NULL)
    aux = aux->esquerda;

  return aux->chave;
  
}

No *criarNo(int chave)
{

  No *n = malloc(sizeof(No));
  n->chave = chave;
  n->esquerda = NULL;
  n->direita = NULL;

  return n;

}

void inserir(Arvore *a, int chave)
{
 
  if (a->raiz == NULL)
    a->raiz = criarNo(chave);
  else{
      No* aux = a->raiz;
      while (1) {
        if (chave < aux->chave){
          if (aux->esquerda == NULL){
            aux->esquerda = criarNo(chave);
            break;
          }else
            aux = aux->esquerda;
        } else if (chave > aux->chave){
          if (aux->direita == NULL){
            aux->direita = criarNo(chave);
            break;
          } else
            aux = aux->direita;
        } else{
          printf("Nó já existe!");
          break;
        }
    }
  }
}
