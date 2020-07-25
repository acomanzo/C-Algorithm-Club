#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void stackPrintString(Stack *stack) {
  Item *temp = stack->top;
  while(temp) {
    printf("%s, ", temp->element);
    temp = temp->next;
  }
  printf("\n");
}

void stackTest() {
  printf("%s\n", "Testing linked list stack...");
  Stack *stack = stackCreate();
  Item *temp = malloc(sizeof(Item));
  temp->element = "5";
  printf("Stack empty? %d\n", stackEmpty(stack));
  push(stack, temp);
  stackPrint(stack, stackPrintString);
  printf("Stack empty? %d\n", stackEmpty(stack));
  temp = malloc(sizeof(Item));
  temp->element = "+";
  push(stack, temp);
  temp = malloc(sizeof(Item));
  temp->element = "2";
  push(stack, temp);
  stackPrint(stack, stackPrintString);
  temp = pop(stack);
  printf("Popped: %s\n", temp->element);
  stackPrint(stack, stackPrintString);
}

int main() {
  stackTest();
  return 1;
}
