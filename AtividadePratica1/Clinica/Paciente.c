#include <stdio.h>
#include <string.h>
#include <stdio.h>

void cadastrarPaciente()
{
    printf("Cadastrar Novo Paciente\n");
    FILE *arquivo = fopen("Arquivos/Pacientes.txt", "a");
    char nome[100];
    char cpf[12];
    char contato[20];

    printf("Digite o nome do paciente: ");
    getchar(); // Limpa o buffer do teclado
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0; // Remove o \n do final

    printf("Digite o CPF do paciente: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    printf("Digite o contato do paciente: ");
    fgets(contato, sizeof(contato), stdin);
    contato[strcspn(contato, "\n")] = 0;

    fprintf(arquivo, "%s,%s,%s\n", nome, cpf, contato);
    fclose(arquivo);
}

void listarPaciente()
{
    printf("Pacientes Cadastrados\n");
    fopen("Pacientes.txt", "r");
    FILE *arquivo = fopen("Arquivos/Pacientes.txt", "r");
    char nome[100];
    int cpf;
    int contato;

    while (fscanf(arquivo, "%s,%d,%d", nome, &cpf, &contato) != EOF)
    {
        printf("Nome: %s, CPF: %d, Contato: %d\n", nome, cpf, contato);
    }
    fclose(arquivo);
    printf("\n");
}

void atualizarPaciente()
{
    printf("Atualizar Paciente");
}

void removerPaciente()
{
    printf("Remover Paciente");
}

void menuPaciente()
{
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
        {
        case 0:
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
        case 4: // Remover depois
            listarPaciente();
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);
}