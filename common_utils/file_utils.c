#include "common_utils/dependecies.h"

bool tabela_existe(char nomeTabela[]) {

    char filePath[200];
    strcpy(filePath, TABELA_DIR);
    strcat(filePath, LIST_TABELAS);
    FILE *listTabelas = fopen(filePath, "r");

    char line[1000]; // Buffer pra guardar todas as linhas

    if (listTabelas == NULL) {
        print_vermelho("Erro ao abrir o arquivo de listagem de tabelas.");
        return false;
    }

    while (fgets(line, sizeof(line), listTabelas)) {
        if (strstr(line, nomeTabela) != NULL) {
            fclose(listTabelas);
            return true; // Achou a tabela
        }
    }

    fclose(listTabelas);
    return false; // nomeTabela not found in the file
    }

bool lista_existe() {

    char filePath[200];
    strcpy(filePath, TABELA_DIR);
    strcat(filePath, LIST_TABELAS);

    FILE *listTabelas = fopen(filePath, "r");

    if (listTabelas == NULL) {
        return false;
    }

    fclose(listTabelas);
    return true;
}

void criar_lista() {
    char filePath[200];
    strcpy(filePath, TABELA_DIR);
    strcat(filePath, LIST_TABELAS);

    FILE *listTabelas = fopen(filePath, "w");

    fclose(listTabelas);
}

Tabela* ler_arquivo_tabelas(int *qtdTabelas) {
    int numeroTabelas = 0;
    Tabela *tabelas = malloc(sizeof(Tabela) * 1);
    FILE *arquivo = fopen("tabelas/listTabelas.pwn", "r" );
    if(arquivo == NULL) {
        print_vermelho("Erro na abertura do arquivo\n");
    } else {
        while(feof(arquivo) == 0) {
            int qtd = 0;
            char nome[20];
            fscanf(arquivo, "%i %s\n", &qtd, nome);
            nome[strlen(nome)] = '\0';
            if(qtd > 0) {
                tabelas = realloc(tabelas, sizeof(Tabela) * (numeroTabelas+1));
                tabelas[numeroTabelas].qtdColunas = qtd;
                strcpy(tabelas[numeroTabelas].nome, nome);
                numeroTabelas++;
            }
        }
    }
    printf("%i - %i\n", *qtdTabelas, numeroTabelas);
    qtdTabelas = &numeroTabelas;
    printf("%i - %i\n", *qtdTabelas, numeroTabelas);
    fclose(arquivo); 
    return tabelas;
}

void listar_tabelas() {
    Tabela *tabelas;
    int qtd = 0;
    tabelas = ler_arquivo_tabelas(&qtd);
    printf("%i\n", qtd);
    printf("Estas são as tabelas existentes:\n");
    for(int i = 0; i < qtd; i++) {
        printf("%i - Tabela: %s", i+1, tabelas[i].nome);
        if(i % 2 == 1) { 
            printf("\n"); 
        } else { 
            printf("\t\t"); 
        }
    }
    printf("\n");
}