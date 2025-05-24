#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Medico.h"

void cadastrarMedico(){
    printf("Cadastro de Medico");

}

void listarMedico(){
    printf("Listar Medicos");

}

void atualizarMedico(){
    printf("Atualizar Medico");

}

void removerMedico(){
    printf("Remover Medico");

}


void menuMedico(){
    int opcao;
    do
    {
        printf("\nMenu Principal de Médicos\n");
        printf("1. Cadastrar Medico\n");
        printf("2. Atualizar Medico\n");
        printf("3. Remover Medico\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 0:
                return;
                break;
            case 1:
                cadastrarMedico();
                break;
            case 2:
                atualizarMedico();
                break;
            case 3:
                removerMedico();
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);
}