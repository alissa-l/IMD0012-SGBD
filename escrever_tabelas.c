#include <stdio.h>
#include "coluna.h"
#include <string.h>
#include <errno.h>

void escrever_tabela(Coluna colunas[], int qtdColunas, char nomeArquivo[]) {
    char listTipos[5][20] = {"CHAR", "INT", "FLOAT", "DOUBLE", "STRING"};
    
    FILE *arquivo, *listTabela;
    
    listTabela = fopen("tabelas/listTabelas.pwn", "a");
    fprintf(listTabela, "%i %s\n", qtdColunas, nomeArquivo);

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

    for(int i = 0; i < qtdColunas; i++) {
        fprintf(arquivo, "%s.%s;", colunas[i].nome, listTipos[colunas[i].tipo]);
    }

    fclose(arquivo);
}