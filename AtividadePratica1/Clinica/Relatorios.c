#include "Relatorios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "Auxiliar.h"


void relatorioConsultaPacientes() {

    char cpfBusca[30];
    printf("Digite o CPF do paciente para listar as consultas: ");
    fgets(cpfBusca, sizeof(cpfBusca), stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = 0;

    FILE *fcon = fopen("Consultas.txt", "r");
    if (fcon == NULL) {
        printf("Nenhuma consulta cadastrada ou erro ao abrir o arquivo!\n");
        return;
    }

    char linha[512];
    int encontrou = 0;
    printf("\nConsultas do paciente CPF: %s\n", cpfBusca);
    printf("--------------------------------------------------\n");
    while (fgets(linha, sizeof(linha), fcon)) {
        int id;
        char cpf[30], nomePaciente[100], crm[30], nomeMedico[100], data[15], hora[10], status[20];
        int campos = sscanf(linha, "%d,%29[^,],%99[^,],%29[^,],%99[^,],%14[^,],%9[^,],%19[^\n]",
            &id, cpf, nomePaciente, crm, nomeMedico, data, hora, status);
        if (campos == 8 && strcmp(cpf, cpfBusca) == 0) {
            printf("ID: %d\n", id);
            printf("Paciente: %s (CPF: %s)\n", nomePaciente, cpf);
            printf("Médico: %s (CRM: %s)\n", nomeMedico, crm);
            printf("Data: %s\n", data);
            printf("Hora: %s\n", hora);
            printf("Status: %s\n", status);
            printf("-----------------------------\n");
            encontrou = 1;
        }
    }
    fclose(fcon);

    if (!encontrou) {
        printf("Nenhuma consulta encontrada para este paciente.\n");
    }

  
}

void relatorioConsultaMedicos() {

    printf("Relatorio de Medicos.\n");


}

void relatorioConsultaPorEspecialidae() {

    printf("Relatorio Por especialidade.\n");

}

void relatorioConsultaDiaAtual() {

    printf("Relatorio de Consulta.\n");


}

   
void menuRelatorios() {
    int opcao;
    do
    {
        printf("\nMenu Principal\n");
        printf("1. Relatório de Consultas (Pacientes)\n");
        printf("2. Relatório de Consultas (Medicos)\n");
        printf("3. Relatório de Consulta (Especialidade)\n");
        printf("4. Relatório de Consulta Dia Atual\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 0:
                printf("Voltando");
                break;
            case 1:
                relatorioConsultaPacientes();
                break;
            case 2:
                void relatorioConsultaMedicos();
                break;
            case 3:
                void relatorioConsultaPorEspecialidae();
                break;
            case 4:
               void relatorioConsultaDiaAtual();
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);
      
}


