#include "./common_utils/dependecies.h"
void pesquisa_maior_que(char valorPesquisa[], Tabela tabela, Coluna col, int indCln) {
    for(int i = 0; i < tabela.qtdLinhas; i++) {
                if(strcmp(col.nomeTipo, "CHAR") == 0) {
                    if(tabela.linhas[i].valoresColuna[indCln].valor > valorPesquisa[0]) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "INT") == 0) {
                    if(atoi(tabela.linhas[i].valoresColuna[indCln].valor) > atoi(valorPesquisa)) {

                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "FLOAT") == 0) {
                    if(atof(tabela.linhas[i].valoresColuna[indCln].valor) > atof(valorPesquisa)) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "DOUBLE") == 0) {
                    if(atof(tabela.linhas[i].valoresColuna[indCln].valor) > atof(valorPesquisa)) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "STRING") == 0) {
                    if(strcmp(tabela.linhas[i].valoresColuna[indCln].valor, valorPesquisa) > 0) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);
                        }
                        printf("\n");
                    }
                }
            }
}

void pesquisa_maior_ou_igual_a(char valorPesquisa[], Tabela tabela, Coluna col, int indCln) {
    for(int i = 0; i < tabela.qtdLinhas; i++) {
                if(strcmp(col.nomeTipo, "CHAR") == 0) {
                    if(tabela.linhas[i].valoresColuna[indCln].valor >= valorPesquisa[0]) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);	
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "INT") == 0) {
                    if(atoi(tabela.linhas[i].valoresColuna[indCln].valor) >= atoi(valorPesquisa)) {

                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);	
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "FLOAT") == 0) {
                    if(atof(tabela.linhas[i].valoresColuna[indCln].valor) >= atof(valorPesquisa)) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);	
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "DOUBLE") == 0) {
                    if(atof(tabela.linhas[i].valoresColuna[indCln].valor) >= atof(valorPesquisa)) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);	
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "STRING") == 0) {
                    if(strcmp(tabela.linhas[i].valoresColuna[indCln].valor, valorPesquisa) >= 0) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor
                            );
                        }
                        printf("\n");
                    }
                }
            }
}


void pesquisa_menor_que(char valorPesquisa[], Tabela tabela, Coluna col, int indCln) {
    for(int i = 0; i < tabela.qtdLinhas; i++) {
                if(strcmp(col.nomeTipo, "CHAR") == 0) {
                    if(tabela.linhas[i].valoresColuna[indCln].valor < valorPesquisa[0]) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "INT") == 0) {
                    if(atoi(tabela.linhas[i].valoresColuna[indCln].valor) < atoi(valorPesquisa)) {

                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "FLOAT") == 0) {
                    if(atof(tabela.linhas[i].valoresColuna[indCln].valor) < atof(valorPesquisa)) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "DOUBLE") == 0) {
                    if(atof(tabela.linhas[i].valoresColuna[indCln].valor) < atof(valorPesquisa)) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "STRING") == 0) {
                    if(strcmp(tabela.linhas[i].valoresColuna[indCln].valor, valorPesquisa) < 0) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);
                        }
                        printf("\n");	
                    }
                }
            }
}

void pesquisa_menor_ou_igual_a(char valorPesquisa[], Tabela tabela, Coluna col, int indCln) {
    for(int i = 0; i < tabela.qtdLinhas; i++) {
                if(strcmp(col.nomeTipo, "CHAR") == 0) {
                    if(tabela.linhas[i].valoresColuna[indCln].valor <= valorPesquisa[0]) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);	
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "INT") == 0) {
                    if(atoi(tabela.linhas[i].valoresColuna[indCln].valor) <= atoi(valorPesquisa)) {

                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);	
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "FLOAT") == 0) {
                    if(atof(tabela.linhas[i].valoresColuna[indCln].valor) <= atof(valorPesquisa)) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);	
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "DOUBLE") == 0) {
                    if(atof(tabela.linhas[i].valoresColuna[indCln].valor) <= atof(valorPesquisa)) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);	
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "STRING") == 0) {
                    if(strcmp(tabela.linhas[i].valoresColuna[indCln].valor, valorPesquisa) <= 0) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor
                            );
                        }
                        printf("\n");
                    }
                }
            }
}

void pesquisa_igual_a(char valorPesquisa[], Tabela tabela, Coluna col, int indCln) {
    for(int i = 0; i < tabela.qtdLinhas; i++) {
                if(strcmp(col.nomeTipo, "CHAR") == 0) {
                    if(tabela.linhas[i].valoresColuna[indCln].valor == valorPesquisa[0]) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);	
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "INT") == 0) {
                    if(atoi(tabela.linhas[i].valoresColuna[indCln].valor) == atoi(valorPesquisa)) {

                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);	
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "FLOAT") == 0) {
                    if(atof(tabela.linhas[i].valoresColuna[indCln].valor) == atof(valorPesquisa)) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);	
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "DOUBLE") == 0) {
                    if(atof(tabela.linhas[i].valoresColuna[indCln].valor) == atof(valorPesquisa)) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);	
                        }
                        printf("\n");
                    }
                } else if(strcmp(col.nomeTipo, "STRING") == 0) {
                    if(strcmp(tabela.linhas[i].valoresColuna[indCln].valor, valorPesquisa) <= 0) {
                        for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                            printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor
                            );
                        }
                        printf("\n");
                    }
                }
            }
}

void pesquisa_proxima(char valorPesquisa[], Tabela tabela, Coluna col, int indCln) {
    int maxCharsComuns = 0;

    for (int i = 0; i < tabela.qtdLinhas; i++) {
        int charsComuns = 0;
        int len = strlen(tabela.linhas[i].valoresColuna[indCln].valor);
        int minLen = strlen(valorPesquisa) < len ? strlen(valorPesquisa) : len;

        for (int j = 0; j < minLen; j++) {
            if (tabela.linhas[i].valoresColuna[indCln].valor[j] == valorPesquisa[j]) {
                charsComuns++;
            } else {
                break;
            }
        }

        if (charsComuns > maxCharsComuns) {
            maxCharsComuns = charsComuns;
        }
    }

    for (int i = 0; i < tabela.qtdLinhas; i++) {
        int charsComuns = 0;
        int len = strlen(tabela.linhas[i].valoresColuna[indCln].valor);
        int minLen = strlen(valorPesquisa) < len ? strlen(valorPesquisa) : len;

        for (int j = 0; j < minLen; j++) {
            if (tabela.linhas[i].valoresColuna[indCln].valor[j] == valorPesquisa[j]) {
                charsComuns++;
            } else {
                break;
            }
        }

        if (charsComuns == maxCharsComuns) {
            for (int indice = 0; indice < tabela.qtdColunas; indice++) {
                printf("%s\t\t", tabela.linhas[i].valoresColuna[indice].valor);
            }
            printf("\n");
        }
    }
}
