#include "coluna.h"
#include <dirent.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

void erro_ao_abrir_arquivo() {
    printf("\033[0;31m"); // Setar a cor do output pra vermelho
    printf("\nErro ao abrir o arquivo!\n");
    printf("Erro: %d\n", errno);
    printf("Erro: %s\n", strerror(errno));
    printf("\033[0m"); // Resetar a cor do output
}

void print_vermelho(char string[]) {
    printf("\033[0;31m"); // Setar a cor do output pra vermelho
    printf("\n%s\n", string);
    printf("\033[0m"); // Resetar a cor do output
}

void print_verde(char string[]) {
    printf("\033[0;32m"); // Setar a cor do output pra verde
    printf("%s", string);
    printf("\033[0m"); // Resetar a cor do output
}

bool diretorio_existe(char diretorio[]) {
    DIR *dir = opendir(diretorio);

    if (dir) {
        closedir(dir);
        return true;
    } else if (ENOENT == errno) {
        return false;
    }
}

bool tabela_existe(char diretorio[], char nomeTabela[]) {

    FILE *listTabelas = fopen("tabelas/listTabelas.pwn", "r");

    if (listTabelas == NULL) {
        erro_ao_abrir_arquivo();
    }
}

void escrever_tabela(Coluna colunas[], int qtdColunas, char nomeArquivo[]) {

    // Mapear titulos
    char listTipos[5][20] = {"CHAR", "INT", "FLOAT", "DOUBLE", "STRING"};

    // Nome do diretorio tabelas
    char nomeDiretorio[200] = "tabelas/";

    // Se o diretorio não existe, criar
    if (diretorio_existe(nomeDiretorio) == false) {
        mkdir("tabelas", 0777);
    }

    // Variaveis de arquivo e lista de tabelas existentes
    FILE *arquivo, *listTabela;

    // Adicionar a tabela na lista de tabelas
    listTabela = fopen("tabelas/listTabelas.pwn", "a"); // Abrir o arquivo
    fprintf(listTabela, "%i %s\n", qtdColunas,
            nomeArquivo); // Escrever no arquivo
    fclose(listTabela);   // Fechar o arquivo

    // Criar nome do arquivo da tabela
    strcat(nomeArquivo, ".pwn"); // Adicionar a extensão .pwn
    strcat(nomeDiretorio,
           nomeArquivo); // Adicionar nome do arquivo ao nome do diretorio

    // Abrir arquivo da tabela
    printf("nomeDiretorio: %s\n", nomeDiretorio);
    arquivo = fopen(nomeDiretorio, "w");

    if (arquivo != NULL) {
        printf("\033[0;32m"); // Setar a cor do output pra verde
        printf("\nArquivo criado com sucesso!\n\n");
        printf("\033[0m"); // Resetar a cor do output
    } else {
        erro_ao_abrir_arquivo();
    }

    // Escrever colunas no arquivo
    for (int i = 0; i < qtdColunas; i++) {
        fprintf(arquivo, "%s.%s;", colunas[i].nome, listTipos[colunas[i].tipo]);
    }

    fclose(arquivo); // Fechar arquivo
}

Coluna *criar_colunas(Coluna *colunas, int qtdColunas) {
    for (int i = 1; i < qtdColunas; i++) {

        int validacao = 0;

        while (validacao == 0) {

            printf("Digite o nome da coluna %d: ", i);
            scanf("%s", colunas[i].nome);

            if (colunas[i].nome[0] == '\0') {

                print_vermelho("Nome da coluna não pode ser vazio!");

            } else if (colunas[i].nome[0] == ' ') {

                print_vermelho("Nome da coluna não pode começar com espaço!");
            }

            for (int j = 0; j < i; j++) {
                if (strcmp(colunas[j].nome, colunas[i].nome) == 0) {

                    print_vermelho("Uma coluna com esse nome já existe!");
                    break;

                } else {

                    validacao = 1;
                }
            }

            printf("\nQual será o tipo da coluna %d: %s\n", i, colunas[i].nome);
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
}

void criar_tabela() {
    // Criar o nome da tabela
    char listTipos[5][20] = {"CHAR", "INT", "FLOAT", "DOUBLE", "STRING"};

    int validacao = 0;
    char nomeArquivo[20];

    while (validacao == 0) {
        printf("\nDigite o nome da tabela: ");

        scanf("%s", nomeArquivo);

        if (tabela_existe("tabelas/", nomeArquivo) == true) {

            if (nomeArquivo[0] == '\0') {
                print_vermelho("Nome da tabela não pode ser vazio!");
                break;
            } else if (nomeArquivo[0] == ' ') {
                print_vermelho("Nome da tabela não pode começar com espaço!");
                break;
            } else {
                print_vermelho("Uma tabela com esse nome já existe!");
                break;
            }
            validacao = 1;
        }

        // Criar a coluna primaria
        printf("Digite o nome da coluna primaria: ");
        char colunaId[20];
        scanf("%s", colunaId);

        // Quantas colunas
        int qtdColunas;
        printf("Quantas colunas deseja criar? ");
        scanf("%d", &qtdColunas);

        // Adicionando a colunaId na contagem
        qtdColunas++;

        // Array pra guardar as colunas
        Coluna colunas[qtdColunas];

        // Inicializar a coluna primaria
        strcpy(colunas[0].nome, colunaId);

        // Obrigatoriamente a coluna 0 é um inteiro
        colunas[0].tipo = INT;

        Coluna *colunasPtr = criar_colunas(colunas, qtdColunas);

        // Imprimir nomes e tipos das colunas
        printf("\nNomes e tipos das colunas:\n");
        for (int i = 0; i < qtdColunas; i++) {
            if (colunasPtr[i].nome[0] == '\0') {
                break;
            } else {
                printf("Coluna %d: %s (Tipo: %s)\n", i + 1, colunasPtr[i].nome,
                       listTipos[colunasPtr[i].tipo]);
            }
        }

        escrever_tabela(colunasPtr, qtdColunas, nomeArquivo);
    }
}