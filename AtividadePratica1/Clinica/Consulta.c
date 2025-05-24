#include "Relatorios.h"
#include "Consulta.h"


void listarConsultas(){
    
}

void agendarConsulta(){

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
            case 4: //Remover depois
                listarConsulta();
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

}