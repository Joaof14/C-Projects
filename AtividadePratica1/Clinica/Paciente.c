#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Paciente.h"
#include "Auxiliar.h"

void cadastrarPaciente()
{
    criarArquivo("Arquivos/Pacientes.txt", "Nome,CPF,Telefone");

    // Alocar memória para o paciente
    Paciente *novo = (Paciente*)malloc(sizeof(Paciente));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    // Coletar dados usando ponteiros
    printf("\n--- Novo Paciente ---\n");
    
    printf("Nome: ");
    lerString(novo->nome, sizeof(novo->nome));

    printf("CPF (11 dígitos): ");
    lerString(novo->cpf, sizeof(novo->cpf));

    printf("Telefone: ");
    lerString(novo->Telefone, sizeof(novo->Telefone));

    // Menu de opções
    int opcao;
    do {
        printf("\n1. Salvar\n");
        printf("2. Sair sem salvar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // Limpar buffer

        switch(opcao) {
            case 1:
                // Salvar no arquivo
                FILE *arquivo = fopen("Arquivos/Pacientes.txt", "a");
                if (arquivo) {
                    fprintf(arquivo, "\n%s,%s,%s", 
                            novo->nome, 
                            novo->cpf, 
                            novo->Telefone);
                    fclose(arquivo);
                    printf("Paciente salvo com sucesso!\n");
                } else {
                    printf("Erro ao abrir arquivo!\n");
                }
                break;
                
            case 2:
                printf("Cadastro descartado.\n");
                break;
                
            default:
                printf("Opção inválida!\n");
                continue;
        }
    } while(opcao < 1 || opcao > 2);

    free(novo); // Liberar memória
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