// paciente.h
#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct {
    char nome[100];
    char cpf[12];
    char contato[20];
} Paciente;

void salvarPacientes(Paciente *pacientes, int total, const char *modo);

void carregarPacientes(Paciente **pacientes, int *total);

void cadastrarPaciente();

void listarPaciente();

void atualizarPaciente();

void removerPaciente();

void menuPaciente();

#endif