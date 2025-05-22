// paciente.h
#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct {
    char nome[100];
    char cpf[15];
    char telefone[20];
} Paciente;

void menuPaciente();
void cadastrarPaciente();
void removerPaciente();
void editarPaciente();


#endif

