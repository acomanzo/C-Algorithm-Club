#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int stackEmpty(Stack *stack) {
  if (stack->top == NULL) {
    return 1;
  }
  return 0;
}

void push(Stack *stack, Item *item) {
  Item *temp = stack->top;
  stack->top = item;
  item->next = temp;
}

Item *pop(Stack *stack) {
  // Item *item = malloc(sizeof(Item));
  // item->element = stack->top->element;
  Item *formerTop = stack->top;
  Item *newTop = stack->top->next;
  stack->top = newTop;
  formerTop->next = NULL;
  return formerTop;
}

Stack *stackCreate() {
  Stack *stack;
  if ((stack = malloc(sizeof(Stack))) == NULL) {
    printf("%s\n", "Cannot allocate space for new stack.");
    exit(EXIT_FAILURE);
  }
  stack->top = NULL;
  return stack;
}

void stackPrint(Stack *stack, void (*printFunc)(Stack *)) {
  if (*printFunc) {
    (*printFunc)(stack);
  } else {
    printf("%s\n", "Invalid function pointer.");
  }
}
