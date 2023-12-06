#include "common_utils/dependecies.h"

void escrever_tabela(Coluna colunas[], int qtdColunas, char nomeArquivo[]) {

    // Mapear tipos
    char listTipos[5][20] = {"CHAR", "INT", "FLOAT", "DOUBLE", "STRING"};

    // Nome do diretorio tabelas
    char nomeDiretorio[200] = "tabelas/";

    // Variaveis de arquivo e lista de tabelas existentes
    FILE *arquivo, *listTabela;

    // Adicionar a tabela na lista de tabelas
    listTabela = fopen("tabelas/listTabelas.pwn", "a"); // Abrir o arquivo
    fprintf(listTabela, "%i %s\n", qtdColunas,
            nomeArquivo); // Escrever no arquivo
    fclose(listTabela);   // Fechar o arquivo

    // Criar nome do arquivo da tabela
    strcat(nomeArquivo, ".pwn"); // Adicionar a extensão .pwn
    strcat(nomeDiretorio,
           nomeArquivo); // Adicionar nome do arquivo ao nome do diretorio

    // Abrir arquivo da tabela
    printf("nomeDiretorio: %s\n", nomeDiretorio);
    arquivo = fopen(nomeDiretorio, "w");

    if (arquivo != NULL) {
        printf("\033[0;32m"); // Setar a cor do output pra verde
        printf("\nArquivo criado com sucesso!\n\n");
        printf("\033[0m"); // Resetar a cor do output
    } else {
        erro_ao_abrir_arquivo();
    }

    // Escrever colunas no arquivo
    for (int i = 0; i < qtdColunas; i++) {
        fprintf(arquivo, "%s.%s;", colunas[i].nome, listTipos[colunas[i].tipo]);
    }

    fclose(arquivo); // Fechar arquivo
}

Coluna *criar_colunas(Coluna *colunas, int qtdColunas) {
    for (int i = 1; i < qtdColunas; i++) {

        int validacao = 0;

        while (validacao == 0) {

            printf("Digite o nome da coluna %d: ", i);
            char nomeColuna[20];

            scanf("%s", nomeColuna);

            if (nomeColuna[0] == '\0') {

                print_vermelho("Nome da coluna não pode ser vazio!");

            } else if (nomeColuna[0] == ' ') {

                print_vermelho("Nome da coluna não pode começar com espaço!");
            }

            int flag = 0;

            for (int j = 0; j < i; j++) {
                if (strcmp(nomeColuna, colunas[i].nome) == 0) {

                    print_vermelho("Uma coluna com esse nome já existe!");
                    flag = 1;

                }
            }

            if (flag == 0) {
                strcpy(colunas[i].nome, nomeColuna);
                validacao = 1;
            }
            
            
        }

        printf("\nQual será o tipo da coluna %d: %s\n", i, colunas[i].nome);
            printf("1 - CHAR\t2 - INT\n3 - FLOAT\t4 - DOUBLE\n5 - STRING\n");

            int opcao;
            scanf("%d", &opcao);

            switch (opcao) {
            case 1:
                colunas[i].tipo = CHAR;
                break;
            case 2:
                colunas[i].tipo = INT;
                break;
            case 3:
                colunas[i].tipo = FLOAT;
                break;
            case 4:
                colunas[i].tipo = DOUBLE;
                break;
            case 5:
                colunas[i].tipo = STRING;
                break;
            }

    }
    return colunas;

}

void criar_tabela() {
    // Criar o nome da tabela
    char listTipos[5][20] = {"CHAR", "INT", "FLOAT", "DOUBLE", "STRING"};

    int validacao = 0;
    char nomeArquivo[20];

    while (validacao == 0) {

        char nomeArquivoLoop[20];

        printf("\nDigite o nome da tabela: ");

        scanf("%s", nomeArquivoLoop);

        if (lista_existe() == true) {

            if (nomeArquivoLoop == '\0') {
                print_vermelho("Nome da tabela não pode ser vazio!");
            } else if (nomeArquivoLoop[0] == ' ') {
                print_vermelho("Nome da tabela não pode começar com espaço!");
            } else if (tabela_existe(nomeArquivoLoop) == true) {
                print_vermelho("Uma tabela com esse nome já existe!");
            } else {
                strcpy(nomeArquivo, nomeArquivoLoop);
                validacao = 1;
            }
        } else if (lista_existe() == false) {
            printf("Lista não existe, criando lista...\n");
            strcpy(nomeArquivo, nomeArquivoLoop);
            criar_lista();
            validacao = 1;
        }
    }

    // Criar a coluna primaria
    printf("Digite o nome da coluna primaria: ");
    char colunaId[20];
    scanf("%s", colunaId);

    // Quantas colunas
    int qtdColunas;
    printf("Quantas colunas deseja criar? ");
    scanf("%d", &qtdColunas);

    // Adicionando a colunaId na contagem
    qtdColunas += 1;

    // Array pra guardar as colunas
    Coluna colunas[qtdColunas];

    // Inicializar a coluna primaria
    strcpy(colunas[0].nome, colunaId);

    // Obrigatoriamente a coluna 0 é um inteiro
    colunas[0].tipo = INT;

    Coluna *colunasPtr = criar_colunas(colunas, qtdColunas);

    // Imprimir nomes e tipos das colunas
    printf("\nNomes e tipos das colunas:\n");
    for (int i = 0; i < qtdColunas; i++) {
        if (colunasPtr[i].nome[0] == '\0') {
            break;
        } else {
            printf("Coluna %d: %s (Tipo: %s)\n", i + 1, colunasPtr[i].nome,
                   listTipos[colunasPtr[i].tipo]);
        }
    }

    escrever_tabela(colunasPtr, qtdColunas, nomeArquivo);
}