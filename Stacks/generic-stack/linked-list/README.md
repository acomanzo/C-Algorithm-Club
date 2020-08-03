# Linked List
The nice thing about this implementation is that it does not require a
contiguous block of memory. Rather, whenever you push an item to the stack,
a new section of memory is allocated to accommodate a new stack item. For
this reason you could consider a linked list implementation to be more
flexible since you don't need to know the max stack size upon creation
and because there are fewer memory rewrites when resizing a stack
(in fact, there are none!).
