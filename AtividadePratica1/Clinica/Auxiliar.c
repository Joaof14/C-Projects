#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Auxiliar.h"

// cria um arquivo com cabeçalhos se ele não existir
void criarArquivo(const char *caminho, const char *colunas) {
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


// lê entrada do usuário com controle de tamanho
int entradaLimitada(char *destino, int tamanho_max) {
    int i = 0;
    char c;
    
    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < tamanho_max - 1) {
            destino[i++] = c;
        }
    }
    destino[i] = '\0';
    return i; 
}

// valida se o cpf tem 11 dígitos numéricos
int validarCPF(const char *cpf) {
    if (strlen(cpf) != 11) return 0;
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) return 0;
    }
    
    return 1; // cpf válido
}


// verifica se um cpf já existe no arquivo

int CPFJaCadastrado(const char *cpf) {
    FILE *arquivo = fopen("Arquivos/Pacientes.txt", "r");
    if (arquivo == NULL) return 0;

    char nome[100], cpfArquivo[12], telefone[20];

    // Pular o cabeçalho
    fscanf(arquivo, "%*[^\n]\n");

    while (fscanf(arquivo, "%99[^,],%11[^,],%19[^\n]\n", nome, cpfArquivo, telefone) == 3) {
        if (strcmp(cpfArquivo, cpf) == 0) {
            fclose(arquivo);
            return 1;
        }
    }

    fclose(arquivo);
    return 0;
}


