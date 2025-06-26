#ifndef AUXILIAR_H
#define AUXILIAR_H

//void criarArquivos(const char *caminho, const char *colunas);
int ler_entrada_limitada(char *buffer, size_t tamanho_max);

int gerarNovoId(const char *arquivoPath);

void carregarLivros(Livro ** livros, int * total);

int buscarLivroPorISBN(Livro * livros, int total, const char * isbnBusca);
#endif