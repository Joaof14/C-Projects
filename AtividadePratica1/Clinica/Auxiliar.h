#ifndef AUXILIAR_H
#define AUXILIAR_H

//Funções gerais

void verificarArquivo(const char *caminho, const char *colunas);

int entradaLimitada(char *destino, int tamanho_max);

int gerarNovoId(const char *arquivoPath);

//Funções de CPF

int validarCPF(const char *cpf);

int CPFJaCadastrado(const char *cpf);

int receberCPF(char *cpf, int deveExistir);



//Funções de CRM

int CRMJaCadastrado(const char *crm);

int validarCRM(const char *crm);

int receberCRM(char *cpf, int deveExistir);


//Funções de nome

int validarNome(const char *nome);

int receberNome(char *nome);



//Funções de Contato

int validarContato(const char *contato);
    
int receberContato(char *contato);

//Funções para enums
const char* especialidadeParaTexto(enum ESPECIALIDADE esp);

const char* statusConsultaParaTexto(enum statusConsulta status);

//Função para receber especialidade
int receberEspecialidade(enum ESPECIALIDADE *especialidade);


//Funções de exibição
void exibirMedico(Medico medico);

void exibirPaciente(Paciente paciente);

void exibirConsulta(Consulta consulta);

#endif