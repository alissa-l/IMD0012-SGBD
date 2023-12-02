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
} Coluna;