#ifndef TIPOS_H
#define TIPOS_H


// TIPOS E ENUMS
typedef struct {
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
} DataHora;
enum GENERO {FICÇÃO, DIDÁTICO, BIOGRAFIA, COMEDIA, TERROR, ROMANCE};

struct {
    char titulo[200];
    char Autor[200];
    char ISBN[13];
    enum GENERO genero;
} Livros;

enum STATUS {CONCLUIDO, ANDAMENTO, CANCELADO};

typedef struct {
    unsigned int id;
    char leitor[200];
    char ISBN[13];
    DataHora DataDoEmprestimo;
    enum STATUS status;
} Emprestimos;


//LIVROS
void verificarISBN(char ISBN);
const char* generoParaTexto(int n);

//EMPRESTIMOS
//Função de conversão de enums
const char* statusParaTexto(int n);
//Data e hora
int receberDataHora(DataHora *dh);
int validarHora(int hora, int minuto);
int validarData(int dia, int mes, int ano);






#endif