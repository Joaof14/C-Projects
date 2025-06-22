#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "auxiliar.h"

void cadastrarEmprestimo(){}

void registrarDevol(){}

void listarEmprestimoPorStatus(){}

void MenuEmprestimos(){
    int op;
    do {
        printf("\nEMPRESTIMOS\n");
        printf("Escolha a opção que você quer acessar:\n0.Voltar\n1.Cadastrar Empréstimo\n2.Registrar Devolução\n3.Listar Empréstimos por Status\n");
        scanf("%d", &op);
        switch (op)
        {
            case 0:
                return;
                break;
            case 1:
                cadastrarEmprestimo();
                break;
            case 2:
                registrarDevol();
                break;
            case 3:
                listarEmprestimoPorStatus();
            default:
                break;
        }
    }while(op != 0);
}