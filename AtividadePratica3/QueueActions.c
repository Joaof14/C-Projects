#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "QueueActions.h"

void initQueue (Queue * queue){
    queue->front = queue->rear = NULL;
    queue->size = NULL;
}

int isEmpty(Queue * queue){
    return queue->front == NULL;
}

void enqueue(Queue * queue, Player player){
    PlayerNode * newNode = (PlayerNode*)malloc(sizeof(PlayerNode));
    if (!newNode) {
        printf("Erro de alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    newNode->player = player;
    newNode->next = NULL;

    if(queue->rear == NULL){
        queue->front = queue->rear = newNode;
    }
    else{
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

Player dequeue(Queue* queue){
    if (isEmpty(queue)){
        printf("Erro: Fila Vazia\n");
        Player invalid;
        strcpy(invalid.name, "INVALID");
        invalid.points = -1;
        initStack(&invalid.hand);
        return invalid;
    }

    PlayerNode * temp = queue-> front;
    Player dequeuedPlayer = temp->player;
    queue->front = temp->next;
    if(queue->front == NULL){
        queue->rear == NULL;
    }
    free(temp);
    queue->size--;
    return dequeuedPlayer;
}

Player front(Queue * queue){
    if (isEmpty(queue)){
        printf("Erro: Fila Vazia\n");
        Player invalid;
        strcpy(invalid.name, "INVALID");
        invalid.points = -1;
        initStack(&invalid.hand);
        return invalid;
    }
    return queue->front->player;

}

void display(Queue * queue){
    if (isEmpty(queue)){
        printf("Fila Vazia.\n");
        return;
    }
    PlayerNode * temp = queue->front;
    printf("Fila de Jogadores (%d): \n", queue->size);

    while(temp){
        printf("- %s (Pontos: %d, Cartas: %d)\n", temp->player.name, temp->player.points, temp->player.hand.size);
        temp = temp->next;
    }
    printf("\n");
}

void rotateQueue(Queue* queue){
    if (isEmpty(queue) || queue->front == queue->rear) {
        return;
    }
    PlayerNode* temp = queue->front;
    queue->front = (PlayerNode*)temp->next;
    queue->rear->next = (struct PlayerNode*)temp;
    queue->rear = temp;
    temp->next = NULL;
}

int main(){
    Queue turnQueue;
    initQueue(&turnQueue);
    
    // Criar jogadores de teste
    Player p1, p2, p3;
    
    strcpy(p1.name, "Alice");
    initStack(&p1.hand);
    p1.points = 10;
    
    strcpy(p2.name, "Bob");
    initStack(&p2.hand);
    p2.points = 15;
    
    strcpy(p3.name, "Carol");
    initStack(&p3.hand);
    p3.points = 8;
    
    // Adicionar jogadores à fila
    enqueue(&turnQueue, p1);
    enqueue(&turnQueue, p2);
    enqueue(&turnQueue, p3);
    
    // Mostrar fila
    display(&turnQueue);
    
    // Simular rodada de turnos
    printf("\n--- Simulando turnos ---\n");
    for (int i = 0; i < 3; i++) {
        Player current = front(&turnQueue);
        printf("Vez de: %s\n", current.name);
        
        // Rotacionar fila
        rotateQueue(&turnQueue);
        printf("Após rotação: ");
        display(&turnQueue);
    }
    
    // Remover jogador
    Player removed = dequeue(&turnQueue);
    printf("\nJogador removido: %s\n", removed.name);
    printf("Fila após remoção: ");
    display(&turnQueue);
    
    return 0;
}
