enum Tipo {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    STRING
};

typedef struct coluna {
    char nome[20];
    enum Tipo tipo;
    char nomeTipo[20];
} Coluna;