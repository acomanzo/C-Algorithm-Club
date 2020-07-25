#include <stdio.h>
#include <stdlib.h>
#include "stackBlock.h"

int stackEmpty(Stack *stackPointer) {
  if (stackPointer->top < 0) {
    return 1;
  }
  return 0;
}

void stackResize(Stack *stack, int newSize) {
  Item *newBuffer = realloc(stack->items, newSize);
  if (newBuffer != NULL) {
    stack->items = newBuffer;
  }
  else {
    printf("%s\n", "Couldn't resize.");
  }
}

void push(Stack *stack, Item *item) {
  int newSize = stack->top + 2;
  if (newSize == stack->maxSize) {
    stackResize(stack, stack->maxSize + 5);
    stack->maxSize = stack->maxSize + 5;
  }
  stack->top = stack->top + 1;
  (stack->items)[stack->top] = *item;
}

Item* pop(Stack *stack) {
  if (stack->top == -1) {
    printf("%s\n", "Stack underflow.");
    return NULL;
  }
  Item *item = malloc(sizeof(Item));
  item->element = ((stack->items)[stack->top]).element;
  stack->top = stack->top - 1;
  return item;
}

Stack* stackCreate(enum StackType type) {
  Stack *stackPointer = malloc(sizeof(Stack));
  stackPointer->maxSize = 5;
  stackPointer->top = -1;
  // make a pointer to a dynamic block of Items on the heap
  if ((stackPointer->items = malloc(5 * sizeof(Item))) == NULL) {
      printf("%s\n", "Cannot allocate space for items.");
      exit(EXIT_FAILURE);
  }
  // memset(stackPointer->items, 0, sizeof *(stackPointer->items));
  stackPointer->type = type;
  return stackPointer;
}

void stackPrint(Stack *stack, enum StackType type, void (*printFunc)(Stack *)) {
  switch(type) {
    case String:
      for (int i = 0; i < (stack->top + 1); i++) {
        printf("%s, ", (stack->items)[i].element);
      }
      printf("\n");
      break;
    case Int:
      for (int i = 0; i < (stack->top + 1); i++) {
        printf("%d, ", *(int*)((stack->items)[i].element));
      }
      printf("\n");
      break;
    case Float:
      for (int i = 0; i < (stack->top + 1); i++) {
        printf("%f, ", *(float*)((stack->items)[i].element));
      }
      printf("\n");
      break;
    case Char:
      for (int i = 0; i < (stack->top + 1); i++) {
        printf("%c, ", *(char*)((stack->items)[i].element));
      }
      printf("\n");
      break;
    case Struct:
      if (*printFunc != NULL && printFunc != NULL) {
        (*printFunc)(stack);
      }
      else {
        printf("%s\n", "Invalid function pointer.");
      }
      break;
    default:
      printf("%s\n", "Type not implemented yet.");
  }
}
