#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "livros.h"
#include "emprestimos.h"
#include "relatorios.h"
#include "auxiliar.h"

int main(){
    //Criação dos arquivos que servirão como banco de dados
    criarArquivos("arquivos/livros.txt", "Colunas");
    criarArquivos("arquivos/Emprestimos.txt", "Colunas");


    int op;
    do {

    }while(op != 4);
    return 0;
}