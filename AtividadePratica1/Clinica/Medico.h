// medico.h
#ifndef MEDICO_H
#define MEDICO_H

void carregarMedicos(Medico **medicos, int *total);

void salvarMedicos(Medico *medicos, int total, const char *modo);

void cadastrarMedico();

void listarMedicos();

void atualizarMedico();

void removerMedico();

void menuMedico();

const char* especialidadeParaTexto(enum ESPECIALIDADE esp);


#endif