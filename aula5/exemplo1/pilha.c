#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

int pilhaVazia(Pilha p){
  return !(p.quantidade);
}

int pilhaCheia(Pilha p){
  return 0;
}

void inicializaPilha(Pilha* p){
  p->topo = NULL;
  p->quantidade = 0;
}

void inserir(Pilha* p, int valor){

  No* novo = malloc(sizeof(No));

  novo->proximo = p->topo;
  novo->valor = valor;

  p->topo = novo;
  p->quantidade++;

}

int remover(Pilha* p){

  if (pilhaVazia(*p)){

    printf("Pilha vazia!");
    return -1;

  } else {

    No* aux = p->topo;
    int valor = aux->valor;

    p->topo = aux->proximo;
    free(aux);

    p->quantidade--;

    return valor;
  }
}

int verTopo(Pilha p){
  if (pilhaVazia(p)){
    printf("Pilha vazia!");
    return -1;
  } else
    return p.topo->valor;
}

