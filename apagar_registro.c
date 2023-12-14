#include "common_utils/dependecies.h"

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
    printf("%i\n", qtdRegistros);
    if(qtdRegistros > 0) {
        listar_dados_tabela(tab);
        int id = -1;
        while(id < 0 && id >= qtdRegistros) {
            printf("Informe a chave primária (id) do registro que você deseja apagar:\n");
            scanf("%i", &id);
            if(id < 0 && id >= qtdRegistros) {
                print_vermelho("Por favor, informe uma chave primária (id) válida!\n");
            }
        }

        /**
        
            APAGAR REGISTRO DO ID FORNECIDO!

        */



    } else {
        print_vermelho("Não há dados cadastrados nessa tabela!\n");
    }


}