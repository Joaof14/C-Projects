#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Paciente.h"
#include "Auxiliar.h"




void carregarPacientes(Paciente **pacientes, int *total) {
    FILE *arquivo = fopen("Arquivos/Pacientes.txt", "r");
    if (!arquivo) {
        *total = 0;
        *pacientes = NULL;
        return;
    }

    // Pular cabeçalho (primeira linha)
    char buffer[256];
    fgets(buffer, sizeof(buffer), arquivo);

    *total = 0;
    Paciente temp;
    

    // Ler cada linha do arquivo
    while (fscanf(arquivo, "%99[^,],%11[^,],%19[^\n]\n", 
                temp.nome, 
                temp.cpf,  
                temp.contato) == 3) {


        // Alocar espaço para mais um médico
        *pacientes = realloc(*pacientes, (*total + 1) * sizeof(Paciente));
        
        // Adicionar ao array
        (*pacientes)[*total] = temp;
        (*total)++;
    }

    fclose(arquivo);
}

void salvarPacientes(Paciente *pacientes, int total, const char *modo) {

    
    FILE *arquivo = fopen("Arquivos/Pacientes.txt", modo);
    if (!arquivo) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    //se for modo write, reescreve o cabeçalho
    if (strcmp(modo, "w") == 0) {
        fprintf(arquivo, "Nome,CPF,Contato\n");
    }

    //escreve os médicos
    for (int i = 0; i < total; i++) {
        fprintf(arquivo, "\n%s,%s,%s", 
            pacientes[i].nome, 
            pacientes[i].cpf, 
            pacientes[i].contato);
    }

    fclose(arquivo);
}



void cadastrarPaciente()
{
    verificarArquivo("Arquivos/Pacientes.txt", "Nome,CPF,Contato");

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

    // coleta do CPF com validações
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

    // coleta do contato
    do {
        printf("contato (só numeros): ");
        entradaLimitada(novo->contato, 20);
    } while (strlen(novo->contato) == 0);


    int opcao;
    do {
        printf("\n1. Salvar\n");
        printf("2. Sair sem salvar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); 

        switch(opcao) {
            case 1:
                salvarPacientes(novo, 1, "a");
                printf("Paciente salvo com sucesso!\n");
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
                  paciente.contato) == 3) 
    {
        printf("Paciente %d:\n", contador++);
        printf("Nome: %s\n", paciente.nome);
        printf("CPF: %s\n", paciente.cpf);
        printf("contato: %s\n\n", paciente.contato);
    }

    fclose(arquivo);
}


void atualizarPaciente() {
    Paciente *pacientes = NULL;
    int total = 0;
    carregarPacientes(&pacientes, &total);

    if (total == 0) {
        printf("Nenhum paciente cadastrado para atualizar.\n");
        return;
    }

    while (getchar() != '\n');

    char cpfBusca[12];
    printf("\n--- Atualização de Paciente ---\n");
    printf("Digite o CPF do paciente que deseja atualizar: ");
    entradaLimitada(cpfBusca, sizeof(cpfBusca));

    int encontrado = -1;
    for (int i = 0; i < total; i++) {
        if (strcmp(pacientes[i].cpf, cpfBusca) == 0) {
            encontrado = i;
            break;
            
    }
}
    if (encontrado == -1) {
        printf("Paciente com CPF %s não encontrado.\n", cpfBusca);
        free(pacientes);
        return;
    }

    Paciente atualizado = pacientes[encontrado];

    //coletar novos dados (mesma sequência do cadastro)
    printf("\nAtualizar Dados\n");

    //atualizar nome
    printf("Nome atual: %s\n", atualizado.nome);
    do {
        printf("Novo nome (máx 99 caracteres): ");
        entradaLimitada(atualizado.nome, sizeof(atualizado.nome));
        if(strlen(atualizado.nome) == 0) {
            printf("Nome não pode ser vazio!\n");
        }
    } while(strlen(atualizado.nome) == 0);

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
    pacientes[encontrado] = atualizado;

    int opcao;
            do {
                printf("\n1. Salvar alterações\n");
                printf("2. Cancelar\n");
                printf("Escolha: ");
                scanf("%d", &opcao);
                getchar(); // limpar buffer

                switch (opcao) {
                    case 1:
                        salvarPacientes(pacientes, total, "w");
                        printf("Paciente atualizado com sucesso!\n");
                        break;
                    case 2:
                        printf("Alterações canceladas.\n");
                        break;
                    default:
                        printf("Opção inválida!\n");
                }
            } while (opcao != 1 && opcao != 2);
            free(pacientes);
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
        printf("4. Listar Pacientes\n");
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