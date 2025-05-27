#include "Relatorios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Auxiliar.h"

void relatorioConsultaPacientes() {

    
    FILE *file = fopen("Consultas.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de consultas.\n");
        return;
    }

    char linha[256];
    char cpf[11];
    printf("Digite o CPF do paciente: ");
    scanf("%s", cpf);

    printf("Consultas do Paciente com CPF %s:\n", cpf);
    while (fgets(linha, sizeof(linha), file)) {
        char id[10], pacienteCPF[11], pacienteNome[50], medicoCRM[6], medicoNome[50], especialidade[30];
        char dataHora[20], status[10];
        sscanf(linha, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", id, pacienteCPF, pacienteNome, medicoCRM, medicoNome, especialidade, dataHora, status);
        
        if (strcmp(pacienteCPF, cpf) == 0) {
            printf("ID: %s, Paciente: %s (%s), Medico: %s (%s), Especialidade: %s, Data/Hora: %s, Status: %s\n",
                   id, pacienteNome, pacienteCPF, medicoNome, medicoCRM, especialidade, dataHora, status);
        }
    }

    fclose(file);
  
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


