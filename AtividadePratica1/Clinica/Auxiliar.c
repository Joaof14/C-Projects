#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tipos.h"
#include "Auxiliar.h"

// cria um arquivo com cabeçalhos se ele não existir
void verificarArquivo(const char *caminho, const char *colunas) {
    FILE *arquivo = fopen(caminho, "r");
    
    if (arquivo == NULL) {
        arquivo = fopen(caminho, "w");
        if (arquivo != NULL) {
            fprintf(arquivo, "%s", colunas); 
            fclose(arquivo);
        } else {
            printf("Erro ao criar o arquivo: %s\n", caminho);
        }
    } else {
        fclose(arquivo); 
    }
}


// lê entrada do usuário com controle de tamanho
int entradaLimitada(char *destino, int tamanho_max) {
    int i = 0, excesso = 0;
    char c;
    
    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < tamanho_max - 1) {
            destino[i++] = c;
        }
        else{
            excesso = 1;
        }
    }
    destino[i] = '\0';
    return i; 
}



//Função gera id
int gerarNovoId(const char *arquivoPath) {
    FILE *arquivo = fopen(arquivoPath, "r");
    if (!arquivo) return 1; // Primeiro ID se arquivo não existir
    
    int maxId = 0;
    char linha[256];
    
    // Pular cabeçalho
    fgets(linha, sizeof(linha), arquivo);
    
    while (fgets(linha, sizeof(linha), arquivo)) {
        int id;
        if (sscanf(linha, "%d,", &id) == 1) {
            if (id > maxId) maxId = id;
        }
    }
    
    fclose(arquivo);
    return maxId + 1;
}

// Funções relacionadas a entrada CPF

// Valida se o cpf tem 11 dígitos numéricos
int validarCPF(const char *cpf) {
    if (strlen(cpf) != 11) 
    {return 0;}
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) return 0;
    }
    
    return 1; // cpf válido
}

// Verifica se um cpf já existe no arquivo
int CPFJaCadastrado(const char *cpf) {
    FILE *arquivo = fopen("Arquivos/Pacientes.txt", "r");
    if (arquivo == NULL) {return -1;}

    char nome[100], cpfArquivo[12], telefone[20];

    // Pular o cabeçalho
    fscanf(arquivo, "%*[^\n]\n");

    while (fscanf(arquivo, "%99[^,],%11[^,],%19[^\n]\n", nome, cpfArquivo, telefone) == 3) {
        if (strcmp(cpfArquivo, cpf) == 0) {
            fclose(arquivo);
            return 1;
        }
    }

    fclose(arquivo);
    return 0;
}

//Receber CPF
int receberCPF(char *cpf){
    
    int cpfValido = 0;
    do{
        printf("Digite o CPF do paciente (só numeros):\n");
        entradaLimitada(cpf, 12);
        if(!validarCPF(cpf)){
            printf("Erro: CPF deve conter exatamente 11 números!\n");
            continue;
        }
        if (CPFJaCadastrado(cpf)){
            printf("CPF já cadastrado no sistema!\n");
            continue;
        }
        if (CPFJaCadastrado(cpf) == -1){
            printf("Erro na verificação, tente novamente!\n");
            continue;
        }
        cpfValido=1;
        
    }while(!cpfValido);
    return 1;
}


//Funções de CRM


// valida se o CRM tem 6 dígitos numéricos

int validarCRM(const char *crm) {
    if (strlen(crm) != 6) return 0;
    for (int i = 0; i < 6; i++) {
        if (!isdigit(crm[i])) return 0;
    }
    
    return 1; // crm válido
}

// Verifica se um CRM já existe no arquivo
int CRMJaCadastrado(const char *crm) {
    FILE *arquivo = fopen("Arquivos/Medicos.txt", "r");
    if (arquivo == NULL) {return -1;}

    char nome[100], crmArquivo[7], especialidade[100], contato[20];

    // Pular o cabeçalho
    fscanf(arquivo, "%*[^\n]\n");
    while (fscanf(arquivo, "%99[^,],%7[^,],%99[^,],%19[^\n]\n", nome, crmArquivo, especialidade, contato) == 4) {
        if (strcmp(crmArquivo, crm) == 0) {
            fclose(arquivo);
            return 1;
        }
    }

    fclose(arquivo);
    return 0;
}

