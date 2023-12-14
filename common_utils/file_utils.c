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

Tipo setar_tipo(char *tipo) {
    Tipo tipo_enum;
    if(strcmp(tipo, "CHAR") == 0) {
        tipo_enum = CHAR;
    } else if(strcmp(tipo, "INT") == 0) {
        tipo_enum = INT;
    } else if(strcmp(tipo, "FLOAT") == 0) {
        tipo_enum = FLOAT;
    } else if(strcmp(tipo, "DOUBLE") == 0) {
        tipo_enum = DOUBLE;
    } else if(strcmp(tipo, "STRING") == 0) {
        tipo_enum = STRING;
    }
    return tipo_enum;
}


Tabela mapear_colunas(Tabela tabela) {
    char nomeDiretorio[200] = "tabelas/";
    int c = 0;
    char* pedaco;
    strcat(nomeDiretorio, tabela.nome);
    strcat(nomeDiretorio, ".pwn");
    FILE *arquivo = fopen(nomeDiretorio, "r" );
    char line[1000];
    if(arquivo == NULL) {
        print_vermelho("Erro na abertura do arquivo\n");
    } else {   
        fscanf(arquivo, "%s", line);
    }
    tabela.colunas = malloc(sizeof(Coluna) * tabela.qtdColunas);
    pedaco = strtok(line, ".");
    while(pedaco != NULL){
        char nome[20], tipo[20];
        strcpy(nome, pedaco);
        pedaco = strtok(NULL, ";");
        strcpy(tipo, pedaco);
        pedaco = strtok(NULL, ".");
        strcpy(tabela.colunas[c].nome, nome);
        strcpy(tabela.colunas[c].nomeTipo, tipo);
        tabela.colunas[c].tipo = setar_tipo(tipo);
        c++;
    }
    fclose(arquivo);
    return tabela;
}

ListaTabela listar_tabelas(bool imprimir) {
    ListaTabela listaTabelas;
    int qtdTabelas = 0;
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
                tabelas = realloc(tabelas, sizeof(Tabela) * (qtdTabelas+1));
                tabelas[qtdTabelas].qtdColunas = qtd;
                strcpy(tabelas[qtdTabelas].nome, nome);
                qtdTabelas++;
            }
        }
    }

    fclose(arquivo); 
    listaTabelas.qtdTabelas = qtdTabelas;
    listaTabelas.tabelas = malloc(sizeof(Tabela) * qtdTabelas);
    for(int i = 0; i < qtdTabelas; i++) {
        Tabela tab = mapear_colunas(tabelas[i]);
        listaTabelas.tabelas[i] = tab;
    }
    
    free(tabelas);

    if(imprimir == true) {
        printf("Estas são as tabelas existentes:\n");
        for(int i = 0; i < listaTabelas.qtdTabelas; i++) {
            printf("%i - Tabela: %s", i+1, listaTabelas.tabelas[i].nome);
            if(i % 2 == 1) { 
                printf("\n"); 
            } else { 
                printf("\t\t"); 
            }
        }
        printf("\n\n");
    }

    return listaTabelas;
    
}

void escrever_dado(char *nome, char* dados) {
    char nomeDiretorio[200] = "tabelas/";
    strcat(nomeDiretorio, nome);
    strcat(nomeDiretorio, ".pwn");
    FILE *arquivo = fopen(nomeDiretorio, "a");
    if(arquivo == NULL) {
        print_vermelho("Erro na abertura do arquivo: ");
        printf("%s\n", nomeDiretorio);
    } else {
        fprintf(arquivo, "%s\n", dados);
    }
    fclose(arquivo);
}

int get_ultimo_registro(char *nomeTabela) {
    int qtd = -1;
    char nomeDiretorio[200] = "tabelas/";
    strcat(nomeDiretorio, nomeTabela);
    strcat(nomeDiretorio, ".pwn");
    FILE *arquivo = fopen(nomeDiretorio, "r" );
    if(arquivo == NULL) {
        print_vermelho("Erro na abertura do arquivo\n");
    } else {
        while(feof(arquivo) == 0) {
            char line[100];
            fscanf(arquivo, "%s", line);
            qtd++;
        }
    }
    qtd--;
    return qtd;
}