#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Stack{
    Node *top;
} Stack;

void initStack(Stack * stack){
    stack->top = NULL;
}

int isEmpty(Stack * stack){
    return stack->top == NULL;
}

void push(Stack * stack, int value){
    Node * newNode = (Node*)malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack * stack) {
    if (isEmpty(stack)){
        printf("Erro de fila vazia\n");
        return -1;
    }

    Node * temp = stack->top;
    int poppedValue = temp->data;
    stack->top =temp->next;
    free(temp);
    return poppedValue;

}

int peek(Stack* stack){
    if (isEmpty(stack)){
        printf("Erro de fila vazia\n");
        return -1;
    }
    return stack->top->data;

}

void display(Stack * stack){
    if (isEmpty(stack)){
        printf("Erro de fila vazia\n");
        return;
    }
    Node * temp = stack->top;
    printf("Pilha: ");
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main(){
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(&stack);
    pop(&stack);
    push(&stack, 40);
    display(&stack);

    printf("Elemento no topo: %d\n", peek(&stack));
    printf("Desimpilhando: %d\n", pop(&stack));
    display(&stack);
    return 0;
}


