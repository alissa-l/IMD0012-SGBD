#include "common_utils/dependecies.h"

void criar_registro() {
    int novoRegistro = 1;
    while(novoRegistro == 1) {
        ListaTabela listaTabelas = listar_tabelas(true);
        int ind = -1;
        while(ind < 0) {
            char nome[20];
            printf("Em qual tabela você deseja adicionar seu registro? Informe o nome da tabela:\n");
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
        int id = get_ultimo_registro(tab.nome);
        char line[1000];
        char id_str[100];
        sprintf(id_str,"%d",id);
        strcpy(line, id_str);
        strcat(line, ";");
        for(int i = 1; i < tab.qtdColunas; i++) {
            char entrada[100];
            printf("Qual valor deseja colocar na coluna '%s'? ", tab.colunas[i].nome);
            printf("(Informe um valor do tipo %s)\n", tab.colunas[i].nomeTipo);
            scanf("%s", entrada);
            strcat(line, entrada);
            strcat(line, ";");
        }
        escrever_dado(tab.nome, line);
        printf("Dados salvos com sucesso!\n");
        printf("Deseja salvar um novo registro?\n");
        printf("1 - Sim\t\t2- Não\n");
        scanf("%i", &novoRegistro);
    }
    printf("Obrigado!\n\n");
}