
# AED2
Algoritmos e Estrutura de Dados 2

## Aula 7

Nesta aula são apresentadas algumas estratégias de implementação da árvore binária de busca.

### Estratégia 1

Nesta estratégia o nó da árvore, ao invés de possuir dois ponteiros (esquerda e direita), possui um vetor de duas posições, em que as posições 0 e 1 são os ponteiros esquera e direita, respectivamente.

```C
#define esquerda 0
#define direita 1

typedef struct no
{
  int chave;
  struct no *filho[2]; // 0 - Esquerda; 1 - Direita
} No;
```
O objetivo desta estratégia é permitir associar posições baseados em números e não em nomes. Observe como fica a função para criar nó:

```C
No *criarNo(int chave){
  No *n = malloc(sizeof(No));
  n->chave = chave;
  n->filho[esquerda] = NULL;
  n->filho[direita] = NULL;
  return n;
}
```

Todavia, a principal vantagem desta abordagem é utilizar-se do resultado de operações de comparação que retornam inteiros 0 para falso e 1 para verdadeiro. Desta forma, é possível evitar comparações para decidir, por exemplo, se será inserido no lado esquerdo ou direito:


```C
void inserirNo(No *p, No *n)
{
  if (n->chave != p->chave)
    if (p->filho[(n->chave > p->chave)] == NULL)
      p->filho[(n->chave > p->chave)] = n;
    else
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
```

Compare com a operação apresentada na aula anterior e veja como a função ficou mais compacta e fazendo o mesmo papel.


Um exemplo incompleto está disponível em:
[exemplo 3](exemplo3/)

### Estratégia 2

Usar ponteiro para ponteiro para evitar criar uma função para tratar a raiz e outra para tratar os nós com recursividade.

```C
void inserir(No** p, int chave)
{
  if ((*p) == NULL){
    (*p) = criarNo(chave);
  } else {
    if (chave != (*p)->chave)
      if ((*p)->filho[(chave > (*p)->chave)] == NULL)
        (*p)->filho[(chave > (*p)->chave)] = criarNo(chave);
      else
        inserir(&((*p)->filho[chave > (*p)->chave]), chave);
    else { // chave == p->chave
      printf("Nó já existe!");
    }
  }
}
```
_Observação: No exemplo acima foi utilizada a estratégia 1 também, porém não é necessária._

Um exemplo incompleto está disponível em:
[exemplo 4](exemplo4/)

## Estratégia 3

É possível criar um apontador pai de um nó. Desta forma teremos um encadeamento duplo entre nós. Os apontamentos de pai devem ser mantidos nas operações de inserção, remoção, etc.


```C
typedef struct no
{
  int chave;
  struct no*filho[2]; // 0 - Esquerda; 1 - Direita
  struct no* pai;
} No;
```
_Observação: No exemplo acima foi utilizada a estratégia 1 também, porém não é necessária._

