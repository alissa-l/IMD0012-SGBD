#include <stdio.h>
#include "coluna.h"
#include <string.h>
#include <errno.h>

void escrever_tabela(Coluna colunas[], int qtdColunas, char nomeArquivo[]) {
    char listTipos[5][20] = {"CHAR", "INT", "FLOAT", "DOUBLE", "STRING"};
    FILE *arquivo;
    char nomeDiretorio[200] = "tabelas/";

    strcat(nomeArquivo, ".pwn");
    strcat(nomeDiretorio, nomeArquivo);

    printf("nomeDiretorio: %s\n", nomeDiretorio);
    arquivo = fopen(nomeDiretorio, "w");

    if (arquivo != NULL) {
        printf("Arquivo criado com sucesso!\n");
    } else {
        printf("Erro ao abrir o arquivo!\n");
        printf("Erro: %d\n", errno);
        printf("Erro: %s\n", strerror(errno));
    }

    char linha[200];
    char valor[200];
    for(int i = 0; i < qtdColunas; i++) {
        strcat(valor, " ");
        strcat(valor, colunas[i].nome);
        strcat(valor, ".");
        strcat(valor, listTipos[colunas[i].tipo]);
        strcat(valor, ";");
        strcat(linha, valor);
        printf("%s\n", linha);
    }

    fprintf(arquivo, "%s", linha);

    fclose(arquivo);
}