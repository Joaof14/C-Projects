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

//Carregar arquivos
void carregarLivros(Livros ** livros){
        FILE *arquivo = fopen("Arquivos/livros.txt", "r");
        int * total = 0;
    if (!arquivo) {
        *total = 0;
        *livros = NULL;
        return;
    }

    //pular cabeçalho (primeira linha)
    char buffer[256];
    fgets(buffer, sizeof(buffer), arquivo);

    *total = 0;
    Livros temp;
    int genero_tmp;

    //ler cada linha do arquivo
    while (fscanf(arquivo, "%s,%199[^,],%199[^,],%d\n", 
                temp.ISBN,
                temp.titulo, 
                temp.autor, 
                &genero_tmp) == 4) {

        //converter genero
        temp.genero = (enum GENERO)genero_tmp;

        //alocar espaço para mais um médico e adicionar
        *livros = realloc(*livros, (*total + 1) * sizeof(Livros));
        (*livros)[*total] = temp;
        (*total)++;
    }
    fclose(arquivo);
}


