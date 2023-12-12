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

int ler_arquivo(Tabela *tabelas) {
    int c = 0;
    FILE *arquivo = fopen("tabelas/listTabelas.pwn", "r" );
    if(arquivo == NULL) {
        print_vermelho("Erro na abertura do arquivo\n");
    } else {
        while(feof(arquivo) == 0) {
            int qtd = 0;
            char nome[20];
            fscanf(arquivo, "%i %s\n", &qtd, nome);
            printf("%i - %s\n", qtd, nome);
            nome[strlen(nome)] = '\0';
            if(qtd > 0) {
                tabelas = realloc(tabelas, sizeof(Tabela) * (c+1));
                tabelas[c].qtdColunas = qtd;
                strcpy(tabelas[c].nome, nome);
                c++;
            }
        }
     }
    fclose(arquivo); 

    return c;
}