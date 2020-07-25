#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "stackBlock.h"

void stackStringTest() {
  printf("%s\n", "Testing string implementation...");
  enum StackType type = String;
  printf("%lu\n", sizeof(Stack));
  Stack *stackPointer;
  stackPointer = stackCreate(type);
  printf("Type: %d\n", stackPointer->type);
  printf("Top: %d\n", stackPointer->top);
  printf("Stack empty? %d\n", stackEmpty(stackPointer));
  Item *temp = malloc(sizeof(Item));
  temp->element = malloc((8) * sizeof(char));
  strcpy(temp->element, "Anthony");
  push(stackPointer, temp);
  printf("%s\n", (stackPointer->items)[0].element);
  printf("Stack empty? %d\n", stackEmpty(stackPointer));
  temp = pop(stackPointer);
  printf("Stack empty? %d\n", stackEmpty(stackPointer));
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
  stackPrint(stackPointer, stackPointer->type, NULL);
  temp = pop(stackPointer);
  printf("%s\n", temp->element);
  temp = pop(stackPointer);
  printf("%s\n", temp->element);
  temp = pop(stackPointer);
  printf("%s\n", temp->element);
  pop(stackPointer);
  printf("%d\n", stackPointer->maxSize);
  pop(stackPointer);

  temp = malloc(sizeof(Item));
  temp->element = malloc((5) * sizeof(char));
  strcpy(temp->element, "John");
  push(stackPointer, temp);
  temp = malloc(sizeof(Item));
  temp->element = malloc((5) * sizeof(char));
  strcpy(temp->element, "Fred");
  push(stackPointer, temp);
  temp = malloc(sizeof(Item));
  temp->element = malloc((5) * sizeof(char));
  strcpy(temp->element, "Mart");
  push(stackPointer, temp);
  temp = malloc(sizeof(Item));
  temp->element = malloc((5) * sizeof(char));
  strcpy(temp->element, "Jobe");
  push(stackPointer, temp);
  temp = malloc(sizeof(Item));
  temp->element = malloc((5) * sizeof(char));
  strcpy(temp->element, "Izzy");
  printf("%s\n", "Pushing Izzy");
  push(stackPointer, temp);
  temp = malloc(sizeof(Item));
  temp->element = malloc((5) * sizeof(char));
  strcpy(temp->element, "Char");
  printf("%s\n", "Pushing Char");
  push(stackPointer, temp);
  printf("%d\n", stackPointer->maxSize);
  printf("%s\n", stackPointer->items[0].element);
  printf("%s\n", stackPointer->items[1].element);
  printf("%s\n", stackPointer->items[2].element);
  printf("%s\n", stackPointer->items[3].element);
  printf("%s\n", stackPointer->items[4].element);
  stackPrint(stackPointer, stackPointer->type, NULL);
  pop(stackPointer);
  pop(stackPointer);
  pop(stackPointer);
  pop(stackPointer);
  stackPrint(stackPointer, stackPointer->type, NULL);
}

void stackIntTest() {
  printf("%s\n", "Testing integer implementation...");
  Stack *stackPointer;
  stackPointer = stackCreate(Int);
  printf("Type: %d\n", stackPointer->type);
  printf("Top: %d\n", stackPointer->top);
  printf("Stack empty? %d\n", stackEmpty(stackPointer));
  Item *temp = malloc(sizeof(Item));
  temp->element = malloc(sizeof(int));
  int tempInt0 = 7;
  temp->element = &tempInt0;
  push(stackPointer, temp);
  printf("%d\n", *(int*)((stackPointer->items)[0].element));
  printf("Stack empty? %d\n", stackEmpty(stackPointer));
  temp = pop(stackPointer);
  printf("Stack empty? %d\n", stackEmpty(stackPointer));
  temp = malloc(sizeof(Item));
  temp->element = malloc(sizeof(int));
  int tempInt1 = 100;
  temp->element = &tempInt1;
  printf("%s\n", "Pushing 100");
  push(stackPointer, temp);
  temp = malloc(sizeof(Item));
  temp->element = malloc(sizeof(int));
  int tempInt2 = 200;
  temp->element = &tempInt2;
  printf("%s\n", "Pushing 200");
  push(stackPointer, temp);
  temp = malloc(sizeof(Item));
  temp->element = malloc(sizeof(int));
  int tempInt3 = 300;
  temp->element = &tempInt3;
  printf("%s\n", "Pushing 300");
  push(stackPointer, temp);
  printf("%d\n", *(int*)((stackPointer->items)[0].element));
  printf("%d\n", *(int*)((stackPointer->items)[1].element));
  printf("%d\n", *(int*)((stackPointer->items)[2].element));
  stackPrint(stackPointer, stackPointer->type, NULL);
}

int main() {
  stackStringTest();
  stackIntTest();
  return 0;
}
