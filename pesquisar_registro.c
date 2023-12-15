#include "common_utils/dependecies.h"

void pesquisar_registro() {
    ListaTabela listaTabelas = listar_tabelas(true);
    if(listaTabelas.qtdTabelas > 0) {
        int indTbl = -1;
        int indCln = -1;
        while(indTbl < 0) {
            char nome[20];
            printf("Em qual tabela você deseja realizar a pesquisa?\n");
            scanf("%s", nome);
            for(int i = 0; i < listaTabelas.qtdTabelas; i++) {
                if(strcmp(listaTabelas.tabelas[i].nome, nome) == 0) {
                    indTbl = i;
                    break;
                }
            }

            if(indTbl < 0) {
                print_vermelho("Por favor, digite um nome de tabela válido!");
            }
        }
        printf("\n");
        Tabela tabela = listaTabelas.tabelas[indTbl];
        while(indCln < 0) {
            char nome[20];
            printf("Em qual coluna você deseja pesquisar?\n");
            for(int i = 0; i < tabela.qtdColunas; i++) {
                printf("Coluna %i: %s (Tipo: %s)", i+1, tabela.colunas[i].nome, tabela.colunas[i].nomeTipo);
                if(i % 2 == 0) {
                    printf("\t\t");
                } else {
                    printf("\n");
                }
            }
            printf("\n\n");
            scanf("%s", nome);
            for(int i = 0; i < tabela.qtdColunas; i++) {
                if(strcmp(tabela.colunas[i].nome, nome) == 0) {
                    indCln = i;
                    break;
                }
            }

            if(indCln < 0) {
                print_vermelho("Por favor, digite um nome de coluna válido!");
            }
        }
        Coluna col = tabela.colunas[indCln];
        printf("\n");
        
        char valorPesquisa[1000];
        printf("O que você deseja pesquisar?\n");
        scanf("%s", valorPesquisa);
        
        printf("\nO que a busca deve informar?\n");
        printf("1 - Valores maior que o valor informado\t\t 2 - Valores maior ou igual que o valor informado\n");
        printf("3 - Valores menor que o valor informado\t\t 4 - Valores menor ou igual que o valor informado\n");
        printf("5 - Valores igual o valor informado");
        if(strcmp(col.nomeTipo, "STRING") == 0) {
            printf("\t\t 6 - Valores próximo ao valor informado\n");
        } else {
            printf("\n");
        }

        int opcao;

        scanf("%d", &opcao);

        printf("\n\n");
        for(int i = 0; i < tabela.qtdColunas; i++) {
            if (i == tabela.qtdColunas - 1) {
                printf("%s\n", tabela.colunas[i].nome);
            } else {
                printf("%s\t\t", tabela.colunas[i].nome);
            }   
        }

        switch (opcao)
        {
        case 1:
            pesquisa_maior_que(valorPesquisa, tabela, col, indCln);
            break;
        case 2:
            pesquisa_maior_ou_igual_a(valorPesquisa, tabela, col, indCln);
            break;
        case 3:
            pesquisa_menor_que(valorPesquisa, tabela, col, indCln);
            break;
        case 4:
            pesquisa_menor_ou_igual_a(valorPesquisa, tabela, col, indCln);
            break;
        case 5:
            pesquisa_igual_a(valorPesquisa, tabela, col, indCln);
            break;
        case 6:
            pesquisa_proxima(valorPesquisa, tabela, col, indCln);
        default:
            break;
        }

        printf("\n\n\n\n");
    }

}