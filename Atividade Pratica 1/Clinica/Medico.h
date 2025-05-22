// medico.h
#ifndef MEDICO_H
#define MEDICO_H

enum ESPECIALIDADE {CLÍNICO, PEDIATRA, CARDIOLOGISTA};

struct Medico
{
    char Nome[200];
    char CRM[14];
    enum ESPECIALIDADE especialidade;

};


void cadastrarMedico();

void listarMedicos();

void atualizarMedicos();

void removerMedicos();

void Medico();


#endif