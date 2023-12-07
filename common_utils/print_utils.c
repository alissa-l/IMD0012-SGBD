#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

/*
Printa erro em vermelho
*/
void erro_ao_abrir_arquivo() {
    printf("\033[0;31m"); // Setar a cor do output pra vermelho
    printf("\nErro ao abrir o arquivo!\n");
    printf("Erro: %d\n", errno);
    printf("Erro: %s\n", strerror(errno));
    printf("\033[0m"); // Resetar a cor do output
}

/*
Printa em vermelho
*/
void print_vermelho(char string[]) {
    printf("\033[0;31m"); // Setar a cor do output pra vermelho
    printf("\n%s\n", string);
    printf("\033[0m"); // Resetar a cor do output
}

/*
Printa em verde
*/
void print_verde(char string[]) {
    printf("\033[0;32m"); // Setar a cor do output pra verde
    printf("%s", string);
    printf("\033[0m"); // Resetar a cor do output
}