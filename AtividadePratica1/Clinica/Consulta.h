#ifndef CONSULTA_H
#define CONSULTA_H



void salvarConsultas(Consulta *consultas, int total, const char *modo);

void listarConsultas();

const char* statusConsultaParaTexto(enum statusConsulta status);

void cancelarConsulta() ;

void menuConsultas();

#endif