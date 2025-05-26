#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Medico.h"
#include "Auxiliar.h"


const char* especialidadeParaTexto(enum ESPECIALIDADE esp) {
    switch (esp) {
        case CLINICO: return "CLINICO";
        case PEDIATRA: return "PEDIATRA";
        case CARDIOLOGISTA: return "CARDIOLOGISTA";
        case DERMATOLOGISTA: return "DERMATOLOGISTA";
        case PSIQUIATRA: return "PSIQUIATRA";
        case ORTOPEDISTA: return "ORTOPEDISTA";
        
        default: return "DESCONHECIDO";
    }
}

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
    printf("Selecione a especialidade:\n");
    for (int i = 0; i < 6; i++) {
        printf("  %d - %s\n", i, especialidadeParaTexto(i));
    }

    do {
        printf("Digite o número da especialidade: ");
        scanf("%d", (int*)&novo->especialidade);
        while (getchar() != '\n'); // limpa o buffer
        if (novo->especialidade < 0 || novo->especialidade >= 6) {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (novo->especialidade < 0 || novo->especialidade >= 6);


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
    printf("Especialidade: %s\n", especialidadeParaTexto(novo->especialidade));
    printf("Contato: %s\n", novo->contato);

    // perguntar se deseja salvar ou sair sem salvar
    printf("\nDeseja salvar os dados?");
    int opcao;
    do {
        printf("\n1. Salvar\n");
        printf("2. Sair sem salvar\n");
        printf("selecione uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch(opcao) {
            case 1:
                FILE *arquivo = fopen("Arquivos/Medicos.txt", "a");
                if (arquivo) {
                    fprintf(arquivo, "\n%s,%s,%d,%s", 
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







void listarMedico(){ /*
   printf("Lista de Medicos:\n");
    FILE *arquivo = fopen("Arquivos/Medicos.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhum Medico cadastrado ou erro ao abrir o arquivo!\n");
        return;
    }
    char linha[256];
    int contador = 1;
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char nome[100], crm[10], especialidade[50], contato[30];
        char *token = strtok(linha, ",");
        if (token != NULL) strcpy(nome, token);
        token = strtok(NULL, ",");
        if (token != NULL) strcpy(crm, token);
        token = strtok(NULL, ",");
        if (token != NULL) strcpy(especialidade, token);
        token = strtok(NULL, ",\n");
        if (token != NULL) strcpy(contato, token);

        printf("Medico %d:\n", contador++);
        printf("  Nome: %s\n", nome);
        printf("  CRM: %s\n", crm);
        printf("  Especialidade: %s\n", especialidade);
        printf("  Contato: %s\n\n", contato);
    }
    fclose(arquivo);
    */
}



void atualizarMedico(){ /*
  
    printf("Atualização de Medico\n");
    listarMedico();
    
    char crm[7];
    printf("Digite o CRM do medico a ser atualizado: ");
    entradaLimitada(crm, 7);

    FILE *arquivo = fopen("Arquivos/Medicos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // cria um arquivo temporário para armazenar os dados atualizados
    FILE *temp = fopen("Arquivos/temp.txt", "w");
    if (temp == NULL) {
        fclose(arquivo);
        printf("Erro ao criar arquivo temporário!\n");
        return;
    }

    char linha[256];
    int encontrado = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *token = strtok(linha, ",");
        if (token != NULL && strcmp(token, crm) == 0) {
            encontrado = 1;
            Medico novo;
            printf("Atualizando Dados:\n");

            // coleta do nome atualizado
            printf("Nome (máx 99 caracteres): ");
            entradaLimitada(novo.nome, 100);
            while (strlen(novo.nome) == 0) {
                printf("Nome (máx 99 caracteres): ");
                entradaLimitada(novo.nome, 100);
            }

            // coleta do CRM atualizado
            int crmValido = 0;
            do {
                printf("CRM (só numeros): ");
                entradaLimitada(novo.crm, 7);
                
                if (!validarCRM(novo.crm)) {
                    printf("Erro: CRM deve conter exatamente 6 números!\n");
                    continue;
                }
                
                if (CRMJaCadastrado(novo.crm)) {
                    printf("Erro: CRM já cadastrado no sistema!\n");
                    continue;
                }
                
                crmValido = 1;
            } while (!crmValido);

            // coleta da especialidade atualizada
            printf("Especialidade (máx 49 caracteres): ");      
            entradaLimitada(novo.especialidade, 50);
            while (strlen(novo.especialidade) == 0) {
                printf("Especialidade (máx 49 caracteres): ");
                entradaLimitada(novo.especialidade, 50);
            }

            // coleta do contato atualizado
            printf("Contato (máx 19 caracteres): ");    
            entradaLimitada(novo.contato, 20);
            while (strlen(novo.contato) == 0) {
                printf("Contato (máx 19 caracteres): ");
                entradaLimitada(novo.contato, 20);
            }

            // escreve os dados atualizados no arquivo temporário
            fprintf(temp, "%s,%s,%s,%s\n", novo.nome, novo.crm, novo.especialidade, novo.contato);
        } else {
            fputs(linha, temp);
        }

    }
    if (!encontrado) {
        fprintf(temp, "%s,%s,%s,%s\n", linha, crm, "Especialidade", "Contato");
    }
    // fecha os arquivos

    fclose(temp);
    fclose(arquivo);

    if (encontrado) {
        remove("Arquivos/Medicos.txt");
        rename("Arquivos/temp.txt", "Arquivos/Medicos.txt");
        printf("Medico atualizado com sucesso!\n");
    } else {
        remove("Arquivos/temp.txt");
        printf("CRM não encontrado para atualização!\n");
    }

    printf("Atualização concluída.\n");
    */
    
}



void removerMedico(){
    /*

    printf("Remoção de Medico\n");
    listarMedico();
    
    char crm[7];
    printf("Digite o CRM do medico a ser removido: ");
    entradaLimitada(crm, 7);

    FILE *arquivo = fopen("Arquivos/Medicos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    FILE *temp = fopen("Arquivos/temp.txt", "w");
    if (temp == NULL) {
        fclose(arquivo);
        printf("Erro ao criar arquivo temporário!\n");
        return;
    }

    char linha[256];
    int encontrado = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *token = strtok(linha, ",");
        if (token != NULL && strcmp(token, crm) != 0) {
            fputs(linha, temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    if (encontrado) {
        remove("Arquivos/Medicos.txt");
        rename("Arquivos/temp.txt", "Arquivos/Medicos.txt");
        printf("Medico removido com sucesso!\n");
    } else {
        remove("Arquivos/temp.txt");
        printf("CRM não encontrado para remoção!\n");
    }
*/
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
        printf("Selecione uma opcao: ");
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