#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int chave;
  struct no* esquerda;
  struct no* direita;
} No;

typedef struct arvore{

  No* raiz;

} Arvore;

void inicializar(Arvore* a){
  a->raiz = NULL;
}

No* criarNo(int chave){

  No* n = malloc(sizeof(No));
  n->chave = chave;
  n->esquerda = NULL;
  n->direita = NULL;

}

void inserirNo(No* p, No* n){

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
   else {
      printf("Nó já existe!");
      free(n);
      return;
   }

}

void inserir(Arvore* a, int chave){

  No* n = criarNo(chave);

  if (a->raiz == NULL)
    a->raiz = n;
  else
    inserirNo(a->raiz, n);

}

void main(){

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

}
