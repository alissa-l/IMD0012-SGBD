#include "common_utils/dependecies.h"

int main() {
    int opcao = 0;
    while (opcao != 8) {
        printf("Qual operação deseja realizar?\n");
        printf("1 - Criar tabela\t\t2 - Listar tabelas\n");
        printf("3 - Criar novo registro\t\t4 - Listar dados de uma tabela\n");
        printf("5 - Pesquisar registro\t\t6 - Apagar registro\n");
        printf("7 - Apagar tabela\t\t8 - Sair\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
                criar_tabela(); 
                break;
            case 2:
                listar_tabelas(true);
                break;
            case 3:
                criar_registro();
                break;
            case 4:
                listar_dados();
                break;
            case 5:
                //pesquisar_registro();
                break;
            case 6:
                //apagar_registro();
                break;
            case 7:
                apagar_tabela();
                break;
            case 8:
                break;
            default:
                break;
        }
    }

    return 0;
}