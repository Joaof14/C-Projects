#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "StackCards.h"

void initPlayer(Player* player, const char* name) {
    strncpy(player->name, name, sizeof(player->name) - 1);
    initStack(&player->hand);
    player->points = 0;
}

void addCardToPlayer(Player* player, Card card) {
    push(&player->hand, card);
}

Card removeCardFromPlayer(Player* player, int cardIndex) {
    Stack temp;
    initStack(&temp);
    Card selected;
    
    //transferir cartas até o índice desejado
    for (int i = 0; i < cardIndex; i++) {
        push(&temp, pop(&player->hand));
    }
    
    //remover carta selecionada
    selected = pop(&player->hand);
    
    // Devolver cartas restantes
    while (!isEmptyStack(&temp)) {
        push(&player->hand, pop(&temp));
    }
    
    return selected;
}

void displayPlayerHand(Player* player) {
    printf("\nCartas de %s:\n", player->name);
    if (player->hand.size == 0) {
        printf("  Nenhuma carta na mão\n");
        return;
    }
    
    //criar uma pilha temporária para preservar a ordem
    Stack tempStack;
    initStack(&tempStack);
    int count = player->hand.size;
    
    //transferir cartas para a pilha temporária (invertendo a ordem)
    while (!isEmptyStack(&player->hand)) {
        Card c = pop(&player->hand);
        push(&tempStack, c);
    }
    
    // Mostrar cartas e recolocar na mão do jogador
    for (int i = 0; i < count; i++) {
        Card c = pop(&tempStack);
        printf("  %d: [%c%c]\n", i+1, c.value, c.suit);
        push(&player->hand, c);
    }
}