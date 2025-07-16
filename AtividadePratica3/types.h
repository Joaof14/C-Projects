#ifndef STACKCARDS_H
#define STACKCARDS_H

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Stack{
    Node *top;
} Stack;

typedef struct Queue{
    Node * front;
    Node * rear;
} Queue;



#endif