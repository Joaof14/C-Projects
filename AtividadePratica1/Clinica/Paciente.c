#include <stdio.h>
#include <string.h>
#include <stdio.h>

void cadastrarPaciente()
{
    printf("Cadastrar Novo Paciente\n");
    FILE *arquivo = fopen("Arquivos/Pacientes.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("Arquivos/Pacientes.txt", "w");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }
    fclose(arquivo);
    FILE *arquivo = fopen("Arquivos/Pacientes.txt", "a");
    char nome[100];
    char cpf[12];
    char contato[20];
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
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
    printf("Lista de Pacientes:\n");
    FILE *arquivo = fopen("Arquivos/Pacientes.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhum paciente cadastrado ou erro ao abrir o arquivo!\n");
        return;
    }
    char linha[200];
    int contador = 1;
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char nome[100], cpf[20], contato[30];
        char *token = strtok(linha, ",");
        if (token != NULL) strcpy(nome, token);
        token = strtok(NULL, ",");
        if (token != NULL) strcpy(cpf, token);
        token = strtok(NULL, ",\n");
        if (token != NULL) strcpy(contato, token);

        printf("Paciente %d:\n", contador++);
        printf("  Nome: %s\n", nome);
        printf("  CPF: %s\n", cpf);
        printf("  Contato: %s\n\n", contato);
    }
    fclose(arquivo);
}

void atualizarPaciente()
{
    printf("Atualizar Paciente");
}

void removerPaciente()
{


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