#include "Relatorios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "Auxiliar.h"


void relatorioConsultaPacientes() {
    char cpfBusca[12];
    printf("\nDigite o CPF do paciente para buscar suas consultas: ");
    fgets(cpfBusca, sizeof(cpfBusca), stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = 0;

    // Busca o ID do paciente pelo CPF
    int idPaciente = buscaPacienteCPF(cpfBusca);
    if (idPaciente == -1) {
        printf("Paciente não encontrado!\n");
        return;
    }

    // Busca os dados do paciente pelo ID
    Paciente paciente = buscaPacienteId(idPaciente);
    if (paciente.cpf[0] == '\0') {
        printf("Erro ao buscar dados do paciente!\n");
        return;
    }

    // Abre o arquivo de consultas
    FILE *arquivo = fopen("Arquivos/Consultas.txt", "r");
    if (!arquivo) {
        printf("Erro ao abrir arquivo de consultas!\n");
        return;
    }

    // Pula o cabeçalho
    char buffer[256];
    fgets(buffer, sizeof(buffer), arquivo);

    printf("\n=== Consultas do Paciente ===\n");
    printf("Nome: %s\n", paciente.nome);
    printf("CPF: %s\n", paciente.cpf);
    printf("Contato: %s\n", paciente.contato);
    printf("--------------------------------\n");

    // Variáveis para ler cada linha do arquivo
    int id, idMed, idPac, dia, mes, ano, hora, min, status;
    int encontrouConsulta = 0;

    // Lê cada consulta do arquivo
    while (fscanf(arquivo, "%d,%d,%d,%d/%d/%d %d:%d,%d\n",
           &id, &idMed, &idPac, &dia, &mes, &ano, &hora, &min, &status) == 9) {
        
        if (idPac == idPaciente) {
            encontrouConsulta = 1;
            
            // Busca dados do médico
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

    if (!encontrouConsulta) {
        printf("Nenhuma consulta encontrada para este paciente.\n");
    }

    fclose(arquivo);
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


