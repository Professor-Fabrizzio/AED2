# AED2 - Algoritmos e Estrutura de Dados 2

# Trabalho 1

Neste trabalho serão realizados alguns experimentos com tabelas Hash. As tabelas hash construídas deverão conter funções de:
* Inserção;
* Busca e
* Remoção.

Para isto, está disponibilizado um arquivo texto, no formato csv, com 500 mil linhas.

## Definição do trabalho

Neste trabalho será usado somente as primeiras **10.000** linhas.

O trabalho consistirá das seguintes etapas:

1. Construir um hash ideal (Sem tratamento de colisões) e calcular o total de colisões por posição conforme a seguir:
    * Usar o método da divisão considerando o tamanho padrão da tabela;
    * Usar uma tabela de tamanho baseado em número primo e usar o método da divisão;
    * Usar o método da dobra;
    * Usar o método da multiplicação simples;
    * Usar o método da multiplicação considerand o quadrado da chave.
2. Construir um hash com tratamento de colisões:
    * Usar o método de encadeamento externo em que o 1o registro é considerado na tabela;
    * Usar o método de encadeamento externo em que o nenhum registro é considerado na tabela;
    * Usar o método de zona de colisão.

Para a parte 2 pode ser considerada a função hashing da sua preferência, ou aquela que oferecer a menor taxa de colisões.
Na parte 2 deverá ser feita uma simulação de busca aleatória de um total de 1000 chaves, considerando as 10.000 chaves inseridas e chaves aleatórias não existentes, para ser obter a quantidade média de operações para se obter o registro desejado. Os registros inexistentes, obviamente, não serão encontrados na busca, mas terão seu tempo de busca computado.

## Artefatos

Ao final deste trabalho deverá ser enviado:
* Todos os códigos fontes utilizados. Sugiro usar um programa para cada caso descrito na seção de definição.
* Relatório dos experimentos. Deverá conter:
    * Membros do grupo que desenvolveu o trabalho;
    * Introdução com explicações fundamentadas sobre tabela hash e seus componentes;
    * Descrição dos métodos utilizados;
    * Resultados experimentais;
    * Conclusões ou Considerações finais e
    * Referências.

Será avaliado o código com comentários, clareza e grau de detalhamento do relatório e coerência dos resultados obtidos com experados pelo professor, bem como com as conclusões.

A submissão deverá ser feita via moodle em link a ser disponibilizado em breve. Os grupos poderão ter até **3 integrantes**.

## Instruções

Cada linha do arquivo representa um registro de uma pessoa com os campos a seguir na seguinte ordem:

* Numero da linha
* Address
* id (**Campo chave**)
* Birth Date
* Name
* Email Address
* Phone Number

Para efetuar a leitura do arquivo, deverá ser usadas as funções de abertura (fopen), leitura (fgets) e fechamento (fclose).

Abaixo segue um exemplo de registro e função para processamento das linhas do arquivo texto.

```C
typedef struct _pessoa //144 bytes
{
    int  linha;
    char endereco[50];
    int  chave;
    char datanasc[10];
    char nome[40];
    char email[20];
    char celular[13];
} Pessoa;

Pessoa parseData(char linha[]){

    Pessoa r;
    char *pt;
    pt = strtok (linha, ",");
    r.linha = atoi(pt); // numero da linha
    pt = strtok (NULL, ",");
    strncpy(r.endereco, pt, 50); // endereco
    pt = strtok (NULL, ",");
    r.chave = atoi(pt); // id
    pt = strtok (NULL, ",");
    strncpy(r.datanasc, pt, 10); // data de nascimento
    pt = strtok (NULL, ",");
    strncpy(r.nome, pt, 40); // nome
    pt = strtok (NULL, ",");
    strncpy(r.email, pt, 20); // email
    pt = strtok (NULL, ",");
    strncpy(r.celular, pt, 13); // celular
    return r;
}
```

A princípio, um buffer de 170 caracteres parece suficiente para conter uma linha a ser processada, todavia, isto deverá ser verificado.

