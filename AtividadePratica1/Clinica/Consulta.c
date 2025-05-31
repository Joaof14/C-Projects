#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"
#include "Relatorios.h"
#include "Consulta.h"
#include "Auxiliar.h"




void carregarConsultas(Consulta **consultas, int *total)
{
    FILE *arquivo = fopen("Arquivos/Consultas.txt", "r");
    if(!arquivo) 
    {
        *total = 0;
        *consultas = NULL;
        return;
    }
    //pular cabeçalho (primeira linha)
    char buffer[256];
    fgets(buffer, sizeof(buffer), arquivo);

    *total = 0;
    Consulta temp;
    int status_temp;

    //ler cada linha do arquivo
    while(fscanf(arquivo, "%d,%d,%d,%d/%d/%d %d:%d,%d\n",
        &temp.id,
        &temp.pacienteId,
        &temp.medicoId,
        &temp.data_hora.dia,
        &temp.data_hora.mes,
        &temp.data_hora.ano,
        &temp.data_hora.hora,
        &temp.data_hora.minuto,
        &status_temp) == 9) 

        {
            //alocar espaço para mais um médico e adicionar
            *consultas = realloc(*consultas, (*total + 1) * sizeof(Consulta));
            (*consultas)[*total] = temp;
            (*total)++;
    }
    fclose(arquivo);
}

void salvarConsultas(Consulta *consultas, int total, const char *modo) { 
    
    FILE *arquivo = fopen("Arquivos/Consultas.txt", modo);
    if (!arquivo) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    //se for modo write, reescreve o cabeçalho
    if (strcmp(modo, "w") == 0) {
        fprintf(arquivo, "ID,PacienteId,MedicoId,Data Hora,Status\n");
    }

    //escreve as consultas
    for (int i = 0; i < total; i++) {
        fprintf(arquivo, "%d,%d,%d,%02d/%02d/%04d %02d:%02d,%d\n", 
                consultas[i].id, 
                consultas[i].pacienteId,
                consultas[i].medicoId, 
                consultas[i].data_hora.dia,
                consultas[i].data_hora.mes,
                consultas[i].data_hora.ano,
                consultas[i].data_hora.hora,
                consultas[i].data_hora.minuto,     
                consultas[i].status);
    }

    fclose(arquivo);
}


void alterarStatusConsulta(enum statusConsulta novoStatus){
    int id, total;
    printf("\nDigite o id da consulta que voce quer alterar: ");
    scanf("%d",&id);

    //Verificar se id está cadastrada.
    Consulta *consultas = NULL;
    carregarConsultas(&consultas, &total);
    int encontrado = -1;
    for (int i = 0; i < total; i++){
        if(consultas[i].id == id) 
        {
            exibirConsulta(consultas[i]);
            encontrado = i;
            break;
        }
    }
    //Salvamento da alteraçao
    if (encontrado != -1){
        //Confirmar alteração
        printf("\nDeseja alterar o status para %s?", statusConsultaParaTexto(novoStatus));
        int opcao;
        do {
            printf("\n1. Salvar\n");
            printf("2. Sair sem salvar\n");
            printf("selecione uma opção: ");
            scanf("%d", &opcao);
            getchar(); 

            switch(opcao) {
                case 1:
                consultas[encontrado].status = novoStatus;
                salvarConsultas(consultas, total,"w");
                printf("Status atualizado!\n");
                case 2:
                    printf("Atualização de status descartada.\n");
                    break;
                    
                default:
                    printf("Opção inválida!\n");
                    continue;
            }
        } while(opcao < 1 || opcao > 2);
    }
    else {
        printf("Consulta não encontrada");
    }
    free(consultas);

    }

void listarConsultas(){
    Consulta *consultas = NULL;
    int total;
    carregarConsultas(&consultas, &total);

    printf("\nLista de Consultas:\n");
    for (int i = 0; i < total; i++)
    {
        exibirConsulta(consultas[i]);
    }

    free(consultas);

}

void agendarConsulta(){
/* verificarArquivo("Arquivos/Consultas.txt", "Id,PacienteId,MedicoId,Data Hora,Status\n");

    int cadastros = 0;
    printf("\nPaciente e Médico da consulta ja estão cadastrados no sistema?\nDigite: 1-Sim, 2-Não\n");
    scanf("%d", &cadastros);

    if(cadastros != 1){
        printf("\nCadastre primeiro o médico ou paciente!\n");
        return;
    }

    Consulta * nova = (Consulta*)malloc(sizeof(Consulta));
    int totalConsultas;
    
    printf("\nAgendamento do Paciente: \nPreencha com atenção. Em caso de erro o processo deverá ser reiniciado!\n");
    
    while (getchar() != '\n');
    //receber cpf everificar se cpf está nos dados
    printf("Digite o cpf do paciente (apenas números): ");
    entradaLimitada(nova->pacienteId, 12);
    if(!CPFJaCadastrado(nova->pacienteId))
    {
        printf("\nERRO: CPF NÃO ENCONTRADO!\n");
        return;
    }

    printf("Digite o CRM do Médico (apenas números): ");
    entradaLimitada(nova->medicoId, 7);
    if(!CRMJaCadastrado(nova->medicoId))
    {
        printf("\nERRO: CRM NÃO ENCONTRADO!\n");
        free(nova);
        return;
    }
    
    //Coletar data e hora
    printf("Data da consulta (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &nova->data_hora.dia, &nova->data_hora.mes, &nova->data_hora.ano);

    printf("Hora da consulta (HH:MM): ");
    scanf("%d:%d", &nova->data_hora.hora, &nova->data_hora.minuto);

    //Validar data e hora


    //Confirmar salvamento
    int opcao;
    do
    {
        printf("\n1. Salvar\n");
        printf("2. Sair sem salvar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); 

        switch(opcao) {
            case 1:

            //gerar id para consulta
                Consulta *consultas = NULL;
                carregarConsultas(&consultas, &totalConsultas);
        
                if (totalConsultas > 0)
                    {nova->id = consultas[totalConsultas-1].id + 1;}
                free(consultas);

                //Salvar Consultas
                salvarConsultas(nova, 1, "a");
                printf("Consulta salva com sucesso!\n");
                break;
            case 2:
                printf("Agendamento descartado.\n");
                break;
                
            default:
                printf("Opção inválida!\n");
                continue;
        }
    } while(opcao < 1 || opcao > 2);
 
    
    free(nova);
*/
    
    
}   



void registrarConsulta(){
    

}

void cancelarConsulta() {
    
}


void menuConsultas(){
    int opcao;
    do
    {
        printf("\nMenu Principal de Consultas\n");
        printf("1. Agendar Consulta\n");
        printf("2. Cancelar Consulta\n");
        printf("3. Registar Consulta\n");
        printf("4. Listar Consultas Por Paciente\n");
        printf("5. Listar Consultas Por Medico\n");        
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {   case 0:
                return;
                break;
            case 1:
                agendarConsulta();
                break;
            case 2:
                printf("\nCancelamento de consulta!\n");
                alterarStatusConsulta(CANCELADA);
                break;
            case 3:
                printf("\nRegistro de consulta!\n");
                alterarStatusConsulta(REALIZADA);
                break;
            case 4: 
                listarConsultas();
                relatorioConsultaPacientes();
                break;
            case 5:
                relatorioConsultaMedicos();
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }  
    } while (opcao != 5);

}