// ------Funções de mcriações de arquivos e verificação de existência -------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

// cria um arquivo com cabeçalhos se ele não existir
void criarArquivos(const char *caminho, const char *colunas) {
    FILE *arquivo =fopen(caminho, "w");
        if (arquivo != NULL) {
            fprintf(arquivo, "%s", colunas); 
            fclose(arquivo);
        } else {
            printf("Erro ao criar o arquivo: %s\n", caminho);
        }
        fclose(arquivo);
}

int ler_entrada_limitada(char *buffer, size_t tamanho_max) {
    if (fgets(buffer, tamanho_max, stdin) == NULL) {
        return 0; // Erro ou EOF
    }
    
    size_t len = strlen(buffer);
    
    // Se a entrada for muito longa (sem \n no final)
    if (len == tamanho_max - 1 && buffer[len - 1] != '\n') {
        // Limpar o buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return 0;
    }
    
    // Remover \n se existir
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
    
    return 1;
}

