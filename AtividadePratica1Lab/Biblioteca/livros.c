#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "auxiliar.h"




void salvarLivros(Livros * livros, int total){
        FILE *arquivo = fopen("arquivos/livros.txt","a");
    if (!arquivo) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    //escreve os livros
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
// alocar memória para o Livros
    Livros *novo = (Livros*)malloc(sizeof(Livros));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }
    
    // coletar dados usando ponteiros
    printf("\n Novo Livros \n");
    while (getchar() != '\n');


    // coleta do ISBN com validações
    receberISBN(novo->ISBN);

    // coleta do titulo
    printf("\nTítulo do livro\n");
    receberTitulo(novo->titulo);

    // coleta do ISBN com validações
    printf("\nAutor do livro\n");
    receberNome(novo->autor);

    // coleta do genero
    receberGenero(&novo->genero);

    // exibir os dados coletados
    exibirLivro(*novo);

    // perguntar se deseja salvar ou sair sem salvar
    printf("\nDeseja salvar os dados?");
    int opcao;
    do {
        printf("\n1. Salvar\n");
        printf("2. Sair sem salvar\n");
        printf("selecione uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch(opcao) {
            case 1:
                salvarLivros(novo, 1); 
                printf("Livro cadastrado com sucesso!\n");
                break;
            case 2:
                printf("Cadastro descartado.\n");
                break;
            default:
                printf("Opção inválida!\n");
                continue;
        }
    } while(opcao < 1 || opcao > 2);

    free(novo); 
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