#ifndef STACKCARDS_H
#define STACKCARDS_H

void initStack(Stack * stack);

int isEmptyStack(Stack * stack);

void push(Stack * stack, Card card);

Card pop(Stack * stack); 

Card peek(Stack* stack);

void displayStack(Stack * stack);

#endif