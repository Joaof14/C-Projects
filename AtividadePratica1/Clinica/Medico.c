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



void carregarMedicos(Medico **medicos, int *total) {
    FILE *arquivo = fopen("Arquivos/Medicos.txt", "r");
    if (!arquivo) {
        *total = 0;
        *medicos = NULL;
        return;
    }

    //pular cabeçalho (primeira linha)
    char buffer[256];
    fgets(buffer, sizeof(buffer), arquivo);

    *total = 0;
    Medico temp;
    int especialidade_tmp;

    //ler cada linha do arquivo
    while (fscanf(arquivo, "%99[^,],%6[^,],%d,%19[^\n]\n", 
                temp.nome, 
                temp.crm, 
                &especialidade_tmp, 
                temp.contato) == 4) {

        //converter especialidade
        temp.especialidade = (enum ESPECIALIDADE)especialidade_tmp;

        //alocar espaço para mais um médico e adicionar
        *medicos = realloc(*medicos, (*total + 1) * sizeof(Medico));
        (*medicos)[*total] = temp;
        (*total)++;
    }
    fclose(arquivo);
}

void salvarMedicos(Medico *medicos, int total, const char *modo) {

    
    
    FILE *arquivo = fopen("Arquivos/Medicos.txt", modo);
    if (!arquivo) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    //se for modo write, reescreve o cabeçalho
    if (strcmp(modo, "w") == 0) {
        fprintf(arquivo, "Nome,CRM,Especialidade,Contato\n");
    }

    //escreve os médicos
    for (int i = 0; i < total; i++) {
        fprintf(arquivo, "%s,%s,%d,%s\n", 
                medicos[i].nome, 
                medicos[i].crm, 
                medicos[i].especialidade, 
                medicos[i].contato);
    }

    fclose(arquivo);
}

