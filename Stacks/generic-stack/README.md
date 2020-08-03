# Generic Stacks
A stack is quite literally a stack of items and you can think of it like a stack of
plates or cars in a driveway. It's a special type of list with two important
functions: push and pop. Push puts an item on top of the stack while pop gives you
the item on the top of the stack.
So why would you want to use a stack? Well, maybe you quite literally need to
represent a stack of plates or cars in a driveway. In other cases
they're useful for parsing problems and puzzles like evaluating infix, prefix,
or postfix expressions and the Towers of Hanoi. One of the most famous stacks is
the call stack! And if you're a computer programmer, chances are you use it
almost every day.
# Asymptotic Notation
In general, stack operations (push, pop) take O(1) time.
That's because you're always pushing and popping the top of the stack, so
no need to traverse in most cases.
If for some reason you wanted to access the nth element of a stack then
the time differs depending on the implementation. In a linked list
implementation retrieval is O(n) but in the dynamic block implementation
it takes O(1) time because the block is contiguous and we use it like an
array.
No matter the implementation, searching for a particular element will take
O(n) time if we don't know what index that element exists at.
Stacks' space complexity is O(n).
###### *\*where n is the size of the stack*
# Stack Functions in Detail
### Here's how stacks work (via linked list):
1. Create a stack:
    ```c
    Stack *stackCreate() {
      Stack *stack;
      if ((stack = malloc(sizeof(Stack))) == NULL) {
        printf("%s\n", "Cannot allocate space for new stack.");
        exit(EXIT_FAILURE);
      }
      stack->top = NULL;
      return stack;
    }
    Stack *stack = stackCreate();
    ```
    Right now the stack looks like `[]`
2. Make an item and push to the stack:
    ```c
    Item *temp = malloc(sizeof(Item));
    temp->element = "5";
    push(stack, temp);
    ```
    After that, the stack looks like `["5"]`
3. Push another item to the stack:
    ```c
    Item *temp = malloc(sizeof(Item));
    temp->element = "32478";
    push(stack, temp);
    ```
    This is what the stack looks like:
    `["5", "32478"]`
    Say we push five more items to the stack and it looks like this:
    `["5", "32478", "10", "-23", "100", "1000", "10000"]`
    And now we want to pop the stack.
4. Pop the top item:
    ```c
    Item temp = pop(stack);
    ```
    The stack should look like this
    `["5", "32478", "10", "-23", "100", "1000"]`
    and temp should be pointing to an address where we can access the
    element ("10000").
