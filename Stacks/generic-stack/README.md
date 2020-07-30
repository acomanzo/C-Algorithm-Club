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
## Dynamic Block Implementation
This implementation uses a dynamic block of memory to represent the stack.
What that means is that when you create a stack you're receiving a pointer to
a section of your computer's memory that spans one or more stack items. Since
there's no way to tell how big of a stack you'll need upon creation, a block
on the heap is necessary if you don't use a fixed sized stack. When you push
an item to the stack, if the stack is full, it will automatically resize to
accommodate the new item. It uses realloc to resize which will simply
enlarge the stack or copy the stack to a new block if it's impossible to
resize the stack where it is in memory.
## Triple Pointer
This is the first way I tried implementing a stack in C! I can't figure it
out yet but I'd like to! The idea was that you could access the elements
like you would an array or in the dynamic block implementation but create
new elements similar to how you would with a linked list (except you'd
realloc the stack for every one new item). Think of it as a pointer to an
array of pointers.
## Linked List
The nice thing about this implementation is that it does not require a
contiguous block of memory. Rather, whenever you push an item to the stack,
a new section of memory is allocated to accommodate a new stack item. For
this reason you could consider a linked list implementation to be more
flexible since you don't need to know the max stack size upon creation
and because there are fewer memory rewrites when resizing a stack
(in fact, there are none!). 
