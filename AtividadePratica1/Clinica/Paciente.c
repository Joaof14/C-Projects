#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Paciente.h"
#include "Auxiliar.h"

void cadastrarPaciente()
{
    criarArquivo("Arquivos/Pacientes.txt", "Nome,CPF,Telefone");

    // alocar memória para o paciente
    Paciente *novo = (Paciente*)malloc(sizeof(Paciente));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    // coletar dados usando ponteiros
    printf("\n Novo Paciente \n");
    do {
        printf("Nome (máx 99 caracteres): ");
        entradaLimitada(novo->nome, 100);
    }
    while (strlen(novo->nome) == 0); 

    // coleta do cpf com validações
    int cpfValido = 0;
    do {
        printf("CPF (só numeros): ");
        entradaLimitada(novo->cpf, 12);
        
        if (!validarCPF(novo->cpf)) {
            printf("Erro: CPF deve conter exatamente 11 números!\n");
            continue;
        }
        
        if (CPFJaCadastrado(novo->cpf)) {
            printf("Erro: CPF já cadastrado no sistema!\n");
            continue;
        }
        
        cpfValido = 1;
    } while (!cpfValido);

    
    do {
        printf("Telefone (só numeros): ");
        entradaLimitada(novo->telefone, 20);
    } while (strlen(novo->telefone) == 0);


    int opcao;
    do {
        printf("\n1. Salvar\n");
        printf("2. Sair sem salvar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); 

        switch(opcao) {
            case 1:
                //salvamentos dos dados
                FILE *arquivo = fopen("Arquivos/Pacientes.txt", "a");
                if (arquivo) {
                    fprintf(arquivo, "\n%s,%s,%s", 
                            novo->nome, 
                            novo->cpf, 
                            novo->telefone);
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

    free(novo); 
}








void listarPaciente()
{
    printf("Lista de Pacientes:\n");
    FILE *arquivo = fopen("Arquivos/Pacientes.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhum paciente cadastrado ou erro ao abrir o arquivo!\n");
        return;
    }
    //Pular cabeçalho
    char cabecalho[200];
    fscanf(arquivo, "%199[^\n]\n", cabecalho);
    Paciente paciente;
    int contador = 1;
    //Ler dados
    while (fscanf(arquivo, "%99[^,],%11[^,],%19[^\n]\n",
                  paciente.nome,
                  paciente.cpf,
                  paciente.telefone) == 3) 
    {
        printf("Paciente %d:\n", contador++);
        printf("Nome: %s\n", paciente.nome);
        printf("CPF: %s\n", paciente.cpf);
        printf("Telefone: %s\n\n", paciente.telefone);
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