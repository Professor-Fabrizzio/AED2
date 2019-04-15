#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

typedef struct no
{
  int chave;
  struct no *esquerda;
  struct no *direita;
  int he;
  int hd;
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
  n->he = 0;
  n->hd = 0;

  return n;

}

int alturaNo(No* n){
  if (n == NULL)
    return 0;
  else {
    if (n->he > n->hd)
      return n->he + 1;
    else
      return n->hd + 1;    
  }  
}

void atualizaNo(No* n){
  if (n){
    n->he = alturaNo(n->esquerda);
    n->hd = alturaNo(n->direita);
  }
}

void rotacionarParaDireita(No* p, No* n){

  if (n->esquerda){
    No* aux = n->esquerda;
    n->esquerda = aux->direita;
    aux->direita = n;
    if (aux->chave < p->chave)
      p->esquerda = aux;
    else
      p->direita = aux;

    atualizaNo(n);
    atualizaNo(aux);
    atualizaNo(p);

  } else {
    printf("Rotação não permitida!");
  }
}

void rotacionarParaEsquerda(No* p, No* n){

  if (n->direita){
    No* aux = n->direita;
    n->direita = aux->esquerda;
    aux->esquerda = n;
    if (aux->chave < p->chave)
      p->esquerda = aux;
    else
      p->direita = aux;
    
    atualizaNo(n);
    atualizaNo(aux);
    atualizaNo(p);

  } else {
    printf("Rotação não permitida!");
  }
}

void rotacionarRaizParaDireita(Arvore* a){

  if ((a->raiz) && (a->raiz->esquerda)){

    No* aux = a->raiz;
    a->raiz = aux->esquerda;
    aux->esquerda = a->raiz->direita;
    a->raiz->direita = aux;

    atualizaNo(aux->esquerda);
    atualizaNo(a->raiz->direita);
    atualizaNo(a->raiz);

  } else {
    printf("Rotação não permitida!");
  }
}

void rotacionarRaizParaEsquerda(Arvore* a){

  if ((a->raiz) && (a->raiz->direita)){

    No* aux = a->raiz;
    a->raiz = aux->direita;
    aux->direita = a->raiz->esquerda;
    a->raiz->esquerda = aux;
    
    atualizaNo(aux->direita);
    atualizaNo(a->raiz->esquerda);
    atualizaNo(a->raiz);

  } else {
    printf("Rotação não permitida!");
  }
}

void balancearNo(No* p, No* n){
  
  if (n->he - n->hd > 1){
    if (n->esquerda->he - n->esquerda->hd < 0) // Rotação Dupla
      rotacionarParaEsquerda(n, n->esquerda);

    rotacionarParaDireita(p, n);

  } else if (n->he - n->hd < -1){

    if (n->direita->he - n->direita->hd > 0) // Rotação Dupla
      rotacionarParaDireita(n, n->direita);

    rotacionarParaEsquerda(p, n);
  }
}

void balancearRaiz(Arvore* a){
    
  if (a->raiz->he - a->raiz->hd > 1){

    if (a->raiz->esquerda->he - a->raiz->esquerda->hd < 0) // Rotação Dupla
      rotacionarParaEsquerda(a->raiz, a->raiz->esquerda);

    rotacionarRaizParaDireita(a);
  } else if (a->raiz->he - a->raiz->hd < -1){

    if (a->raiz->direita->he - a->raiz->direita->hd > 0) // Rotação Dupla
      rotacionarParaDireita(a->raiz, a->raiz->direita);

    rotacionarRaizParaEsquerda(a);
  }

}

int inserirNo(No *p, No *n)
{
  int r;
  if (n->chave < p->chave)
    if (p->esquerda == NULL){
      p->esquerda = n;
      p->he++;
      return 1;
    } else {
      r = inserirNo(p->esquerda, n);
      balancearNo(p, p->esquerda);
      atualizaNo(p);
      return r;
    } 
  else if (n->chave > p->chave)
    if (p->direita == NULL){
      p->direita = n;
      p->hd++;
      return 1;
    } else {
      r = inserirNo(p->direita, n);
      balancearNo(p, p->direita);
      atualizaNo(p);
      return r;
  } else  {
    printf("Nó já existe!");
    free(n);
    return 0;
  }

}

void inserir(Arvore *a, int chave)
{

  No *n = criarNo(chave);

  if (a->raiz == NULL)
    a->raiz = n;
  else {
    inserirNo(a->raiz, n);
    balancearRaiz(a);
    atualizaNo(a->raiz);
  }
}

No *removerSucessor(No *p, No *n)
{
  if (n->esquerda == NULL)
  {
    if (n->chave < p->chave){
      p->esquerda = n->direita;
    } else{ 
      p->direita = n->direita;
      p->hd--;
    }
    return n;
  }
  else {
    No* suc = removerSucessor(n, n->esquerda);
    atualizaNo(n);
    balancearNo(p, n);
    return suc;
  }
}

No *removerNo(No *p, No *n, int chave)
{
  if (chave < n->chave)
    if (n->esquerda == NULL){
      printf("Nó não encontrado!\n");
      return NULL;
    } else {
      No* aux = removerNo(n, n->esquerda, chave);
      if (aux) {
        atualizaNo(n);
        balancearNo(p, n);
      }
      return aux;
    }
  else if (chave > n->chave)
    if (n->direita == NULL){
      printf("Nó não encontrado!\n");
      return NULL;
    } else {
      No* aux = removerNo(n, n->direita, chave);
      if (aux) {
        atualizaNo(n);
        balancearNo(p, n);
      }
      return aux;
    }
  else // chave == n->chave
  {
    if ((n->esquerda == NULL) && (n->direita == NULL))
    {
      if (chave < p->chave){
        p->esquerda = NULL;
        p->he--;
      } else if (chave > p->chave) {
        p->direita = NULL;
        p->hd--;
      }
    } else if (n->esquerda == NULL) {
      if (chave < p->chave) {
        p->esquerda = n->direita;
        p->he--;
      } else if (chave > p->chave) {
        p->direita = n->direita;
        p->hd--;
      }
    } else if (n->direita == NULL) {
      if (chave < p->chave) {
        p->esquerda = n->esquerda;
        p->he--;
      } else if (chave > p->chave) {
        p->direita = n->esquerda;
        p->hd--;
      }
    } else { // n->esquerda !=NULL && n->direita != NULL
      No *suc = removerSucessor(n, n->direita);
      suc->esquerda = n->esquerda;
      suc->direita = n->direita;
      atualizaNo(suc);
      balancearNo(p, n);
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
    else{ // raiz->esquerda != NULL && raiz->direita != NULL
      No *suc = removerSucessor(a->raiz, a->raiz->direita);
      suc->esquerda = a->raiz->esquerda;
      suc->direita = a->raiz->direita;
      atualizaNo(suc);
      a->raiz = suc;
    }
  }

  if (a->raiz != NULL) {
    atualizaNo(a->raiz);
    balancearRaiz(a);
  }

  if (aux == NULL)
    printf("Chave não encontrada!");
  else  {
    i = aux->chave;
    free(aux);
  }    

  return i;
}