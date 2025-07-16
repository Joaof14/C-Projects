#ifndef TYPES_H
#define TYPES_H

typedef struct Cards{
    char suit;
    char value;
} Cards;

typedef struct Node{
    Cards card;
    struct Node* next;
} Node;

typedef struct Stack{
    Node * top;
    int size;
    
} Stack;

typedef struct Queue{
    Node * front; //inicio da fila
    Node * rear; //fim da fila
    int size;
    
} Queue;

typedef struct {
    char name[50];
    Stack hand;   //cartas na mão do jogador (pode ser uma pilha ou lista)
    int points;
} Player;


#endif