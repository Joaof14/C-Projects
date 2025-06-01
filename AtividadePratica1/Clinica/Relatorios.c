#include "Relatorios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "Auxiliar.h"


void relatorioConsultaPacientes() {
    char cpfBusca[12];
    printf("\nDigite o CPF do paciente para buscar suas consultas: ");
    setbuf(stdin, NULL);
    
    if (fgets(cpfBusca, sizeof(cpfBusca), stdin) == NULL) {
        printf("Erro ao ler CPF!\n");
        return;
    }
    cpfBusca[strcspn(cpfBusca, "\n")] = 0;

    int idPaciente = buscaPacienteCPF(cpfBusca);
    if (idPaciente == -1) {
        printf("Paciente não encontrado!\n");
        return;
    }

    Paciente paciente = buscaPacienteId(idPaciente);
    if (paciente.cpf[0] == '\0') {
        printf("Erro ao buscar dados do paciente!\n");
        return;
    }

    FILE *arquivo = fopen("Arquivos/Consultas.txt", "r");
    if (!arquivo) {
        printf("Erro ao abrir arquivo de consultas!\n");
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), arquivo); // Pula cabeçalho

    printf("\n--- Consultas do Paciente ---\n");
    printf("Nome: %s\n", paciente.nome);
    printf("CPF: %s\n", paciente.cpf);
    printf("Contato: %s\n", paciente.contato);
    printf("--------------------------------\n");

    int id, idMed, idPac, dia, mes, ano, hora, min, status;
    int encontrouConsulta = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "%d,%d,%d,%d/%d/%d %d:%d,%d",
            &id, &idPac, &idMed, &dia, &mes, &ano, &hora, &min, &status) == 9) {
            if (idPac == idPaciente) {
                encontrouConsulta = 1;
                Medico medico = buscaMedicoId(idMed);
                
                printf("\nConsulta ID: %d\n", id);
                printf("Médico: %s (CRM: %s)\n", medico.nome, medico.crm);
                printf("Especialidade: %s\n", especialidadeParaTexto(medico.especialidade));
                printf("Data: %02d/%02d/%04d\n", dia, mes, ano);
                printf("Hora: %02d:%02d\n", hora, min);
                printf("Status: %s\n", statusConsultaParaTexto(status));
                printf("--------------------------------\n");
            }
        }
    }

    if (!encontrouConsulta) {
        printf("Nenhuma consulta encontrada para este paciente.\n");
    }
    fclose(arquivo);
}

void relatorioConsultaMedicos() {
    char crmBusca[12];
    printf("\nDigite o CRM do médico para buscar suas consultas: ");
    setbuf(stdin, NULL);
    
    if (fgets(crmBusca, sizeof(crmBusca), stdin) == NULL) {
        printf("Erro ao ler CRM!\n");
        return;
    }
    crmBusca[strcspn(crmBusca, "\n")] = 0;

    int idMedico = buscaMedicoCRM(crmBusca);
    if (idMedico == -1) {
        printf("Médico não encontrado!\n");
        return;
    }

    Medico medico = buscaMedicoId(idMedico);
    if (medico.crm[0] == '\0') {
        printf("Erro ao buscar dados do médico!\n");
        return;
    }

    FILE *arquivo = fopen("Arquivos/Consultas.txt", "r");
    if (!arquivo) {
        printf("Erro ao abrir arquivo de consultas!\n");
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), arquivo); // Pula cabeçalho

    printf("\n=== Consultas do Médico ===\n");
    printf("Nome: %s\n", medico.nome);
    printf("CRM: %s\n", medico.crm);
    printf("Especialidade: %s\n", especialidadeParaTexto(medico.especialidade));
    printf("--------------------------------\n");

    int id, idMed, idPac, dia, mes, ano, hora, min, status;
    int encontrouConsulta = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "%d,%d,%d,%d/%d/%d %d:%d,%d",
            &id, &idPac, &idMed, &dia, &mes, &ano, &hora, &min, &status) == 9) {
            if (idMed == idMedico) {
                encontrouConsulta = 1;
                Paciente paciente = buscaPacienteId(idPac);
                
                printf("\nConsulta ID: %d\n", id);
                printf("Paciente: %s (CPF: %s)\n", paciente.nome, paciente.cpf);
                printf("Contato: %s\n", paciente.contato);
                printf("Data: %02d/%02d/%04d\n", dia, mes, ano);
                printf("Hora: %02d:%02d\n", hora, min);
                printf("Status: %s\n", statusConsultaParaTexto(status));
                printf("--------------------------------\n");
            }
        }
    }

    if (!encontrouConsulta) {
        printf("Nenhuma consulta encontrada para este médico.\n");
    }
    fclose(arquivo);
}

void relatorioConsultaPorEspecialidae() {
 // -Gerar relatório com contagem de consultas por especialidade Criar um arquivo de texto que contenha o relatório de consultas por especialidade, mostrando a quantidade de consultas realizadas para cada especialidade.
    printf("Relatorio Por especialidade.\n");

}

void relatorioConsultaDiaAtual() {

    printf("Relatorio de Consulta.\n");


}

   
void menuRelatorios() {
    int opcao = -1;
    char input[10];
    do {
        printf("\nMenu Relatórios\n");
        printf("1. Relatório de Consultas (Pacientes)\n");
        printf("2. Relatório de Consultas (Médicos)\n");
        printf("3. Relatório de Consulta (Especialidade)\n");
        printf("4. Relatório de Consulta Dia Atual\n");
        printf("0. Voltar\n");
        printf("Escolha uma opção: ");
        
        setbuf(stdin, NULL);
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Erro ao ler opção!\n");
            continue;
        }
        
        opcao = atoi(input);

        switch (opcao) {
            case 0:
                printf("Voltando...\n");
                break;
            case 1:
                relatorioConsultaPacientes();
                break;
            case 2:
                relatorioConsultaMedicos();
                break;
            case 3:
                relatorioConsultaPorEspecialidae();
                break;
            case 4:
                relatorioConsultaDiaAtual();
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

