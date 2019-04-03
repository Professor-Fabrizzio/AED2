
# AED2
Algoritmos e Estrutura de Dados 2

## Aula 3

Nesta aula é apresentado o conceito de árvore binária de busca e alguns algoritmos básicos.
A árvore é composta de nós com filhos à equerda e direita. Sua estrutura de dados pode ser representada como:

```C
typedef struct no{
  int chave;
  struct no* esquerda;
  struct no* direita;
} No;
```

enquanto a árvore contém um nó que representa a raíz:

```C
typedef struct arvore{
  No* raiz;
} Arvore;
```

É recomendável que a árvore seja inicializada, para isto, basta inicializar o nó raiz como nulo:

```C
void inicializar(Arvore* a){
  a->raiz = NULL;
}
```

Quando um nó é inserido na árvore binária temos duas alternativas:
* A árvore está vazia - Criar um novo nó e colocalo como raiz
* A árvore não está vazia - Criar um novo nó e inseri-lo como folha.

Abaixo segue um exemplo em que uma função é usada para inserir na **Árvore** e outra função é usada para inserir nós. É recomendável dar acesso somente à função de inserção na árvore. A função de inserir nós faz acesso interno e foi construída para ser recursiva:

```C
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
```

