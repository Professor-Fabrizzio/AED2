typedef struct no {
  int chave;
  struct no *filho[2]; // 0 - Esquerda; 1 - Direita
} No;

void inicializar(No** arvore);
void inserir(No** a, int chave);
//int remover(No** a, int chave);
int arvoreVazia(No** a);
int menor(No** a);

