
# AED2
Algoritmos e Estrutura de Dados 2

## Aula 6

Nesta aula é apresentado o conceito de busca e remoção em árvore binária **de busca**.

A busca encarrega-se de verificar se o nó está ou não na árvore. Em alguns casos retorna o registro que é apontado pelo nó.
```C

```
Já a operação de remoção considera três Casos:
1. O nó a ser removido não tem filhos (É uma folha)
2. O nó a ser removido só tem um filho (ramo incompleto), assim há duas situações:
  * Não tem filho à esquerda
  * Nâo tem filho à direita
3. O nó a ser removido possui dois filhos

Abaixo segue um código para remover nós em uma árvore binária:

```C
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
```

Para remover na árvore é necessário realizar as operações sobre a raiz, e desta forma, tratar os 3 casos também.

```C
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

```

Para realizar a remoção no caso 3, é necessário remover o sucessor do nó na árvore e utiliza-lo na substituição do nó removido.
```C
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
```

Alguns dos códigos acima estão disponíveis no arquivo de exemplo no link:
[Exemplo6](exemplo1/exemplo-arvore1.c)

