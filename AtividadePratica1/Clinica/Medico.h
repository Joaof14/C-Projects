// medico.h
#ifndef MEDICO_H
#define MEDICO_H

enum ESPECIALIDADE {CLINICO, PEDIATRA, CARDIOLOGISTA, DERMATOLOGISTA, PSIQUIATRA, ORTOPEDISTA};

typedef struct 
{
    char nome[100];
    char crm[7];
    enum ESPECIALIDADE especialidade;
    char contato[20];

} Medico;


void cadastrarMedico();

void listarMedicos();

void atualizarMedico();

void removerMedico();

void menuMedico();

const char* especialidadeParaTexto(enum ESPECIALIDADE esp);


#endif