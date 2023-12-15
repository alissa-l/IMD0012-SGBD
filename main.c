#include "common_utils/dependecies.h"

int main() {
    int opcao = 0;
    while(opcao < 1 || opcao > 8) {

        printf("Qual operação deseja realizar?\n");
        printf("1 - Criar tabela\t\t2 - Listar tabelas\n");
        printf("3 - Criar novo registro\t\t4 - Listar dados de uma tabela\n");            
        printf("5 - Pesquisar registro\t\t6 - Apagar registro\n");
        printf("7 - Apagar tabela\t\t8 - Sair\n");
        scanf("%d", &opcao);

        if(opcao >= 1 && opcao <= 8) {
            switch (opcao) {
                case 1: 
                    print_verde("Você escolheu a opção: 1 - Criar tabela!\n");
                    criar_tabela(); 
                    break;
                case 2:
                    print_verde("Você escolheu a opção: 2 - Listar tabelas!\n");
                    listar_tabelas(true);
                    break;
                case 3:
                    print_verde("Você escolheu a opção: 3 - Criar novo registro!\n");
                    criar_registro();
                    break;
                case 4:
                    print_verde("Você escolheu a opção: 4 - Listar dados de uma tabela!\n");
                    listar_dados();
                    break;
                case 5:
                    print_verde("Você escolheu a opção: 5 - Pesquisar registro!\n");
                    pesquisar_registro();
                    break;
                case 6:
                    print_verde("Você escolheu a opção: 6 - Apagar registro!\n");
                    apagar_registro();
                    break;
                case 7:
                    print_verde("Você escolheu a opção: 7 - Apagar rabela!\n");
                    apagar_tabela();
                    break;
                case 8:
                    print_vermelho("Você escolheu a opção: 8 - Sair!\n");
                    break;
                default:
                    break;
            }
        
        } else {
            print_vermelho("Escolha uma opção válida!\n");
        }
    } 

    return 0;
}