Observe que as linhas são quebradas baseado no caractere "," (vírgula). Todavia, esses dados foram gerados por um gerador online, e o campo endereço, em alguns momentos incluiu algumas vírgulas, e portanto, este campo foi delimitado por aspas. Assim, ou o campo endereço deverá ter suas virgulas e aspas removidas manualmente antes do processamento, ou este comportamento deverá ser incluído no seu processamento.

Abaixo segue um exemplo de trecho de código para abrir, ler "todas" as linhas, processa-las e fechar o arquivo:

```C
    FILE *fp; // arquivo de texto
    char linha[MAXCHAR];
    char* filename = "dados-500000-lin.csv";
    Pessoa r;
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return;
    }
    fgets(linha, MAXCHAR, fp); // ignorando a 1a linha
    int i = 0;
    while ((i < QTD) && (fgets(linha, MAXCHAR, fp) != NULL)){
        dados[i].dados = parseData(linha);
        i++;
    }
    fclose(fp);
```

Abaixo segue um exemplo de registro para a tabela hash com encadeamento externo com registro incluso na tabela:

```C
typedef struct _registro //144 bytes
{
    Pessoa pessoa;
    char situacao;
    int proximo;
} Registro;
```

Sugestão, os registros deverão ter um campo situação que indique:

* 0 (null) ou 'L' - para livre;
* 'O' - para ocupado e
* 'D' - para deletado.

As tabelas hash deverão ser construídas em arquivos binários.

Abaixo segue um exemplo de abertura de um arquivo binário:

```C
    FILE* fp;
    int result = access (arquivo, F_OK); // F_OK testa existencia.

    if (result == 0){
    // Se o arquivo existe, abra e leia o header
        fp = fopen(arquivo, "r+b");
        leHeader(v);
    } else {
    // Se o arquivo nao existe, crie-o, defina um header e escreva no arquivo
        fp = fopen(arquivo, "w+b");        
        header = criaHeader();
        gravaHeader(v);
    }
```

Segue uma lista de funções úteis para manpulação de arquivos binários:
* fseek() - Moveo o ponteiro de arquivo para uma quantidade de bytes a partir de uma referência:
    * SEEK_SET - inicio do arquivo;
    * SEEK_CUR - posição corrente e
    * SEEK_END - fim do arquivo.
* fwread() - Le um registro no arquivo
* fwrite() - Escreve um registro no arquivo
* ftell() - Indica o byte atual apontado pelo ponteiro e arquivo
* feof() - Indica fim de arquivo


Abaixo segue um exemplo de como posicionar no arquivo e ler um registro:

```C
    Registro aux;

    fseek(v->fp, INICIO, SEEK_SET);
    int i = fread(&aux, RECSIZE, 1, v->fp))
    if (i != RECSIZE){
        //registro não existe e não foi lido, ou há algum erro
    } else {
        // registro foi lido e está dentro da variável aux
    }

```

Sugestão, quando o arquivo for criado, já crie uma tabela hash para o total de registros a serem armazenados. Defina em seu layout um cabeçalho para te auxiliar a definir quantos registros há na tabela.

## Arquivos texto

Estão sendo disponibilizados 3 arquivos textos, em que cada um tem um formato de delimitador de linhas que poderão ser tratados automaticamente ou não pelo seu compilador C. Assim, observe se o comportamento da leitura linha a linha está correto e se você está usando o arquivo conforme seu Sistema Operacional:

* [dados-500000-lin.csv](dados-500000-lin.csv) - Linux, Delimitador: caracter 13;
* [dados-500000-mac.csv](dados-500000-mac.csv) - MacOS, Delimitador: caracter 10 (Verificar);
* [dados-500000-win.csv](dados-500000-win.csv) - Windows, Delimitador: caracteres 13 e 10 ou 10 e 13 (Verificar).

Mais detalhes poderão ser informados em breve, portanto, mantenha a sua leitura deste documento sempre atualizada.