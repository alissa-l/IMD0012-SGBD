#include <stdio.h>
#include "coluna.h"
#include <string.h>
#include <errno.h>

void escrever_tabela(Coluna colunas[], char nomeArquivo[]) {

    FILE *arquivo;
    char nomeDiretorio[40] = "bin/tabelas/";

    strcat(nomeArquivo, ".pwn");
    strcat(nomeDiretorio, nomeArquivo);

    arquivo = fopen(nomeDiretorio, "w");

    if (arquivo != NULL) {
        printf("Arquivo criado com sucesso!\n");
    } else {
        printf("Erro ao abrir o arquivo!\n");
        printf("Erro: %d\n", errno);
        printf("Erro: %s\n", strerror(errno));
    }

    char nome[] = "Teste de escrita em arquivo";

    fprintf(arquivo, "%s", nome);

    fclose(arquivo);
}