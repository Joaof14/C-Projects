#include <stdio.h>
#include <string.h> 
#include <stdio.h>

void cadastrarPaciente(){
    printf("Cadastro de Paciente");

}

void listarPaciente(){
    printf("Pacientes Cadastrados\n");
    fopen("Pacientes.txt", "r");
    FILE *arquivo = fopen("Arquivos/Pacientes.txt", "r");
    char nome [100];
    int cpf;
    int contato;

    while (fscanf(arquivo, "%s, %d, %d", nome, &cpf, &contato) != EOF) {
        printf("Nome: %s, CPF: %d, Contato: %d\n", nome, cpf, contato);
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
            case 4:
                listarPaciente();
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

}