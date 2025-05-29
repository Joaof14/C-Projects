#ifndef AUXILIAR_H
#define AUXILIAR_H

//Funções gerais

void verificarArquivo(const char *caminho, const char *colunas);

int entradaLimitada(char *destino, int tamanho_max);



//Funções de CPF

int validarCPF(const char *cpf);

int CPFJaCadastrado(const char *cpf);

int receberCPF(char *cpf);



//Funções de CRM

int CRMJaCadastrado(const char *crm);

int validarCRM(const char *crm);

int receberCRM(char *cpf);


//Funções de nome

int validarNOME(const char *nome){}

int receberNome(char *nome);



//Funções de Contato

int validarContato(const char *contato);

int contatoJaCadastrado(const char * contato);
    
int receberContato(char *contato);


#endif