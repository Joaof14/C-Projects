#define PLAYER_H
#ifndef PLAYER_H

void initPlayer(Player* player, const char* name) ;

void addCardToPlayer(Player* player, Card card) ;

Card removeCardFromPlayer(Player* player, int cardIndex) ;

void displayPlayerHand(Player* player);

#endif 