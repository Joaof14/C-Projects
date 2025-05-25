// paciente.h
#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct {
    char nome[100];
    char cpf[11];
    char Telefone[11];
} Paciente;

void cadastrarPaciente();

void listarPaciente();

void atualizarPaciente();

void removerPaciente();

void menuPaciente();

#endif