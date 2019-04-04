typedef struct no{
  int valor;
  struct no* proximo;
} No;

typedef struct pilha{
  No* topo;
  int quantidade;
} Pilha;

int pilhaVazia(Pilha p);
int pilhaCheia(Pilha p);
void inicializaPilha(Pilha* p);
void inserir(Pilha* p, int valor);
int remover(Pilha* p);
int verTopo(Pilha p);
