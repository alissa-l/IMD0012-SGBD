enum Tipo {
    INT,
    CHAR,
    FLOAT,
    DOUBLE
};

typedef struct coluna {
    char nome[20];
    enum Tipo tipo;
} Coluna;