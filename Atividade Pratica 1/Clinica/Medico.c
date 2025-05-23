#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Medico.h"

void cadastrarMedico() {
   
    printf("Você está cadastrando um Medico"); 

}

void listarMedicos(){

}

void removerMedico(){

}

void atualizarMedico(){
    
}

void menuMedico(){
    int opcao;
    do
    {
        printf("Menu Principal\n");
        printf("1. Cadastrar Paciente\n");
        printf("2. Atualizar Paciente\n");
        printf("3. Remover Paciente\n");
        printf("4. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                cadastrarPaciente();
                break;
            case 2:
                atualizarPaciente();
                break;
            case 3:
                removerPaciente();
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);
}