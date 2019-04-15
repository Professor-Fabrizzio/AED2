
# AED2
Algoritmos e Estrutura de Dados 2

## Aula 8

Nesta aula é apresentado problema da degeneração/desbalanceamento de árvore e a árvore AVL.

### Desbalanceamento / Degeneração

Suponha que as chaves de 1 a 7 sejam inseridas na seguinte ordem:
4, 2, 6, 1, 3, 5, 7.

A árvore resultante é uma árvore que possui a quantidade possível de nós em cada nível, e todos os nós folha estão em um único nível. Desta forma nossa árvore está completamente balanceada.

![Arvore Balanceada](balanceada.png)

Todavia, suponha que as chaves abaixo sejam inseridas na seguinte ordem:

4, 7, 16, 20, 37, 38, 43.

![Arvore Balanceada](desbalanceada.png)

Observe que, embora as chaves sejam inseridas na ordem crescente, o resultado da árvore será o equivalente a uma lista simplesmente encadeada. Desta forma, perdemos a grande vantagem de uma ávore balanceada. Esta árvore sofreu uma degeneração ou desbalanceamento.

Destaco que tanto a inserção quanto a remoção provocam desbalanceamentos. Assim, faz-se necessário reorganizar a árvore a cada operação. Para isto é necessário conhecer o fator de balanceamento, calculando-se das folhas para a raiz. Um nó está balanceado desde que o módulo da diferença entre as alturas das sub-arvores esquerda e direita deste seja menor que dois. Caso o contrário, é necessário realizar operações de rotação.

## Operações de rotação
As rotações podem ser realizadas para a direita ou esquerda, conforme o desbalanceamento encontrado.

![Balanceamento para esquerda](rsesq.gif)

![Balanceamento para a direita](rsdir.gif)

Todavia, há casos em que essas rotações ao inves de corrigir o nó, acaba apenas por espelha-lo.

![Falha de balanceamento](treerotation.png)

Assim, é necessário realizar rotações duplas, que consistem de rotacionar o filho da direção desejada para a direção oposta para então realizar a rotação do nó para a direção desejada.

![Balanceamento duplo para esquerda](rdesq.gif)

![Balanceamento duplo para a direita](rddir.gif)



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

Um exemplo incompleto está disponível em:
[exemplo 5](exemplo5/)

## Estratégia 4

As funções da árvore podem ser iterativas, ao invés de recursivas.
Assim, a manipulação dos nós é feita em uma função com auxílio de laços.
Segue um exemplo da função de inserção:

```C
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
```
Um exemplo incompleto está disponível em:
[exemplo 6](exemplo6/)

_Observação: Algumas otimizações realizadas neste código como, a chamada do método criar nó, pode ser adotada em qualquer das implementações anteriores.

## Atividades

1. Implementar com a *Estratégia 1* os métodos de remover, mínimo, máximo, busca, contagem, listagem em pré, in e pos-ordem.

2. Implementar com a *Estratégia 2* os métodos de remover, mínimo, máximo, busca, contagem, listagem em pré, in e pos-ordem.

3. Implementar com a *Estratégia 3* os métodos de remover, mínimo, máximo, busca, contagem, listagem em pré, in e pos-ordem.

4. Implementar com a *Estratégia 4* os métodos de remover, mínimo, máximo, busca, contagem, listagem em pré, in e pos-ordem.

_Submissão via SIGA-A. Link será aberto em breve._
