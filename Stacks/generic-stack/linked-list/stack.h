typedef struct Item {
  struct Item *next;
  void *element;
} Item;

typedef struct Stack {
  Item *top;
} Stack;

int stackEmpty(Stack *stack);

void push(Stack *stack, Item *item);

Item *pop(Stack *stack);

Stack *stackCreate();

void stackPrint(Stack *stack, void (*printFunc)(Stack *));
