#include <stdio.h>
#include <string.h> 
#include <stdio.h>

void cadastrarPaciente(){
    printf("Cadastro de Paciente");

}

void listarPaciente(){
    printf("Pacientes Cadastrados\n");
    fopen("Pacientes.txt", "r");
    FILE *file = fopen("Arquivos/Pacientes.txt", "r");
    char linha [256];
    while (fgets(linha, sizeof(linha), file) != NULL) {
        printf("%s", linha);
    }
    fclose(file);
    printf("\n");

}

void atualizarPaciente(){
    printf("Atualizar Paciente");

}

void removerPaciente(){
    printf("Remover Paciente");

}

void menuPaciente(){
    int opcao;
    do
    {
        printf("\nMenu Principal de Pacientes\n");
        printf("1. Cadastrar Paciente\n");
        printf("2. Atualizar Paciente\n");
        printf("3. Remover Paciente\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {   case 0:
                return;
                break;
            case 1:
                cadastrarPaciente();
                break;
            case 2:
                atualizarPaciente();
                break;
            case 3:
                removerPaciente();
                break;
            case 4: //Remover depois
                listarPaciente();
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

}