//Receber CRM
int receberCRM(char *crm){
    
    int crmValido = 0;
    do{
        printf("Digite O CRM do médico (só numeros):\n");
        entradaLimitada(crm, 7);
        if(!validarCRM(crm)){
            printf("CRM deve conter exatamente 6 números!\n");
            continue;
        }
        if (CRMJaCadastrado(crm)){
            printf("CRM já cadastrado no sistema!\n");
            continue;
        }
        if (CRMJaCadastrado(crm)== -1){
            printf("Erro na verificação, tente novamente!\n");
            continue;
        }
        crmValido=1;
        
    }while(!crmValido);
    return 1;
}



//Funções de Entrada nome


//Validar nome
int validarNome(const char *nome) {
    // Verificar tamanho e se contém apenas letras e espaços
    if (strlen(nome) == 0 || strlen(nome) > 99) {
        return 0;
    }
    
    // Verificar se contém apenas espaços
    int apenasEspacos = 1;
    for (int i = 0; i < strlen(nome); i++) {
        if (!isspace(nome[i])) {
            apenasEspacos = 0;
            break;
        }
    }
    if (apenasEspacos) {
        return 0;
    }

    for (int i = 0; i < strlen(nome); i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            return 0;
        }
    }
    
    return 1;
}


//Receber Nome
int receberNome(char *nome){
    do {
        printf("Nome (máx 99 caracteres): ");
        entradaLimitada(nome, 100);

        if (!validarNome(nome)) {
            printf("Erro: Use apenas letras e espaços no nome e não deixe em branco!\n");
            continue;
        }
        break;
    }
    while (1);

    return 1;
    

}

//Funções de entrada Contato


//Validar contato
int validarContato(const char *contato){
    int len = strlen(contato);
    if (len < 10 || len > 19) return 0;
    
    // Verificar se contém apenas dígitos
    for (int i = 0; i < len; i++) {
        if (!isdigit(contato[i])) {
            return 0;
        }
    }
    return 1;
}

//Receber Contato
int receberContato(char *contato) {
    
    do {
        printf("contato (só numeros): ");
        entradaLimitada(contato, 20);
        if (!validarContato(contato)) {
            printf("Erro: Use apenas números!\n");
            continue;
        }
        break;
        
    } while (strlen(contato) == 0);

    return 1;
}




//Funções para Enums

//Converter Especialidade para string
const char* especialidadeParaTexto(enum ESPECIALIDADE esp) {
    switch (esp) {
        case CLINICO: return "CLINICO";
        case PEDIATRA: return "PEDIATRA";
        case CARDIOLOGISTA: return "CARDIOLOGISTA";
        case DERMATOLOGISTA: return "DERMATOLOGISTA";
        case PSIQUIATRA: return "PSIQUIATRA";
        case ORTOPEDISTA: return "ORTOPEDISTA";
        
        default: return "DESCONHECIDO";
    }
}


//Converter status da consulta para texto
const char* statusConsultaParaTexto(enum statusConsulta status) {
    switch(status) {
        case AGENDADA: return "AGENDADA";
        case REALIZADA: return "REALIZADA";
        case CANCELADA: return "CANCELADA";
        default: return "DESCONHECIDO";
    }
}


//Função para receber Especialidade

int receberEspecialidade(enum ESPECIALIDADE *especialidade) {
    printf("Selecione a especialidade:\n");
    for (int i = 0; i < 6; i++) {
        printf("  %d - %s\n", i, especialidadeParaTexto(i));
    }

    int opcao;
    do {
        printf("Digite o número da especialidade: ");
        scanf("%d", &opcao);
        while (getchar() != '\n'); 
        
        if (opcao < 0 || opcao >= 6) {
            printf("Opção inválida. Tente novamente.\n");
        }
        else {
            *especialidade = (enum ESPECIALIDADE)opcao;
            break;
        }
    } while (1);
    
    return 1;
}

//Funções de exibição

void exibirMedico(Medico medico){   
    printf("ID: %d\n", medico.id);
    printf("Nome: %s\n", medico.nome);
    printf("CRM: %s\n", medico.crm);
    printf("Especialidade: %s\n", especialidadeParaTexto(medico.especialidade));
    printf("Contato: %s\n", medico.contato);
}

void exibirPaciente(Paciente paciente){
    printf("ID: %d\n", paciente.id);
    printf("Nome: %s\n", paciente.nome);
    printf("CPF: %s\n", paciente.cpf);
    printf("contato: %s\n\n", paciente.contato);
}

