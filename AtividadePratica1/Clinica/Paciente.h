// paciente.h
#ifndef PACIENTE_H
#define PACIENTE_H


void salvarPacientes(Paciente *pacientes, int total, const char *modo);

void carregarPacientes(Paciente **pacientes, int *total);

void cadastrarPaciente();

void listarPaciente();

void atualizarPaciente();

void removerPaciente();

void menuPaciente();

#endif