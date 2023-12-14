#include "common_utils/dependecies.h"

#define MAX 256

void apagar_tabela() {

    printf("\n\n");

    ListaTabela listaTabelas = listar_tabelas(true);

    printf("Qual tabela deseja apagar? (Digite o índice):\n");
    int index;
    scanf("%d", &index);

    FILE *listaOriginal, *listaNova;

    char ch;
    int temp = 0;
    listaOriginal = fopen(LIST_TABELAS_ADDR, "r");
    listaNova = fopen("tabelas/temp.pwn", "w");

    ch = getc(listaOriginal);
    while (ch != EOF) {

        if (ch == '\n') {
            temp++;
        }

        if (temp != index - 1) {
            putc(ch, listaNova);
        }

        ch = getc(listaOriginal);


    }

    fclose(listaNova);
    fclose(listaOriginal);
    
    remove(LIST_TABELAS_ADDR);
    rename("tabelas/temp.pwn", LIST_TABELAS_ADDR);

    Tabela tabela = listaTabelas.tabelas[index - 1];
    char nomeTabela[MAX];
    strcpy(nomeTabela, tabela.nome);


    char nomeDiretorio[MAX] = TABELA_DIR;

    strcat(nomeDiretorio, nomeTabela);
    strcat(nomeDiretorio, ".pwn");

    remove(nomeDiretorio);

    print_verde("\n\nTabela apagada com sucesso!\n\n");
}