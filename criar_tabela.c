#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "escrever_tabelas.h"

Coluna* criar_colunas(Coluna colunas[], int qtdColunas) {
    for (int i = 0; i < qtdColunas; i++) {
        printf("Digite o nome da coluna %d: ", i + 1);
        scanf("%s", colunas[i].nome);

        printf("Qual o tipo da coluna %d: \n", i + 1);
        printf("1 - CHAR\t2 - INT\n3 - FLOAT\t4 - DOUBLE\n5 - STRING\n");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao) {

        case 1:
            colunas[i].tipo = CHAR;
            break;
        case 2:
            colunas[i].tipo = INT;
            break;
        case 3:
            colunas[i].tipo = FLOAT;
            break;
        case 4:
            colunas[i].tipo = DOUBLE;
            break;
        case 5:
            colunas[i].tipo = STRING;
            break;
        }
    }

    return colunas;
}

void criar_tabela() {

    // Criar o nome da tabela
    printf("Digite o nome da tabela: ");

    char nomeArquivo[20];
    scanf("%s", nomeArquivo);

    // Criar a coluna primaria
    printf("Digite o nome da coluna primaria: ");
    char colunaId[20];
    scanf("%s", colunaId);


    // Quantas colunas
    int qtdColunas;
    printf("Quantas colunas deseja criar? ");
    scanf("%d", qtdColunas);

    // Array pra guardar as colunas
    Coluna colunas[qtdColunas];

    // Inicializar a coluna primaria
    strcpy(colunas[0].nome, colunaId);

    // Obrigatoriamente a coluna 0 é um inteiro
    colunas[0].tipo = INT;

    Coluna* colunasPtr = criar_colunas(colunas, qtdColunas);


    // Imprimir nomes e tipos das colunas
    printf("Nomes e tipos das colunas:\n");
    for (int i = 0; i < 10; i++) {
        if (colunas[i].nome[0] == '\0') {
            break;
        } else {
            printf("Coluna %d: %s (Tipo: %d)\n", i + 1, colunas[i].nome,
                   colunas[i].tipo);
        }
    }

    escrever_tabela(colunasPtr, nomeArquivo);

}