#include <stdio.h>



void insertionSort(int *vetor, int tamanho){
    int pivo, j;
    for (int i = 1; i<tamanho; i++)
    {
        pivo = vetor[i];
        j = i - 1;

        while(j>= 0 && vetor[j] > pivo){
            vetor[j+1] = vetor[j];
        }
        vetor[j+1] = pivo;
    }
}


void bubbleSort(int *vetor, int tamanho){
    int aux;
    for (int i = 0; i<tamanho;i++){
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

void gnomeSort(int *vetor, int tamanho){
    int pos = 0, aux;
    while(pos < tamanho){
        if (pos == 0 || vetor[pos] >= vetor[pos-1]){
            pos++;
        }
        else{
            aux = vetor[pos];
            vetor[pos] = vetor[pos - 1];
            vetor[pos-1] = aux;
            pos--;
        }
    }

    //Printar
}

void mergeSort(int *vetor, int tamanho){

}



void shellSort(int *vetor, int tamanho){

}


void quickSort(int *vetor, int tamanho){}