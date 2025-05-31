#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"
#include "Medico.h"
#include "Auxiliar.h"




void salvarMedicos(Medico *medicos, int total, const char *modo) {

    
    
    FILE *arquivo = fopen("Arquivos/Medicos.txt", modo);
    if (!arquivo) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    //se for modo write, reescreve o cabeçalho
    if (strcmp(modo, "w") == 0) {
        fprintf(arquivo, "Id,Nome,CRM,Especialidade,Contato\n");
    }

    //escreve os médicos
    for (int i = 0; i < total; i++) {
        // Gerar ID se for novo registro
        if (medicos[i].id == 0) {
            medicos[i].id = gerarNovoId("Arquivos/Medicos.txt");
        }
        
        fprintf(arquivo, "%d,%s,%s,%d,%s\n", 
                medicos[i].id,
                medicos[i].nome, 
                medicos[i].crm, 
                medicos[i].especialidade, 
                medicos[i].contato);
    }

    fclose(arquivo);
}

void cadastrarMedico()
{
    verificarArquivo("Arquivos/Medicos.txt", "Id,Nome,CRM,Especialidade,Contato\n");

    // alocar memória para o Medico
    Medico *novo = (Medico*)malloc(sizeof(Medico));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }
    novo->id = 0;
    // coletar dados usando ponteiros
    printf("Digite os dados do novo medico:\n");
    while (getchar() != '\n');
    
    // coleta do nome com validações
    receberNome(novo->nome);

    // coleta do CRM com validações
    receberCRM(novo->crm, 0);

    // coleta da especialidade
    receberEspecialidade(&novo->especialidade);

    // coleta do contato com validações
    receberContato(novo->contato);

    // exibir os dados coletados
    exibirMedico(*novo);

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
        exibirMedico(medicos[i]);
    }
    
    free(medicos); //liberar memória alocada
}



  
void atualizarMedico() {

    verificarArquivo("Arquivos/Medicos.txt", "Nome,CRM,Especialidade,Contato\n");

    Medico *medicos = NULL;
    int total = 0;
    carregarMedicos(&medicos, &total);

    

    //Buscar médico pelo crm
    char crmBusca[7];
    printf("\n--- Atualização de Médico ---\n");
    while (getchar() != '\n');
    printf("Digite o CRM (6 dígitos): ");
    receberCRM(crmBusca, 0);
    
    int encontrado = -1;
    for(int i = 0; i < total; i++) {
        if(strcmp(medicos[i].crm, crmBusca) == 0) {
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
    receberNome(atualizado.nome);

    // coleta do CRM com validações
    receberCRM(atualizado.crm, 0);

    //atualizar especialidade
    printf("\nEspecialidade atual: %s\n", especialidadeParaTexto(atualizado.especialidade));
    receberEspecialidade(&atualizado.especialidade);

    //atualizar contato
    printf("\nContato atual: %s\n", atualizado.contato);
    receberContato(atualizado.contato);
    

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
    char crmBusca[7];
    printf("\nRemoção de Médico\n");
    printf("Digite o CRM do médico (6 dígitos): ");
    receberCRM(crmBusca, 1);

    int encontrado = -1;
    for(int i = 0; i < total; i++) {
        if(strcmp(medicos[i].crm, crmBusca) == 0) {
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