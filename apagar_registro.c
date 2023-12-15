#include "common_utils/dependecies.h"

void apagar_registro_tabela(Tabela tab, int id) {
    FILE *arquivoOriginal, *arquivoNovo;

    char nomeDiretorio[200] = "tabelas/";
    strcat(nomeDiretorio, tab.nome);
    strcat(nomeDiretorio, ".pwn");
    char ch;
    int temp = 0;
    arquivoOriginal = fopen(nomeDiretorio, "r");
    arquivoNovo = fopen("tabelas/temp.pwn", "w");

    if(arquivoOriginal == NULL) {
        print_vermelho("Erro na abertura do arquivo\n");
    } else {
        char id_str[100];
        sprintf(id_str,"%d",id);
        while(feof(arquivoOriginal) == 0) {
            char line[1000], dado[1000];
            fscanf(arquivoOriginal, "%s\n", line);
            strcpy(dado, line);
            char *pedaco = strtok(line, ";");
            if(strcmp(pedaco, id_str) != 0) {
                fprintf(arquivoNovo, "%s\n", dado);
            }
        }
        fclose(arquivoOriginal);
        fclose(arquivoNovo);
    }
    remove(nomeDiretorio);
    rename("tabelas/temp.pwn", nomeDiretorio);
    print_verde("Registro apagado com sucesso!\n\n");
}

void apagar_registro() {
    ListaTabela listaTabelas = listar_tabelas(true);
    int ind = -1;
    while(ind < 0) {
        char nome[20];
        printf("De qual tabela você deseja apagar o registro? Informe o nome da tabela:\n");
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
    printf("%s - %i\n", tab.nome, tab.qtdColunas);
    int qtdRegistros = get_ultimo_registro(tab.nome);
    if(qtdRegistros > 0) {
        listar_dados_tabela(tab);
        int id = -1;
        while(id < 0 || id >= qtdRegistros) {
            printf("Informe a chave primária (id) do registro que você deseja apagar:\n");
            scanf("%i", &id);
            if(id < 0 && id >= qtdRegistros) {
                print_vermelho("Por favor, informe uma chave primária (id) válida!\n");
            }
        }

        apagar_registro_tabela(tab, id);
       
    } else {
        print_vermelho("Não há dados cadastrados nessa tabela!\n");
    }

}