#include "common_utils/dependecies.h"

void imprimir_tabelas(int qtd, Tabela *tabelas) {
    for(int i = 0; i < qtd; i++) {
        printf("Tabela: %s", tabelas[i].nome);
        if(i % 2 == 1) { 
            printf("\n"); 
        } else { 
            printf("\t\t"); 
        }
    }
}

void criar_registro() {
    char listTipos[5][20] = {"CHAR", "INT", "FLOAT", "DOUBLE", "STRING"};
    Tabela *tabelas = (Tabela*) malloc(sizeof(Tabela));
    printf("Estas são as tabelas disponíveis:\n");
    
    int c = ler_arquivo(tabelas);
    imprimir_tabelas(c, tabelas);
    

    // printf("Em qual você deseja adicionar o seu registro?\n");

    /*
    
    1. receber a tabela
    2. perguntar o dado, coluna por coluna
    3. coletar as respostas
    4. escrever no arquivo
    5. exibir o que foi salvo
    6. perguntar se deseja adicionar mais um registro
    
    */
}