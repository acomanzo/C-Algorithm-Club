#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

int queueEmpty(Queue *queue) {
  if (queue->length == 0) {
    return 1;
  }
  return 0;
}

void enqueue(Queue *queue, Item *item) {
  if (queueEmpty(queue)) {
    queue->head = item;
    queue->tail = queue->head;
  }
  else {
    queue->tail->next = item;
    queue->tail = item;
  }
  queue->length = queue->length + 1;
}

Item *dequeue(Queue *queue) {
  if (queueEmpty(queue)) {
    return NULL;
  }
  else {
    Item *temp = queue->head;
    queue->head = queue->head->next;
    temp->next = NULL;
    queue->length = queue->length - 1;
    return temp;
  }
}

Queue *queueCreate() {
  Queue *queue;
  if ((queue = malloc(sizeof(Queue))) == NULL) {
    printf("%s\n", "Cannot allocate space for new queue.");
    exit(EXIT_FAILURE);
  }
  queue->head = NULL;
  queue->tail = queue->head;
  queue->length = 0;
  return queue;
}

void queuePrint(Queue *queue, void (*printFunc)(Queue *)) {
  if (*printFunc) {
    (*printFunc)(queue);
  }
  else {
    printf("%s\n", "Invalid function pointer.");
  }
}
