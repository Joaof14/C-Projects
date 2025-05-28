#include "Relatorios.h"


enum statusConsulta { AGENDADA, REALIZADA, CANCELADA
};

typedef struct {
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
} DataHora;

typedef struct {
    int id;
    char pacienteCPF[12];
    char medicoCRM[7];
    DataHora data_hora;
    enum statusConsulta status;
} Consulta;



void salvarConsultas(Consulta *consultas, int total, const char *modo);

void listarConsultas();

const char* statusConsultaParaTexto(enum statusConsulta status);

void cancelarConsulta() ;

void menuConsultas();