void exibirConsulta(Consulta consulta){
    printf("ID: %d\n", consulta.id);
    printf("Médico (CRM): %s\n", consulta.medicoId);
    printf("Paciente (CPF): %s\n", consulta.pacienteId);
    printf("\nData: %02d/%02d/%04d %02d:%02d\n", consulta.data_hora.dia, consulta.data_hora.mes, consulta.data_hora.ano, consulta.data_hora.hora, consulta.data_hora.minuto);
    printf("Status atual: %s\n", statusConsultaParaTexto(consulta.status));
}



//Funções de busca

//buscaPacienteCPF(){} tem que retornar O ID do paciente
int buscaPacienteCPF(const char *cpf) {
    FILE *arquivo = fopen("Arquivos/Pacientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de pacientes.\n");
        return -1; // Erro ao abrir o arquivo
    }

    char nome[100], cpfArquivo[12], contato[20];
    int id = 0;

    // Pular o cabeçalho
    fscanf(arquivo, "%*[^\n]\n");

    while (fscanf(arquivo, "%d,%99[^,],%11[^,],%19[^\n]\n", &id, nome, cpfArquivo, contato) == 4) {
        if (strcmp(cpfArquivo, cpf) == 0) {
            fclose(arquivo);
            return id; // Retorna o ID do paciente
        }
    }

    fclose(arquivo);
    return -1; // CPF não encontrado
}

//buscaPacienteId(){} tem que retornar um paciente com base no ID
Paciente buscaPacienteId(int id) {
    FILE *arquivo = fopen("Arquivos/Pacientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de pacientes.\n");
        return (Paciente){0}; // Retorna um paciente vazio em caso de erro
    }

    Paciente paciente = {0};
    char nome[100], cpf[12], contato[20];

    // Pular o cabeçalho
    fscanf(arquivo, "%*[^\n]\n");

    while (fscanf(arquivo, "%d,%99[^,],%11[^,],%19[^\n]\n", &id, nome, cpf, contato) == 4) {
        if (id == id) {
            strcpy(paciente.nome, nome);
            strcpy(paciente.cpf, cpf);
            strcpy(paciente.contato, contato);
            fclose(arquivo);
            return paciente; // Retorna o paciente encontrado
        }
    }

    fclose(arquivo);
    return (Paciente){0}; // Retorna um paciente vazio se não encontrado
}



//buscaMedicoCRM(){} tem que retornar o ID do medico
int buscaMedicoCRM(const char *crm) {
    FILE *arquivo = fopen("Arquivos/Medicos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de médicos.\n");
        return -1; // Erro ao abrir o arquivo
    }

    char nome[100], crmArquivo[7], especialidade[100], contato[20];
    int id = 0;

    // Pular o cabeçalho
    fscanf(arquivo, "%*[^\n]\n");

    while (fscanf(arquivo, "%d,%99[^,],%6[^,],%99[^,],%19[^\n]\n", &id, nome, crmArquivo, especialidade, contato) == 5) {
        if (strcmp(crmArquivo, crm) == 0) {
            fclose(arquivo);
            return id; // Retorna o ID do médico
        }
    }

    fclose(arquivo);
    return -1; // CRM não encontrado
}

//buscaMedicoId(){} tem que retornar um medico com base no ID
Medico buscaMedicoId(int id) {
    FILE *arquivo = fopen("Arquivos/Medicos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de médicos.\n");
        return (Medico){0}; // Retorna um médico vazio em caso de erro
    }

    Medico medico = {0};
    char nome[100], crm[7], especialidade[100], contato[20];

    // Pular o cabeçalho
    fscanf(arquivo, "%*[^\n]\n");

    while (fscanf(arquivo, "%d,%99[^,],%6[^,],%99[^,],%19[^\n]\n", &id, nome, crm, especialidade, contato) == 5) {
        if (id == id) {
            strcpy(medico.nome, nome);
            strcpy(medico.crm, crm);
            medico.especialidade = especialidadeParaTexto(especialidade);
            strcpy(medico.contato, contato);
            fclose(arquivo);
            return medico; // Retorna o médico encontrado
        }
    }

    fclose(arquivo);
    return (Medico){0}; // Retorna um médico vazio se não encontrado
}

//buscaConsultaEspecialidade(){} tem que retornar uma lista de consultas

//buscaConsultaCPF(){} tem que retornar uma lista de consultas

//buscaConsultaCRM(){} tem que retornar uma lista de consultas

//BuscaConsultaId(){} tem que retornar uma só consulta



