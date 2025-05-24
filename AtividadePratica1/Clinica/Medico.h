// medico.h
#ifndef MEDICO_H
#define MEDICO_H

enum ESPECIALIDADE {CLÍNICO, PEDIATRA, CARDIOLOGISTA};

struct Medico
{
    char Nome[100];
    char CRM[6];
    enum ESPECIALIDADE especialidade;
    char Telefone[11];

};


void cadastrarMedico();

void listarMedicos();

void atualizarMedico();

void removerMedico();

void menuMedico();


#endif