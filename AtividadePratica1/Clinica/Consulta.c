#include "Relatorios.h"
#include "Consulta.h"
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Auxiliar.h"
#include "Medico.h"
#include "Paciente.h"


const char* statusConsultaParaTexto(enum statusConsulta status) {
    switch(status) {
        case AGENDADA: return "AGENDADA";
        case REALIZADA: return "REALIZADA";
        case CANCELADA: return "CANCELADA";
        default: return "DESCONHECIDO";
    }
}

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
    while(fscanf(arquivo, "%d,%11[^,],%6[^,],%d/%d/%d %d:%d,%d\n",
    &temp.id,
        temp.pacienteCPF,
        temp.medicoCRM,
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
        fprintf(arquivo, "ID,PacienteCPF,MedicoCRM,Data,Status\n");
    }

    //escreve as consultas
    for (int i = 0; i < total; i++) {
        fprintf(arquivo, "%d,%s,%s,%02d/%02d/%04d %02d:%02d,%d\n", 
                consultas[i].id, 
                consultas[i].pacienteCPF,
                consultas[i].medicoCRM, 
                consultas[i].data_hora.dia,
                consultas[i].data_hora.mes,
                consultas[i].data_hora.ano,
                consultas[i].data_hora.hora,
                consultas[i].data_hora.minuto,     
                consultas[i].status);
    }

    fclose(arquivo);
}




void listarConsultas(){
    Consulta *consultas = NULL;
    int total;
    carregarConsultas(&consultas, &total);

    printf("\nLista de Consultas:\n");
    for (int i = 0; i < total; i++)
    {
        printf("\nID: %d", consultas[i].id);
        printf("Médico (CRM): %s\n", consultas[i].medicoCRM);
        printf("Paciente (CPF): %s\n", consultas[i].pacienteCPF);
        printf("\nData: %02d/%02d/%04d %02d:%02d", consultas[i].data_hora.dia, consultas[i].data_hora.mes, consultas[i].data_hora.ano, consultas[i].data_hora.hora, consultas[i].data_hora.minuto);
        printf("Status: %s\n", statusConsultaParaTexto(consultas[i].status));
    }

}

void agendarConsulta(){

/* char cpf[30], crm[30], data[15], hora[10], status[20] = "Agendada";
    char nomePaciente[100], nomeMedico[100];
    int pacienteEncontrado = 0, medicoEncontrado = 0;

 printf("O Paciente Ja esta cadastrado? (S/N): ");
        char op;
        scanf(" %c", &op);
        if (op == 'n' || op == 'N') {
            cadastrarPaciente();
            printf("Digite Novamente CPF do paciente: ");
            fgets(cpf, sizeof(cpf), stdin);
            cpf[strcspn(cpf, "\n")] = 0;

            // Busca as informações do paciente cadastrado no arquivo para coletar o nome
            fpac = fopen("Arquivos/Pacientes.txt", "r");
            while (fgets(linha, sizeof(linha), fpac)) {
                char nome[100], cpfArq[30], contato[30];
                sscanf(linha, "%99[^,],%29[^,],%29[^\n]", nome, cpfArq, contato);
                if (strcmp(cpf, cpfArq) == 0) {
                    strcpy(nomePaciente, nome);
                    pacienteEncontrado = 1;
                    break;
                }
            }
            fclose(fpac);
            if (!pacienteEncontrado) {
                printf("Paciente ainda não encontrado. Cancelando agendamento.\n");
                return;
            } 
        } else if (op == 's' || op == 'S') {

    // CPF do paciente 
    printf("Digite o CPF do paciente Para a Consulta: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    // Procurar paciente no arquivo para coletar o nome
    FILE *fpac = fopen("Arquivos/Pacientes.txt", "r");
    if (fpac == NULL) {
        printf("Erro ao abrir o arquivo de pacientes!\n");
        return;
    }
    char linha[256];
    while (fgets(linha, sizeof(linha), fpac)) {
        char nome[100], cpfArq[30], contato[30];
        sscanf(linha, "%99[^,],%29[^,],%29[^\n]", nome, cpfArq, contato);
        if (strcmp(cpf, cpfArq) == 0) {
            strcpy(nomePaciente, nome);
            pacienteEncontrado = 1;
            break;
        }
    }
    fclose(fpac);

           
    } 

   
    // CRM do médico 
    printf("Digite o CRM do médico: ");
    fgets(crm, sizeof(crm), stdin);
    crm[strcspn(crm, "\n")] = 0;

    // Procurar médico no arquivo
    FILE *fmed = fopen("Arquivos/Medicos.txt", "r");
    if (fmed == NULL) {
        printf("Erro ao abrir o arquivo de médicos!\n");
        return;
    }
    while (fgets(linha, sizeof(linha), fmed)) {
        char nome[100], crmArq[30], especialidade[50];
        sscanf(linha, "%99[^,],%29[^,],%49[^\n]", nome, crmArq, especialidade);
        if (strcmp(crm, crmArq) == 0) {
            strcpy(nomeMedico, nome);
            medicoEncontrado = 1;
            break;
        }
    }
    fclose(fmed);

    if (!medicoEncontrado) {
        printf("Médico não encontrado. Cancelando agendamento.\n");
        return;
    }

    // Pede a Data e hora da consulta
    printf("Digite a data da consulta (DD/MM/AAAA): ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = 0;

    printf("Digite a hora da consulta (HH:MM): ");
    fgets(hora, sizeof(hora), stdin);
    hora[strcspn(hora, "\n")] = 0;

    //Gerar ID sequencial
    int novoId = 1;
    FILE *fcon = fopen("Consultas.txt", "r");
    if (fcon) {
        while (fgets(linha, sizeof(linha), fcon)) {
            int idTemp;
            sscanf(linha, "%d,", &idTemp);
            if (idTemp >= novoId) novoId = idTemp + 1;
        }
        fclose(fcon);
    }

    // Salva a consulta
    fcon = fopen("Consultas.txt", "a");
    if (!fcon) {
        printf("Erro ao abrir arquivo de consultas.\n");
        return;
    }
    fprintf(fcon, "%d,%s,%s,%s,%s,%s,%s,%s\n", novoId, cpf, nomePaciente, crm, nomeMedico, data, hora, status);
    fclose(fcon);

    printf("Consulta agendada com sucesso!\n");*/
    
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
                registrarConsulta();
                break;
            case 3:
                cancelarConsulta();
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