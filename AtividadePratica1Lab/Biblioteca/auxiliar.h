#ifndef AUXILIAR_H
#define AUXILIAR_H

//void criarArquivos(const char *caminho, const char *colunas);
int ler_entrada_limitada(char *buffer, size_t tamanho_max);

int gerarNovoId(const char *arquivoPath);

void carregarLivros(Livros ** livros, int * total);


#endif