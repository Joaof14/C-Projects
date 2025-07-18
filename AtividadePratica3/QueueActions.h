#ifndef QUEUEACTIONS
#define QUEUEACTIONS

void initQueue (Queue * queue);

int isEmptyQueue(Queue * queue);

void enqueue(Queue * queue, Player player);

Player dequeue(Queue* queue);

Player front(Queue * queue);

void display(Queue * queue);

void rotateQueue(Queue* queue);


#endif