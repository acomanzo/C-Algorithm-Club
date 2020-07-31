typedef struct Item {
  struct Item *next;
  void *element;
} Item;

typedef struct Queue {
  Item *head;
  Item *tail;
  int length;
} Queue;

int queueEmpty(Queue *queue);

void enqueue(Queue *queue, Item *item);

Item *dequeue(Queue *queue);

Queue *queueCreate();

void queuePrint(Queue *queue, void (*printFunc)(Queue *));
