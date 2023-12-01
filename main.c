#include <stdio.h>
#include "criar_tabela.h"

int main() {

    printf("Qual operação deseja realizar?\n");
    printf("1 - Criar tabela\t\t2 - Listar tabelas\n");
    printf("3 - Criar novo registro\t\t4 - Listar dados de uma tabela\n");
    printf("5 - Pesquisar registro\t\t6 - Apagar registro\n");
    printf("7 - Apagar tabela\t\t8 - Sair\n");

    int opcao;
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        criar_tabela();
        break;
    case 2:
        break;
    
    default:
        break;
    }

    return 0;
}