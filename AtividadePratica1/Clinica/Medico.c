#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Medico.h"
#include "Auxiliar.h"


void cadastrarMedico()
{
    criarArquivo("Arquivos/Medicos.txt", "Nome,CRM,Especialidae,Contato\n");

    // alocar memória para o Medico
    Medico *novo = (Medico*)malloc(sizeof(Medico));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    // coletar dados usando ponteiros
    printf("Digite os dados do novo medico:\n");
    
    // coleta do nome com validações
    printf("Nome (máx 99 caracteres): ");
    entradaLimitada(novo->nome, 100);
    while (strlen(novo->nome) == 0) {
        printf("Nome (máx 99 caracteres): ");
        entradaLimitada(novo->nome, 100);
    }

    // coleta do CRM com validações
    int crmValido = 0;
    do {
        printf("CRM (só numeros): ");
        entradaLimitada(novo->crm, 7);
        
        if (!validarCRM(novo->crm)) {
            printf("Erro: CRM deve conter exatamente 6 números!\n");
            continue;
        }
        
        if (CRMJaCadastrado(novo->crm)) {
            printf("Erro: CRM já cadastrado no sistema!\n");
            continue;
        }
        
        crmValido = 1;
    } while (!crmValido);

    // coleta da especialidade
    printf("Especialidade (máx 49 caracteres): ");      
    entradaLimitada(novo->especialidade, 50);
    while (strlen(novo->especialidade) == 0) {
        printf("Especialidade (máx 49 caracteres): ");
        entradaLimitada(novo->especialidade, 50);
    }


    // coleta do contato com validações
    printf("Contato (máx 19 caracteres): ");    
    entradaLimitada(novo->contato, 20);
    while (strlen(novo->contato) == 0) {
        printf("Contato (máx 19 caracteres): ");
        entradaLimitada(novo->contato, 20);
    }

    // exibir os dados coletados
    printf("\nDados do novo medico:\n");    
    printf("Nome: %s\n", novo->nome);
    printf("CRM: %s\n", novo->crm);
    printf("Especialidade: %s\n", novo->especialidade);
    printf("Contato: %s\n", novo->contato);

    // perguntar se deseja salvar ou sair sem salvar
    printf("\nDeseja salvar os dados?");
    int opcao;
    do {
        printf("\n1. Salvar\n");
        printf("2. Sair sem salvar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); 

        switch(opcao) {
            case 1:
        FILE *arquivo = fopen("Arquivos/Medicos.txt", "a");
        if (arquivo) {
            fprintf(arquivo, "\n%s,%s,%s,%s", 
                    novo->nome, 
                    novo->crm, 
                    novo->especialidade, 
                    novo->contato);
            fclose(arquivo);
            printf("Medico salvo com sucesso!\n");
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