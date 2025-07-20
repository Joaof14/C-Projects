#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "StackCards.h"

void startGame(int numPlayers) {
    //inicializar estruturas
    Stack deck, discardPile;
    Queue turnQueue;
    
    initStack(&deck);
    initStack(&discardPile);
    initQueue(&turnQueue);
    
    //criar e embaralhar baralho
    createDeck(&deck);
    shuffleDeck(&deck);
    
    //criar jogadores
    for (int i = 0; i < numPlayers; i++) {
        Player p;
        char name[50];
        sprintf(name, "Jogador %d", i+1);
        initPlayer(&p, name);
        enqueue(&turnQueue, p);
    }
    
    //distribuir cartas iniciais
    PlayerNode* current = turnQueue.front;
    for (int i = 0; i < 5; i++) {
        while (current) {
            if (!isEmptyStack(&deck)) {
                addCardToPlayer(&current->player, pop(&deck));
            }
            current = current->next;
        }
        current = turnQueue.front;
    }
    
    //iniciar primeira carta no descarte
    if (!isEmptyStack(&deck)) {
        push(&discardPile, pop(&deck));
    }
    
    // Loop principal do jogo
    int gameOver = 0;
    while (!gameOver && !isEmptyQueue(&turnQueue)) {
        Player currentPlayer = front(&turnQueue);
        printf("\n--- VEZ DE %s ---\n", currentPlayer.name);
        
        //mostrar estado do jogo
        printf("Topo do descarte: [%c%c]\n", peekStack(&discardPile).value, peekStack(&discardPile).suit);
        displayPlayerHand(&currentPlayer);
        
        // TODO: Implementar ações do jogador
        
        //verificar se alguém venceu
        if (currentPlayer.hand.size == 0) {
            printf("\nPARABÉNS! %s VENCEU O JOGO!\n", currentPlayer.name);
            gameOver = 1;
        }
        
        //passar para o próximo jogador
        rotateQueue(&turnQueue);
        
        //reciclar descarte se baralho acabar
        if (isEmptyStack(&deck) && !isEmptyStack(&discardPile)) {
            Card top = pop(&discardPile);
            while (!isEmptyStack(&discardPile)) {
                push(&deck, pop(&discardPile));
            }
            push(&discardPile, top);
            shuffleDeck(&deck);
            printf("\nBaralho reciclado!\n");
        }
    }
}