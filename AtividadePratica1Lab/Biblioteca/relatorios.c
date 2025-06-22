#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "auxiliar.h"

void listarLivrosPorGenero(){}

void listarLivrosPorStatus(){}

void MenuRelatorios(){
    int op;
    do {
        printf("\nEMPRESTIMOS\n");
        printf("Escolha a opção que você quer acessar:\n0.Voltar\n1.Listar Livros por Gênero\n2.Listar Livros por Status\n");
        switch (op)
        {
            case 0:
                return;
                break;
            case 1:
                listarLivrosPorGenero();
                break;
            case 2:
                listarLivrosPorStatus();
                break;
            default:
                break;
        }
    }while(op != 0);
}