#include "Relatorios.h"
#include "Consulta.h"
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Auxiliar.h"
#include "Medico.h"
#include "Paciente.h"


void listarConsultas(){

        FILE *fcon = fopen("Consultas.txt", "r");
    if (fcon == NULL) {
        printf("Nenhuma consulta cadastrada ou erro ao abrir o arquivo!\n");
        return;
    }

    char linha[512];
    int encontrou = 0;
    printf("\n--- Lista de Consultas ---\n");
    while (fgets(linha, sizeof(linha), fcon)) {
        int id;
        char cpf[30], nomePaciente[100], crm[30], nomeMedico[100], data[15], hora[10], status[20];

        int campos = sscanf(linha, "%d,%29[^,],%99[^,],%29[^,],%99[^,],%14[^,],%9[^,],%19[^\n]",
            &id, cpf, nomePaciente, crm, nomeMedico, data, hora, status);

        if (campos == 8) {
            printf("-------------------------\n");
            printf("ID: %d\n", id);
            printf("Paciente: %s (CPF: %s)\n", nomePaciente, cpf);
            printf("Médico: %s (CRM: %s)\n", nomeMedico, crm);
            printf("Data: %s\n", data);
            printf("Hora: %s\n", hora);
            printf("Status: %s\n", status);
            printf("-------------------------\n");
            encontrou = 1;
        }
    }
    fclose(fcon);

    if (!encontrou) {
        printf("Nenhuma consulta encontrada.\n");
    }

    
}

void agendarConsulta(){


    char cpf[30], crm[30], data[15], hora[10], status[20] = "Agendada";
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

    printf("Consulta agendada com sucesso!\n");
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