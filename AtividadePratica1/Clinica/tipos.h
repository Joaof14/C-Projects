#ifndef TIPOS_H
#define TIPOS_H


//setor de pacientes
typedef struct {
    char nome[100];
    char cpf[12];
    char contato[20];
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



#endif


