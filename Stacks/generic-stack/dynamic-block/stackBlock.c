#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Represents what type of elements a stack contains where a Struct is any
 * user-defined struct.
 */
enum StackType {String, Int, Char, Float, Struct};

/**
 * Represents an item within a stack.
 */
typedef struct StackItem {
  void *element;
} Item;

/**
 * Represents a generic stack.
 */
typedef struct Stack {
  enum StackType type; // The type of elements in this stack
  int top; // Index representing the element at the top of the stack
  int maxSize; // Threshold before resizing
  Item *items; // pointer to block of Items
} Stack;

/**
 * Determines if a stack is empty.
 * @param stackPointer a pointer to a Stack
 * @returns 1 if the variable top within stackPointer is -1, 0 otherwise.
 */
int stackEmpty(Stack *stackPointer) {
  if (stackPointer->top < 0) {
    return 1;
  }
  return 0;
}

/**
 * Resizes a stack with realloc.
 * @param stack a pointer to a Stack.
 * @param newSize an integer in bytes representing the size of the
 * pointer to the new stack.
 */
void stackResize(Stack *stack, int newSize) {
  Item *newBuffer = realloc(stack->items, newSize);
  if (newBuffer != NULL) {
    stack->items = newBuffer;
  }
  else {
    printf("%s\n", "Couldn't resize.");
  }
}

/**
 * Pushes an item to a stack.
 * @param stack a pointer to a Stack
 * @item a pointer to an Item
 */
void push(Stack *stack, Item *item) {
  if (stack->type != type) {
    printf("%s\n", "Invalid item type.");
  }
  else {
    int newSize = stack->top + 2;
    if (newSize == stack->maxSize) {
      stackResize(stack, stack->maxSize + 5);
      stack->maxSize = stack->maxSize + 5;
    }
    stack->top = stack->top + 1;
    (stack->items)[stack->top] = *item;
  }
}

/**
 * Pops an item from a stack and returns a copy of the top item.
 * @param stack a pointer to a Stack
 * @returns a copy of the Item that was popped or NULL if the stack is empty
 */
struct StackItem* pop(Stack *stack) {
  if (stack->top == -1) {
    printf("%s\n", "Stack underflow.");
    return NULL;
  }
  Item *item = malloc(sizeof(Item));
  item->element = ((stack->items)[stack->top]).element;
  stack->top = stack->top - 1;
  return item;
}

/**
 * Creates a stack on the heap and returns a pointer to it.
 * @param type the type of items the stack will hold.
 * @returns a pointer to the newly created stack.
 */
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

/**
 * Prints the contents of a stack, first-in first-printed.
 * @param stack a pointer to a stack.
 * @param type the type of elements in the stack.
 */
void stackPrint(Stack *stack, enum StackType type) {
  switch(type) {
    case String:
      for (int i = 0; i < (stack->top + 1); i++) {
        printf("%s, ", (stack->items)[i].element);
      }
      break;
    case Int:
      for (int i = 0; i < (stack->top + 1); i++) {
        printf("%d, ", *(int*)((stack->items)[i].element));
      }
      break;
    default:
      printf("%s\n", "Type not implemented yet.");
  }

  printf("\n");
}

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
  stackPrint(stackPointer, stackPointer->type);
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
  stackPrint(stackPointer, stackPointer->type);
  pop(stackPointer);
  pop(stackPointer);
  pop(stackPointer);
  pop(stackPointer);
  stackPrint(stackPointer, stackPointer->type);
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
  stackPrint(stackPointer, stackPointer->type);
}

int main() {
  stackStringTest();
  stackIntTest();
  return 0;
}
