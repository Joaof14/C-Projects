#include <stdio.h>
#include <string.h> 
#include <stdio.h>

void cadastrarPaciente(){

}

void listarPaciente(){

}

void atualizarPaciente(){

}

void removerPaciente(){

}

void menuPaciente(){
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