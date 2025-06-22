#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "auxiliar.h"

//--------------------------------------------
//LIVROS

//Função de conversão de enums
const char* generoParaTexto(int n){}

//Funções para ISBN
int validarISBN(const char *isbn){
        if (strlen(isbn) != 11) 
    {return 0;}
    for (int i = 0; i < 11; i++) {
        if (!isdigit(isbn[i])) return 0;
    }

    return 1; // isbn válido
}

int receberISBN(char * ISBN){
    int isbnValido = 0;

    do {
        printf("\nDigite o ISBN do livro\n");
        ler_entrada_limitada(ISBN, 14);
        if(validarISBN(ISBN)){
            isbnValido = 1;
        }
        printf("\nErro: ISBN deve conter exatamente 13 números\n");
    } while(!isbnValido);
}


//Funções para titulo
int validarTitulo(const char *nome) {
    // Verificar tamanho e se contém apenas letras e espaços
    if (strlen(nome) == 0 || strlen(nome) > 199) {
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

    return 1;
}

int receberTitulo(char *nome){
    do {
        printf("Nome (máx 199 caracteres): ");
        entradaLimitada(nome, 200);

        if (!validarTitulo(nome)) {
            printf("Erro: Use apenas letras e espaços no nome e não deixe em branco!\n");
            continue;
        }
        break;
    }
    while (1);

    return 1;
}

//--------------------------------------------
//EMPRESTIMOS
//Função de conversão de enums
const char* statusParaTexto(int n){}

void gerarIdEmprestimo(){}

//--------------------------------------------
//DATA E HORA

int validarHora(int hora, int minuto) {
    if (hora < 0 || hora > 23) return 0;
    if (minuto < 0 || minuto > 59) return 0;
    return 1;
}

int validarData(int dia, int mes, int ano) {
    if (ano < 1900 || ano > 2100) return 0;
    if (mes < 1 || mes > 12) return 0;
    if (dia < 1) return 0;

    int diasNoMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    // Ano bissexto
    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
        diasNoMes[1] = 29;

    if (dia > diasNoMes[mes - 1]) return 0;

    return 1;
}

int receberData(Data *dh) {
    char buffer[100];
    do {
        printf("Data do empréstimo (DD/MM/AAAA): ");
        
        // Lê toda a linha incluindo o '\n'
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erro na leitura.\n");
            return 0; // Trata erro de leitura
        }
        
        // Remove o '\n' do final se existir
        char *pos = strchr(buffer, '\n');
        if (pos) *pos = '\0';
        
        int resultado = sscanf(buffer, "%d/%d/%d", 
                               &dh->dia, &dh->mes, &dh->ano);
        
        if (resultado != 3) {
            printf("Erro: Formato inválido! Use DD/MM/AAAA.\n");
            continue;
        }
        
        if (!validarData(dh->dia, dh->mes, dh->ano)) {
            printf("Erro: Data inválida!\n");
            continue;
        }
        
        break;
    } while (1);
    return 1;
}


//-------------------------------------------
//Funções para componentes de ambas as structs: autor, e leitor
int validarNome(const char *nome) {
    // Verificar tamanho e se contém apenas letras e espaços
    if (strlen(nome) == 0 || strlen(nome) > 199) {
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
        printf("Nome (máx 199 caracteres): ");
        entradaLimitada(nome, 200);

        if (!validarNome(nome)) {
            printf("Erro: Use apenas letras e espaços no nome e não deixe em branco!\n");
            continue;
        }
        break;
    }
    while (1);

    return 1;
}