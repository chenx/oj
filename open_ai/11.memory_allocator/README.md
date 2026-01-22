
# Data structures to implement memory allocator

Memory allocators use various data structures to manage the heap memory efficiently, primarily by keeping track of both allocated and free blocks. Common choices include linked lists and binary trees, often with additional metadata for each memory block. 

Key data structures and concepts used in implementing memory allocators:

- Memory Block Structure: Each chunk of memory is typically preceded by a metadata structure (a header/footer) that stores vital information:

  - Size of the block.
  - Allocation status (free or used).
  - Pointers to link it with the next/previous blocks in a list.

- Free Lists (Linked Lists): This is one of the most common and fundamental data structures for general-purpose allocators.

  - A singly or doubly linked list is used to store only the free blocks of memory.
  - When an allocation is requested, the allocator searches this list for a suitable free block (using algorithms like First Fit, Best Fit, etc.).
  - This allows for out-of-order deallocation and variable block sizes, though search time can vary with list size.

- Memory Pools (Object Pools): This strategy is used for performance-critical scenarios, especially when allocating and deallocating many objects of the same size.

  - It pre-allocates a large, fixed-size chunk of memory and manages smaller, fixed-size slots within it.
  - A free list often manages the available slots within the pool.
  - Allocation and deallocation are very fast (often constant time, O(1)).

- Binary Trees / Buddy Systems: For more complex, high-performance allocators (like the jemalloc library used in production systems), tree-based structures are used.
  - The buddy memory allocation system often uses a binary tree to represent memory blocks and their availability, allowing for efficient merging (coalescing) of adjacent free blocks.
  - Other balanced trees like red-black trees can also manage free blocks, offering better performance guarantees for finding the optimal block size. 

The choice of data structure largely depends on the specific performance requirements, expected allocation patterns (e.g., variable vs. fixed size), and potential for memory fragmentation. 


## Binary Tree (buddy system)

A memory allocator implemented with a binary tree typically uses a buddy memory allocation system, 
which efficiently manages memory by dividing it into power-of-two sized blocks. 

Concept Overview The buddy allocator works by managing a fixed-size memory pool (e.g., 256 KB) and a binary tree 
(or an array representation of one) that tracks the status of memory blocks. 

- Initialization: The entire memory pool starts as one large, free block (the root of the tree).
- Allocation: When a memory request is made, the algorithm finds the smallest available block that is large enough to satisfy the request. 
  If the found block is too large, it is recursively split into two "buddies" until a block of the appropriate power-of-two size is reached. 
  One buddy is allocated, and the other remains free.
- Deallocation (Freeing): When a block is freed, the allocator checks its "buddy" (the other half of the split pair). 
  If the buddy is also free, the two are merged to form a larger free block. 
  This coalescing process continues up the tree hierarchy, reducing external fragmentation and making larger blocks available 
  for future allocations. 

Implementation Details 

- Key aspects of implementing a binary tree based memory allocator include: 
- Data Structure: An array-based representation of a complete binary tree is often used for efficiency, 
  as it avoids the overhead of managing pointers for each node.
- Metadata: Information about each block (size, allocated/free status, etc.) is tracked in the tree or 
  in a header/footer within the memory block itself.
- Operations: Both allocation and deallocation operations typically run in logarithmic time, \(O(\log N)\), 
  where \(N\) is the maximum number of possible allocations, which is efficient.

Fragmentation: While it minimizes external fragmentation through coalescing, the power-of-two block sizing 
can lead to internal fragmentation (allocating more memory than requested). 

Resources for Further Exploration You can find more detailed descriptions and sample implementations through 
these resources: 

- Conceptual Explanations: The buddy memory allocation article on Wikipedia provides a good overview of the algorithm.
- Example Code:An implementation of buddy memory allocation is available on GitHub.
  The OSDev forums have discussions on implementing allocators.FreeRTOS offers several simple reference implementations 
  of heap memory allocators.
- Design Guidance: The blog post series "Memory Allocation Strategies" is a good guide for identifying use cases and design patterns. 
  
## References

- https://medium.com/howsofcoding/custom-memory-allocator-malloc-62d28e10bfb8
- Memory allocation schema: Best Fit, First Fit, Second Fit
