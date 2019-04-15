
typedef struct no No;

typedef struct arvore{

  No* raiz;

} Arvore;

void inicializar(Arvore* a);
void inserir(Arvore* a, int chave);
int arvoreVazia(Arvore a);
int menor(Arvore a);