void cadastrarMedico()
{
    verificarArquivo("Arquivos/Medicos.txt", "Nome,CRM,Especialidade,Contato\n");

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
            salvarMedicos(novo, 1, "a"); 
            printf("Médico cadastrado com sucesso!\n");
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


void listarMedicos() {
    Medico *medicos = NULL;
    int total;
    carregarMedicos(&medicos, &total);

    if(total == 0) {
        printf("Nenhum médico cadastrado!\n");
        return;
    }

    printf("\nLista de Médicos\n");
    for(int i = 0; i < total; i++) {
        printf("\nMédico %d:\n", i+1);
        printf("Nome: %s\n", medicos[i].nome);
        printf("CRM: %s\n", medicos[i].crm);
        printf("Especialidade: %s\n", especialidadeParaTexto(medicos[i].especialidade));
        printf("Contato: %s\n", medicos[i].contato);
    }
    
    free(medicos); //liberar memória alocada
}



  
void atualizarMedico() {

    verificarArquivo("Arquivos/Medicos.txt", "Nome,CRM,Especialidade,Contato\n");

    Medico *medicos = NULL;
    int total = 0;
    carregarMedicos(&medicos, &total);

    while (getchar() != '\n');

    //Buscar médico pelo crm
    char crm[7];
    printf("\n--- Atualização de Médico ---\n");
    printf("Digite o CRM (6 dígitos): ");
    entradaLimitada(crm, sizeof(crm));
    
    int encontrado = -1;
    for(int i = 0; i < total; i++) {
        if(strcmp(medicos[i].crm, crm) == 0) {
            encontrado = i;
            break;
        }
    }

    if(encontrado == -1) {
        printf("Médico não encontrado!\n");
        free(medicos);
        return;
    }

    Medico atualizado = medicos[encontrado]; 

    //coletar novos dados (mesma sequência do cadastro)
    printf("\nAtualizar Dados \n");
    
    //atualizar nome
    printf("Nome atual: %s\n", atualizado.nome);
    do {
        printf("Novo nome (máx 99 caracteres): ");
        entradaLimitada(atualizado.nome, sizeof(atualizado.nome));
        if(strlen(atualizado.nome) == 0) {
            printf("Nome não pode ser vazio!\n");
        }
    } while(strlen(atualizado.nome) == 0);

    //atualizar especialidade
    printf("\nEspecialidade atual: %s\n", especialidadeParaTexto(atualizado.especialidade));
    for(int i = 0; i < 6; i++) {
        printf("  %d - %s\n", i, especialidadeParaTexto(i));
    }
    do {
        printf("Nova especialidade: ");
        scanf("%d", (int*)&atualizado.especialidade);
        while(getchar() != '\n'); // Limpar buffer
        if(atualizado.especialidade < 0 || atualizado.especialidade >= 6) {
            printf("Opção inválida!\n");
        }
    } while(atualizado.especialidade < 0 || atualizado.especialidade >= 6);

    //atualizar contato
    printf("\nContato atual: %s\n", atualizado.contato);
    do {
        printf("Novo contato (máx 19 caracteres): ");
        entradaLimitada(atualizado.contato, sizeof(atualizado.contato));
        if(strlen(atualizado.contato) == 0) {
            printf("Contato não pode ser vazio!\n");
        }
    } while(strlen(atualizado.contato) == 0);

    //substituir no vetor
    medicos[encontrado] = atualizado;


    int opcao;
    do {
        printf("\n1. Salvar\n");
        printf("2. Sair sem salvar\n");
        printf("selecione uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch(opcao) {
            case 1:
            salvarMedicos(medicos, total, "w");
            printf("\nDados atualizados com sucesso\n");
            case 2:
                printf("Atualização descartada\n");
                break;
                
            default:
                printf("Opção inválida\n");
                continue;
        }
    } while(opcao < 1 || opcao > 2);
    free(medicos);
    
}


void removerMedico(){

    verificarArquivo("Arquivos/Medicos.txt", "Nome,CRM,Especialidade,Contato\n");

    Medico *medicos = NULL;
    int total = 0;
    carregarMedicos(&medicos, &total);

    if(total == 0) {
        printf("Nenhum médico cadastrado!\n");
        return;
    }

    while (getchar() != '\n');
    //obter CRM para remoção e usar para remover medico
    char crm[7];
    printf("\nRemoção de Médico\n");
    printf("Digite o CRM do médico (6 dígitos): ");
    entradaLimitada(crm, sizeof(crm));

    int encontrado = -1;
    for(int i = 0; i < total; i++) {
        if(strcmp(medicos[i].crm, crm) == 0) {
            encontrado = i;
            break;
        }
    }

    if(encontrado == -1) {
        printf("Médico não encontrado!\n");
        free(medicos);
        return;
    }

    //confirmar remoção
    int opcao;
    do {
        printf("\nDeseja realmente remover o médico %s?\n", medicos[encontrado].nome);
        printf("1. Confirmar\n");
        printf("2. Cancelar\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar();
    } while(opcao < 1 || opcao > 2);

    if(opcao == 2) {
        printf("Operação cancelada.\n");
        free(medicos);
        return;
    }

    // novo vetor sem o medico
    Medico *novoVetor = malloc((total - 1) * sizeof(Medico));
    if(!novoVetor) {
        printf("Erro de memória!\n");
        free(medicos);
        return;
    }
    int j = 0;
    for(int i = 0; i < total; i++) {
        if(i != encontrado) {
            novoVetor[j++] = medicos[i];
        }
    }

    //salvar
    salvarMedicos(novoVetor, total - 1, "w");
    free(medicos);
    free(novoVetor);
    
    printf("\nMédico removido com sucesso!\n");
}



void menuMedico(){
    int opcao;
    do
    {
        printf("\nMenu Principal de Médicos\n");
        printf("1. Cadastrar Medico\n");
        printf("2. Atualizar Medico\n");
        printf("3. Remover Medico\n");
        printf("4. listar Medicos\n");
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
            listarMedicos();
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);
}