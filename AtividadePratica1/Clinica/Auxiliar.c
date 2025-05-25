#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Auxiliar.h"



void criarArquivo(const char *caminho){
    FILE *arquivo = fopen(caminho, "r");
    

    if (arquivo == NULL){
        arquivo = fopen(caminho, "w");
        fclose(arquivo);
    }
    else{
        fclose(arquivo);
    }
}

void lerArquivo(const char *caminho, int *totalLinhas){
    

}

void alterarArquivo(const char *caminho, const char *modo, const char *conteudo ){

}

