#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void queuePrintString(Queue *queue) {
  Item *temp = queue->head;
  printf("%c", '[');
  if (temp) {
    while(temp) {
      printf("%s, ", temp->element);
      temp = temp->next;
    }
    printf("%c\n", ']');
  }
  else {
    printf("%c\n", ']');
  }
}

void queueTest() {
  printf("%s\n", "Testing queue linked list...");
  Queue *queue = queueCreate();
  Item *item = malloc(sizeof(Item));
  item->element = "I";
  item->next = NULL;
  printf("Queue empty? %d\n", queueEmpty(queue));
  enqueue(queue, item);
  queuePrint(queue, queuePrintString);
  printf("Queue empty? %d\n", queueEmpty(queue));
  item = malloc(sizeof(Item));
  item->element = "love";
  item->next = NULL;
  enqueue(queue, item);
  item = malloc(sizeof(Item));
  item->element = "C";
  item->next = NULL;
  enqueue(queue, item);
  queuePrint(queue, queuePrintString);
  printf("Queue length: %d\n", queue->length);
  if ((item = dequeue(queue)) == NULL) {
    printf("%s\n", "Queue empty.");
  }
  else {
    printf("Removed \"%s\" from the queue.\n", item->element);
  }
  queuePrint(queue, queuePrintString);
  if ((item = dequeue(queue)) == NULL) {
    printf("%s\n", "Queue empty.");
  }
  else {
    printf("Removed \"%s\" from the queue.\n", item->element);
  }
  queuePrint(queue, queuePrintString);
  if ((item = dequeue(queue)) == NULL) {
    printf("%s\n", "Queue empty.");
  }
  else {
    printf("Removed \"%s\" from the queue.\n", item->element);
  }
  queuePrint(queue, queuePrintString);
  if ((item = dequeue(queue)) == NULL) {
    printf("%s\n", "Queue empty.");
  }
  else {
    printf("Removed \"%s\" from the queue.\n", item->element);
  }
  queuePrint(queue, queuePrintString);
  printf("Queue length: %d\n", queue->length);
}

int main() {
  queueTest();
  return 1;
}
