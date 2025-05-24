#include "Relatorios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void relatorioConsultaPacientes() {

    printf("Relatorio de Consultas.\n");

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
        printf("Menu Principal\n");
        printf("1. Relatório de Consultas (Pacientes)\n");
        printf("2. Relatório de Consultas (Medicos)\n");
        printf("3. Relatório de Consulta (Especialidade)\n");
        printf("4. Relatório de Consulta Dia Atual\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
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


