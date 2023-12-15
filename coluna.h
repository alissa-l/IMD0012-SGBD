typedef enum tipo {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    STRING
} Tipo;

typedef struct coluna {
    char nome[20];
    Tipo tipo;
    char nomeTipo[20];
} Coluna;

typedef struct valorColuna {
    char coluna[20];
    char valor[200];
} ValorColuna;

typedef struct linha {
   ValorColuna *valoresColuna;
} Linha;

typedef struct tabela {
    char nome[20];
    int qtdColunas;
    int qtdLinhas;
    Coluna *colunas;
    Linha *linhas;
} Tabela;


typedef struct listaTabelas {
    int qtdTabelas;
    Tabela *tabelas;
} ListaTabela;
