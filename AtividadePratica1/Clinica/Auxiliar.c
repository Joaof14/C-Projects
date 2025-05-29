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
    int i = 0;
    char c;
    
    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < tamanho_max - 1) {
            destino[i++] = c;
        }
    }
    destino[i] = '\0';
    return i; 
}



// Funções relacionadas a CPF

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
    if (arquivo == NULL) return 0;

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
        cpfValido=1;
        
    }while(!cpfValido);
    return 1;
}


//Funções de CRM

// Verifica se um CRM já existe no arquivo
int CRMJaCadastrado(const char *crm) {
    FILE *arquivo = fopen("Arquivos/Medicos.txt", "r");
    if (arquivo == NULL) return 0;

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

// valida se o CRM tem 6 dígitos numéricos

int validarCRM(const char *crm) {
    if (strlen(crm) != 6) return 0;
    for (int i = 0; i < 6; i++) {
        if (!isdigit(crm[i])) return 0;
    }
    
    return 1; // crm válido
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
        if (CPFJaCadastrado(crm)){
            printf("CRM já cadastrado no sistema!\n");
            continue;
        }
        crmValido=1;
        
    }while(!crmValido);
    return 1;
}



//Funções de nome


//Validar nome
int validarNOME(const char *nome){}

//Receber Nome
int receberNome(char *nome){

}



//Funções de Contato


//Validar contato
int validarContato(const char *contato){

}

//Verificar unicidade de contato
int contatoJaCadastrado(const char * contato){
    
}

//Receber Contato
int receberContato(char *contato) {

}


//Funções de busca





