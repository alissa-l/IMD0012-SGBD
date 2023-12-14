#include "common_utils/dependecies.h"

void criar_registro() {
    int novoRegistro = 1;
    while(novoRegistro == 1) {
        int opcao = 0;
        int validacao = 0;
        Tabela tab;
        printf("\nEm qual você deseja adicionar o seu registro?\n");
        ListaTabela listaTabelas = listar_tabelas(true);
        while(validacao == 0) {
            scanf("%i", &opcao);
            if(opcao > 0 && opcao <= listaTabelas.qtdTabelas) {
                validacao = 1;
                tab = listaTabelas.tabelas[opcao-1];
                printf("Você escolheu a tabela: '%s' que tem %i colunas\n", tab.nome, tab.qtdColunas);
            } else {
                print_vermelho("Por favor, escolha uma opção válida!");
            }
        }
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