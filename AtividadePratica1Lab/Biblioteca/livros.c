#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "auxiliar.h"




void salvarLivro(Livros * livros){
        FILE *arquivo = fopen("Arquivos/livros.txt","a");
    if (!arquivo) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }
    int total = sizeof(livros)/sizeof(Livros);

    //escreve os médicos
    for (int i = 0; i < total; i++) {

        fprintf(arquivo, "%s,%s,%s,%d\n",
                livros[i].ISBN, 
                livros[i].titulo, 
                livros[i].autor, 
                livros[i].genero);
    }

    fclose(arquivo);
}

void cadastrarLivro(){

}

void removerLivro(){
    //criarArquivos("arquivos/livros.txt", "ISBN,titulo,autor,genero\n");
}

void atualizarLivro(){
    //criarArquivos("arquivos/livros.txt", "ISBN,titulo,autor,genero\n");
}

void MenuLivros(){

    int op;
    do {
        printf("\nLIVROS\n");
        printf("Escolha a opção que você quer acessar:\n0.Voltar\n1.Cadastrar Livro\n2. Remover Livro\n3.Atualizar Livro\n");
        scanf("%d", &op);
        switch (op)
        {
            case 0:
                return;
                break;
            case 1:
                cadastrarLivro();
                break;
            case 2:
                removerLivro();
                break;
            case 3:
                atualizarLivro();
            default:
                break;
        }
    }while(op != 0);
}