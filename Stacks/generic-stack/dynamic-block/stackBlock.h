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
int stackEmpty(Stack *stackPointer);

/**
 * Resizes a stack with realloc.
 * @param stack a pointer to a Stack.
 * @param newSize an integer in bytes representing the size of the
 * pointer to the new stack.
 */
void stackResize(Stack *stack, int newSize);

/**
 * Pushes an item to a stack.
 * @param stack a pointer to a Stack
 * @item a pointer to an Item
 */
void push(Stack *stack, Item *item);

/**
 * Pops an item from a stack and returns a copy of the top item.
 * @param stack a pointer to a Stack
 * @returns a copy of the Item that was popped or NULL if the stack is empty
 */
Item* pop(Stack *stack);

/**
 * Creates a stack on the heap and returns a pointer to it.
 * @param type the type of items the stack will hold.
 * @returns a pointer to the newly created stack.
 */
Stack* stackCreate(enum StackType type);

/**
 * Prints the contents of a stack bottom to top if the user selects a
 * non-struct type otherwise executes a user defined print function.
 * @param stack a pointer to a stack.
 * @param type the type of elements in the stack.
 */
void stackPrint(Stack *stack, enum StackType type, void (*printFunc)(Stack *));
