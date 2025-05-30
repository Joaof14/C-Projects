#ifndef TIPOS_H
#define TIPOS_H


//setor de pacientes
typedef struct {
    int id; // ID do paciente
    char nome[100]; // Nome do paciente
    char cpf[12]; // CPF do paciente (apenas números)
    char contato[20]; // Contato do paciente (apenas números)
} Paciente;

//Setor de médico
enum ESPECIALIDADE {CLINICO, PEDIATRA, CARDIOLOGISTA, DERMATOLOGISTA, PSIQUIATRA, ORTOPEDISTA};

typedef struct 
{
    char nome[100];
    char crm[7];
    enum ESPECIALIDADE especialidade;
    char contato[20];

} Medico;


//setor de consultas
enum statusConsulta { AGENDADA, REALIZADA, CANCELADA
};

typedef struct {
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
} DataHora;

typedef struct {
    int id;
    char pacienteCPF[12];
    char medicoCRM[7];
    DataHora data_hora;
    enum statusConsulta status;
} Consulta;


//Setor de relatório


#endif


