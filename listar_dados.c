#include "common_utils/dependecies.h"

void listar_dados_tabela(Tabela tab) {
    printf("\n");
    for(int i = 0; i < tab.qtdColunas; i++) {
        printf("%-*s", 20, tab.colunas[i].nome);
    }
    printf("\n");
    int c = 0;
    char nomeDiretorio[200] = "tabelas/";
    strcat(nomeDiretorio, tab.nome);
    strcat(nomeDiretorio, ".pwn");
    FILE *arquivo = fopen(nomeDiretorio, "r");
    if(arquivo == NULL) {
        print_vermelho("Erro na abertura do arquivo\n");
    } else {
        while(feof(arquivo) == 0) {
            c++;
            char line[1000];
            fscanf(arquivo, "%s\n", line);
            if(c > 1) {
                char *pedaco;
                pedaco = strtok(line, ";");
                while(pedaco != NULL){
                    printf("%-*s", 20, pedaco);
                    pedaco = strtok(NULL, ";");
                }
                printf("\n");
            }
        }
        printf("\n\n");
        fclose(arquivo); 
    }
}

void listar_dados() {
    ListaTabela listaTabelas = listar_tabelas(true);

    int ind = -1;
    while(ind < 0) {
        char nome[20];
        printf("De qual tabela você deseja listar os dados? Informe o nome da tabela:\n");
        scanf("%s", nome);

        for(int i = 0; i < listaTabelas.qtdTabelas; i++) {
            if(strcmp(listaTabelas.tabelas[i].nome, nome) == 0) {
                ind = i;
                break;
            }
        }

        if(ind < 0) {
            print_vermelho("Por favor, digite um nome de tabela válido!");
        }
    }
    
    Tabela tab = listaTabelas.tabelas[ind];

    int qtdRegistros = get_ultimo_registro(tab.nome);
    if(qtdRegistros > 0) {
        listar_dados_tabela(tab);
    } else {
        print_vermelho("Não há dados cadastrados nessa tabela!\n");
    }

    
}