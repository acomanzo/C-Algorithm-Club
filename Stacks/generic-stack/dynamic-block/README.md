# Dynamic Block Implementation
This implementation uses a dynamic block of memory to represent the stack.
What that means is that when you create a stack you're receiving a pointer to
a section of your computer's memory that spans one or more stack items. Since
there's no way to tell how big of a stack you'll need upon creation, a block
on the heap is necessary if you don't use a fixed sized stack. When you push
an item to the stack, if the stack is full, it will automatically resize to
accommodate the new item. It uses realloc to resize which will simply
enlarge the stack or copy the stack to a new block if it's impossible to
resize the stack where it is in memory.
