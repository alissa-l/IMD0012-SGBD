#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <coluna.h>

FILE *arquivo;

void criar_tabela() {

    //Criar o nome da tabela
    printf("Digite o nome da tabela: ");

    char nomeArquivo[20];
    scanf("%s", &nomeArquivo);

    strcat(nomeArquivo, ".pwn");

    Coluna colunas[10];

    printf("Digite o nome da coluna primaria: ");
    char colunaId[20];
    scanf("%s", &colunaId);

    strcpy(colunas[0].nome, colunaId);
    colunas[0].tipo = INT;

    for (int i = 0; i < 10; i++)
    {
        printf("Digite o nome da coluna %d: ", i + 1);
        scanf("%s", &colunas[i]);


        
        printf("Qual o tipo da coluna %d: ", i + 1);
        scanf("%d", &colunas[i].tipo);

    }

    arquivo = fopen(nomeArquivo, "w");

    if (arquivo != NULL)
    {
        printf("Arquivo criado com sucesso!\n");
    }
    else
    {
        printf("Erro ao abrir o arquivo!\n");
        printf("Erro: %d\n", errno);
        printf("Erro: %s\n", strerror(errno));
    }


    char nome[] = "Teste de escrita em arquivo";

    fprintf(arquivo, "%s", nome);

    fclose(arquivo);
}