#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"
#include "Paciente.h"
#include "Auxiliar.h"




void carregarPacientes(Paciente **pacientes, int *total) {
    FILE *arquivo = fopen("Arquivos/Pacientes.txt", "r");
    if (!arquivo) {
        *total = 0;
        *pacientes = NULL;
        return;
    }

    //pular cabeçalho (primeira linha)
    char buffer[256];
    fgets(buffer, sizeof(buffer), arquivo);

    *total = 0;
    Paciente temp;

    //ler cada linha do arquivo
    while (fscanf(arquivo, "%99[^,],%11[^,],%19[^\n]\n", 
                temp.nome, 
                temp.cpf,  
                temp.contato) == 3) {


        //alocar espaço para mais um médico e adicionar
        *pacientes = realloc(*pacientes, (*total + 1) * sizeof(Paciente));
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
        fprintf(arquivo, "%s,%s,%s\n", 
            pacientes[i].nome, 
            pacientes[i].cpf, 
            pacientes[i].contato);
    }

    fclose(arquivo);
}



void cadastrarPaciente()
{
    verificarArquivo("Arquivos/Pacientes.txt", "Nome,CPF,Contato\n");

    //alocar memória para o paciente
    Paciente *novo = (Paciente*)malloc(sizeof(Paciente));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    //coletar dados usando ponteiros
    printf("\n Novo Paciente \n");
    do {
        printf("Nome (máx 99 caracteres): ");
        entradaLimitada(novo->nome, 100);
    }
    while (strlen(novo->nome) == 0); 

    //coleta do CPF com validações
    receberCPF(novo->cpf);

    //coleta do contato
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
   Paciente *pacientes = NULL;
    int total;
    carregarPacientes(&pacientes, &total);   
    FILE *arquivo = fopen("Arquivos/Pacientes.txt", "r");
    if (total == 0) {
        printf("Nenhum paciente cadastrado!\n");
        return;
    }
    
    
    printf("\nLista de Pacientes:\n"); 
    for(int i = 0; i < total; i++)
    {
        printf("\nPaciente %d:\n", i+1);
        printf("Nome: %s\n", pacientes[i].nome);
        printf("CPF: %s\n", pacientes[i].cpf);
        printf("contato: %s\n\n", pacientes[i].contato);
    }
    
    free(pacientes); //liberar memória alocada
}


void atualizarPaciente() {

    verificarArquivo("Arquivos/Pacientes.txt", "Nome,CPF,Contato\n");

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
{   verificarArquivo("Arquivos/Pacientes.txt", "Nome,CPF,Contato\n");

    Paciente *pacientes = NULL;
    int total = 0;
    carregarPacientes(&pacientes, &total);

    if (total == 0) {
        printf("Nenhum paciente cadastrado!\n");
        return;
    }

    while (getchar() != '\n');
    // Obter CPF para remoção
    char cpf[12];
    printf("\n--- Remoção de Paciente ---\n");
    printf("Digite o CPF do paciente (somente números): ");
    entradaLimitada(cpf, sizeof(cpf));

    int encontrado = -1;
    for (int i = 0; i < total; i++) {
        if (strcmp(pacientes[i].cpf, cpf) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Paciente não encontrado!\n");
        free(pacientes);
        return;
    }

    //confirmar remoção
    int opcao;
    do {
        printf("\nDeseja realmente remover o paciente %s?\n", pacientes[encontrado].nome);
        printf("1. Confirmar\n");
        printf("2. Cancelar\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        while (getchar() != '\n'); // Limpar buffer
    } while (opcao < 1 || opcao > 2);

    if (opcao == 2) {
        printf("Operação cancelada.\n");
        free(pacientes);
        return;
    }

    //criar novo vetor sem o paciente
    Paciente *novoVetor = malloc((total - 1) * sizeof(Paciente));
    if (!novoVetor) {
        printf("Erro de memória!\n");
        free(pacientes);
        return;
    }
    int j = 0;
    for (int i = 0; i < total; i++) {
        if (i != encontrado) {
            novoVetor[j++] = pacientes[i];
        }
    }

    //salvar 
    salvarPacientes(novoVetor, total - 1, "w");
    free(pacientes);
    free(novoVetor);

    printf("\nPaciente removido com sucesso!\n");

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