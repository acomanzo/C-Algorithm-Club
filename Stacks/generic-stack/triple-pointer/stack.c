#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackItem {
  void *element;
} Item;

typedef struct Stack {
  char *type; // The type of elements in this stack
  int top; // Index representing the top of the stack
  Item ***items; // pointer to array of pointers that point to Items
} Stack;

int stackEmpty(Stack *stackPointer) {
  if (stackPointer->top < 0) {
    return 1;
  }
  return 0;
}

void push(Stack *stack, Item *item) {
  int newSize = stack->top + 2;
  printf("%p\n", &(stack->items));
  printf("%p\n", &(*(stack->items)));
  printf("%p\n", &(*(*(stack->items)))); // for some reason, this address
  // changes when push is called
  //printf("%p\n", &(*(*(*(stack->items)))));
  Item **newBuffer = realloc(*(stack->items), newSize * sizeof(Item*));
  if (newBuffer != NULL) {
    (stack->items) = &newBuffer;
    stack->top = stack->top + 1;
    (*(stack->items))[stack->top] = item;
    printf("%p\n", &(*(stack->items)));
  }
  else {
    printf("%s\n", "Push failed. Couldn't resize.");
  }
}

struct StackItem* pop(Stack *stack) {
  if (stack->top == -1) {
    printf("%s\n", "Stack underflow.");
    return NULL;
  }
  Item *item = ((*(stack->items))[stack->top]);
  int newSize = stack->top;
  if (newSize == 0) {
    newSize = 1;
  }
  Item **newBuffer = realloc(*(stack->items), newSize * sizeof(Item*));
  if (newBuffer != NULL) {
    *(stack->items) = newBuffer;
    if (newSize == 1) {
      stack->top = -1;
    }
    else {
      stack->top = newSize - 1;
    }
    return item;
  }
  else {
    printf("%s\n", "Pop failed. Couldn't resize.");
    return NULL;
  }
}

Stack* stackCreate(char *type) {
  Stack *stackPointer = malloc(sizeof(Stack));
  // Item **outerbuffer = malloc(sizeof(Item*));
  // if (outerbuffer == NULL) {
  //   printf("%s\n", "Cannot allocate space for items.");
  //   exit(EXIT_FAILURE);
  // }
  // Item *innerbuffer = malloc(sizeof(Item));
  // if (innerbuffer == NULL) {
  //   printf("%s\n", "Cannot allocate space for items.");
  //   exit(EXIT_FAILURE);
  // }
  // outerbuffer = &innerbuffer;
  // (stackPointer->items) = &outerbuffer;

  if ((*(stackPointer->items) = malloc(sizeof(Item*))) == NULL) {
      printf("%s\n", "Cannot allocate space for items.");
      exit(EXIT_FAILURE);
  }
  // memset(stackPointer->items, 0, sizeof *(stackPointer->items));

  if (strcmp(type, "string") == 0) {
    if ((stackPointer->type = (char *)malloc(sizeof("string"))) == NULL) {
      printf("%s\n", "Cannot allocate space for type.");
      exit(EXIT_FAILURE);
    }
    memset(stackPointer->type, '\0', sizeof(stackPointer->type));
    strcpy(stackPointer->type, "string");
  }
  else if (strcmp(type, "int") == 0) {
    if ((stackPointer->type = (char *)malloc(sizeof(char) * 4)) == NULL) {
      printf("%s\n", "Cannot allocate space for type.");
      exit(EXIT_FAILURE);
    }
    memset(stackPointer->type, '\0', sizeof(stackPointer->type));
    strcpy(stackPointer->type, "int");
  }
  else if (strcmp(type, "char") == 0) {
    if ((stackPointer->type = (char *)malloc(sizeof(char) * 5)) == NULL) {
      printf("%s\n", "Cannot allocate space for type.");
      exit(EXIT_FAILURE);
    }
    memset(stackPointer->type, '\0', sizeof(stackPointer->type));
    strcpy(stackPointer->type, "char");
  }
  else if (strcmp(type, "float") == 0) {
    if ((stackPointer->type = (char *)malloc(sizeof(char) * 6)) == NULL) {
      printf("%s\n", "Cannot allocate space for type.");
      exit(EXIT_FAILURE);
    }
    memset(stackPointer->type, '\0', sizeof stackPointer->type);
    strcpy(stackPointer->type, "float");
  }

  stackPointer->top = -1;
  return stackPointer;
}

void stackStringTest() {
  printf("%lu\n", sizeof(Stack));
  Stack *stackPointer;
  stackPointer = stackCreate("string");
  printf("Type: %s\n", stackPointer->type);
  printf("Top: %d\n", stackPointer->top);
  printf("Stack empty? %d\n", stackEmpty(stackPointer));
  Item *temp = malloc(sizeof(Item));
  temp->element = malloc((8) * sizeof(char));
  strcpy(temp->element, "Anthony");
  // printf("%p\n", &(*(*(*(stackPointer->items))))); /* error here: expected, right? */
  push(stackPointer, temp);
  printf("%s\n", (*(stackPointer->items))[0]->element);
  printf("Stack empty? %d\n", stackEmpty(stackPointer));
  // temp = pop(stackPointer);
  // printf("Stack empty? %d\n", stackEmpty(stackPointer));
  temp = malloc(sizeof(Item));
  temp->element = malloc((5) * sizeof(char));
  strcpy(temp->element, "Kara");
  printf("%s\n", "Pushing kara");
  push(stackPointer, temp);
  temp = malloc(sizeof(Item));
  temp->element = malloc((5) * sizeof(char));
  strcpy(temp->element, "John");
  printf("%s\n", "Pushing John");
  push(stackPointer, temp);
  temp = malloc(sizeof(Item));
  temp->element = malloc((7) * sizeof(char));
  strcpy(temp->element, "Krista");
  printf("%s\n", "Pushing Krista");
  push(stackPointer, temp);
  temp = pop(stackPointer);
  printf("%s\n", temp->element);
  temp = pop(stackPointer);
  printf("%s\n", temp->element);
}

int main() {
  stackStringTest();
  return 0;
}
