#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

//Função para verificar se recebeu 13 digitos 
void verificaISBN(char ISBN){}

const char* StatusParaTexto(int n){}


int validarHora(int hora, int minuto) {
    if (hora < 0 || hora > 23) return 0;
    if (minuto < 0 || minuto > 59) return 0;
    return 1;
}



// Verifica se a data é válida
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


int receberDataHora(DataHora *dh) {
    char buffer[100];
    do {
        printf("Data e hora da consulta (DD/MM/AAAA HH:MM): ");
        
        // Lê toda a linha incluindo o '\n'
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erro na leitura.\n");
            return 0; // Trata erro de leitura
        }
        
        // Remove o '\n' do final se existir
        char *pos = strchr(buffer, '\n');
        if (pos) *pos = '\0';
        
        int resultado = sscanf(buffer, "%d/%d/%d %d:%d", 
                               &dh->dia, &dh->mes, &dh->ano, 
                               &dh->hora, &dh->minuto);
        
        if (resultado != 5) {
            printf("Erro: Formato inválido! Use DD/MM/AAAA HH:MM.\n");
            continue;
        }
        
        if (!validarData(dh->dia, dh->mes, dh->ano)) {
            printf("Erro: Data inválida!\n");
            continue;
        }
        
        if (!validarHora(dh->hora, dh->minuto)) {
            printf("Erro: Hora inválida!\n");
            continue;
        }
        
        break;
    } while (1);
    return 1;
}