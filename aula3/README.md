
# AED2
Algoritmos e Estrutura de Dados 2

## Aula 3

Nesta aula é apresentado o conceito de árvore de busca e alguns algoritmos básicos.
Para isto foi apresentada uma árvore unária (hipotética).
Esta árvore é na verdade uma lista simplesmente encadeada em que seus nós estão ordenados conforme suas chaves. Logo as operações sobre a árvore são bastante limitadas. Por exemplo, não é permitido escolher uma posição qualquer para inserir um nó.

```C
typedef struct no{
  int chave;
  struct no* proximo;
} No;
```

enquanto a árvore contém um nó que representa a raíz:

```C
typedef struct arvore{
  No* raiz;
} Arvore;
```

Observe que esta árvore, diferente da lista simplesmente encadeada, não há um nó de fim, dado que operações sobre este são raras. Assim, todas as operações são feitas partindo da raiz em direção à folha.

É recomendável que a árvore seja inicializada, para isto, basta inicializar o nó raiz como nulo:

```C
void inicializar(Arvore* a){
  a->raiz = NULL;
}
```

## Atividade 1

Codificar a árvore unária e submete-la no SIGA-A.
