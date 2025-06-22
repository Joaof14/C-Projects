#ifndef TIPOS_H
#define TIPOS_H


// TIPOS E ENUMS
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;
enum GENERO {FICÇÃO, DIDÁTICO, BIOGRAFIA, COMEDIA, TERROR, ROMANCE};

typedef struct {
    char titulo[200];
    char autor[200];
    char ISBN[13];
    enum GENERO genero;
} Livros;

enum STATUS {CONCLUIDO, ANDAMENTO, CANCELADO};

typedef struct {
    unsigned int id;
    char leitor[200];
    char ISBN[13];
    Data DataDoEmprestimo;
    enum STATUS status;
} Emprestimos;

//-------------------------------------------
//LIVROS
//Função de conversão de enums
const char* generoParaTexto(int n);

int validarISBN(const char *isbn);
int receberISBN(char * ISBN);

int validarTitulo(const char *nome);
int receberTitulo(char *nome);




//-------------------------------------------
//EMPRESTIMOS
//Função de conversão de enums
const char* statusParaTexto(int n);
void gerarIdEmprestimo();

//--------------------------------------------
//DATA E HORA
int receberData(Data *dh);
int validarData(int dia, int mes, int ano);


//-------------------------------------------
//Funções para  conponentes de ambas as structs: titulo, autor, e leitor
int validarNome(const char *nome);
int receberNome(char *nome);


#endif