// paciente.h
#ifndef PACIENTE_H
#define PACIENTE_H

struct Paciente{
    char nome[100];
    char cpf[11];
    char Telefone[11];
} ;

void cadastrarPaciente();

void listarPaciente();

void atualizarPaciente();

void removerPaciente();

void menuPaciente();

#endif