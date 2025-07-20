#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"
#include "StackCards.h"
#include "Player.h"
#include "Game.h"
#include "Actions.h"


int main() {
    srand(time(NULL));
    int choice;
    
    do {
        printf("\nJOGO DE CARTAS\n");
        printf("1. Iniciar novo jogo\n");
        printf("2. Sair\n");
        printf("Escolha: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            int numPlayers;
            printf("Número de jogadores (2-4): ");
            scanf("%d", &numPlayers);
            
            if (numPlayers >= 2 && numPlayers <= 4) {
                startGame(numPlayers);
            } else {
                printf("Número inválido de jogadores!\n");
            }
        }
    } while (choice != 2);
    
    return 0;
}

//Main.c