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
    char pacienteCPF[11];
    char medicoCRM[6];
    DataHora data_hora;
    enum statusConsulta status;
} Consulta;

void listarConsultas();

void agendarConsulta();

void registrarConsulta();

void cancelarConsulta() ;

void menuConsultas();
