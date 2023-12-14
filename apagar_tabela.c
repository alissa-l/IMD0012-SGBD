#include "common_utils/dependecies.h"

#define MAX 256

void apagar_tabela() {

    printf("\n\n");

    ListaTabela listaTabelas = listar_tabelas(true);

    printf("Qual tabela deseja apagar? (Digite o índice)");
    int index;
    scanf("%d", &index);

    FILE *listaOriginal, *listaNova;

    char ch;
    int temp = 0;
    listaOriginal = fopen(LIST_TABELAS_ADDR, "r");
    listaNova = fopen("tabelas/temp.pwn", "w");

    while (ch != EOF) {
        ch = getc(listaOriginal);

        if (ch == '\n') {
            temp++;
        }

        if (temp != index - 1) {
            printf("%c", ch);
            putc(ch, listaNova);
        }
    }

    fclose(listaNova);
    fclose(listaOriginal);
    
    

}