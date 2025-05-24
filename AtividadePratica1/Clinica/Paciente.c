#include <stdio.h>
#include <string.h> 
#include <stdio.h>

void cadastrarPaciente(){
    printf("Cadastro de Paciente");

}

void listarPaciente(){
    printf("Listar Pacientes");
    fopen("Pacientes.txt", "r");
    FILE *file = fopen("Pacientes.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    char linha[256];
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
        printf("Menu Principal de Pacientes\n");
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