
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
