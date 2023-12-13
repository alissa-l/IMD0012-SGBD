#include "common_utils/dependecies.h"

void criar_registro() {
    char listTipos[5][20] = {"CHAR", "INT", "FLOAT", "DOUBLE", "STRING"};
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

    for(int i = 1; i < tab.qtdColunas; i++) {
        printf("Qual valor deseja colocar na coluna %s?\n", tab.colunas[i].nome);


    }


    printf("\n\n");
    
    /*

    1. perguntar o dado, coluna por coluna
    2. coletar as respostas
    3. escrever no arquivo
    4. exibir o que foi salvo
    5. perguntar se deseja adicionar mais um registro
    
    */
}