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

typedef struct tabela {
    char nome[20];
    int qtdColunas;
    Coluna *colunas;
} Tabela;


typedef struct listaTabelas {
    int qtdTabelas;
    Tabela *tabelas;
} ListaTabela;