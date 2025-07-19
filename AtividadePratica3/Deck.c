#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "StackCards.h"

//Criar baralho no inicio do jogo
void createDeck(Stack* deck) {
    char suits[] = {'H', 'D', 'C', 'S'}; // Hearts, Diamonds, Clubs, Spades
    char values[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            Card card = {suits[i], values[j]};
            push(deck, card);
        }
    }
}

void shuffleDeck(Stack* deck) {
    // Converter pilha para array
    int n = deck->size;
    Card* array = (Card*)malloc(n * sizeof(Card));
    
    // Extrair cartas da pilha
    for (int i = 0; i < n; i++) {
        array[i] = pop(deck);
    }
    
    // Embaralhar
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    
    // Reconstruir pilha
    for (int i = 0; i < n; i++) {
        push(deck, array[i]);
    }
    
    free(array);
}