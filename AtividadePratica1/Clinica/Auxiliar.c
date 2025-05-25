#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Auxiliar.h"

void removerQuebraLinha(char *str) {
    while (*str != '\0') {
        if (*str == '\n') {
            *str = '\0'; // Substitui quebra de linha por terminador
            break;
        }
        str++;
    }
}

void criarArquivo(const char *caminho, const char *colunas) {
    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL) {
        arquivo = fopen(caminho, "w");
        if (arquivo != NULL) {
            // Adiciona quebra de linha após os cabeçalhos
            fprintf(arquivo, "%s", colunas); // "\n" no final
            fclose(arquivo);
        } else {
            printf("Erro ao criar o arquivo: %s\n", caminho);
        }
    } else {
        fclose(arquivo); // Arquivo já existe
    }
}

void lerString(char *destino, int tamanho) {
    scanf(" %[^\n]", destino); // Lê até encontrar '\n'
    removerQuebraLinha(destino); // Remove a quebra de linha (se houver)
}
