// ------Funções de mcriações de arquivos e verificação de existência -------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// cria um arquivo com cabeçalhos se ele não existir
void criarArquivos(const char *caminho, const char *colunas) {
    FILE *arquivo = fopen(caminho, "r");
    
    if (arquivo == NULL) {
        arquivo = fopen(caminho, "w");
        if (arquivo != NULL) {
            fprintf(arquivo, "%s", colunas); 
            fclose(arquivo);
        } else {
            printf("Erro ao criar o arquivo: %s\n", caminho);
        }
    } else {
        fclose(arquivo); 
    }
}