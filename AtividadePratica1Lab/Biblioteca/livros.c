#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "auxiliar.h"

void cadastrarLivro(){}

void removerLivro(){}

void atualizarLivro(){}

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