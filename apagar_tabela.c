#include "common_utils/dependecies.h"

#define MAX 256

void apagar_tabela() {

    printf("\n\n");

    ListaTabela listaTabelas = listar_tabelas(true);
    int ind = -1;
    while(ind < 0) {
        char nome[20];
        printf("Qual tabela deseja apagar? Informe o nome da tabela:\n");
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

    FILE *listaOriginal, *listaNova;

    char ch;
    int temp = 0;
    listaOriginal = fopen(LIST_TABELAS_ADDR, "r");
    listaNova = fopen("tabelas/temp.pwn", "w");

    if(listaOriginal == NULL) {
        print_vermelho("Erro na abertura do arquivo\n");
    } else {
        ch = getc(listaOriginal);
        while (ch != EOF) {
            if (ch == '\n') {
                temp++;
            }
            if (temp != ind) {
                putc(ch, listaNova);
            }
            ch = getc(listaOriginal);
        }
        fclose(listaOriginal);
        fclose(listaNova);
    }

    remove(LIST_TABELAS_ADDR);
    rename("tabelas/temp.pwn", LIST_TABELAS_ADDR);

    Tabela tabela = listaTabelas.tabelas[ind];
    char nomeTabela[MAX];
    strcpy(nomeTabela, tabela.nome);

    char nomeDiretorio[MAX] = TABELA_DIR;

    strcat(nomeDiretorio, nomeTabela);
    strcat(nomeDiretorio, ".pwn");

    remove(nomeDiretorio);
    print_verde("\n\nTabela apagada com sucesso!\n\n");
}