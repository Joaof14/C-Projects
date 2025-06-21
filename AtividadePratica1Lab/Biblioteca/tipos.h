#ifndef TIPOS_H
#define TIPOS_H

typedef struct {
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
} DataHora;

struct {
    char titulo[200];
    char Autor[200];
    char ISBN[13];
} Livros;

enum Status {CONCLUIDO, ANDAMENTO, CANCELADO}

struct Emprestimos{

};




#endif