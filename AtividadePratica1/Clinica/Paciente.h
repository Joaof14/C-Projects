// paciente.h
#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct {
    char nome[100];
    char cpf[12];
    char telefone[20];
} Paciente;

void cadastrarPaciente();

void listarPaciente();

void atualizarPaciente();

void removerPaciente();

void menuPaciente();

#endif