class Allocator:

    def __init__(self, n: int):
        self.capacity = n
        self.memory = [0] * n

    def allocate(self, size: int, mID: int) -> int:
        count = 0
        for i in range(self.capacity):
            if self.memory[i] == 0:
                count += 1
                if count == size:
                    start = i - count + 1
                    for j in range(start, i + 1):
                        self.memory[j] = mID
                    return start
            else:
                count = 0
        return -1
        

    def freeMemory(self, mID: int) -> int:
        count = 0
        for i in range(self.capacity):
            if self.memory[i] == mID:
                self.memory[i] = 0
                count += 1
        return count
        


# Your Allocator object will be instantiated and called as such:
# obj = Allocator(n)
# param_1 = obj.allocate(size,mID)
# param_2 = obj.freeMemory(mID)

/**
2502. Design Memory Allocator
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given an integer n representing the size of a 0-indexed memory array. All memory units are initially free.

You have a memory allocator with the following functionalities:

    Allocate a block of size consecutive free memory units and assign it the id mID.
    Free all memory units with the given id mID.

Note that:

    Multiple blocks can be allocated to the same mID.
    You should free all the memory units with mID, even if they were allocated in different blocks.

Implement the Allocator class:

    Allocator(int n) Initializes an Allocator object with a memory array of size n.
    int allocate(int size, int mID) Find the leftmost block of size consecutive free memory units and 
        allocate it with the id mID. Return the block's first index. If such a block does not exist, return -1.
    int freeMemory(int mID) Free all memory units with the id mID. Return the number of memory units you have freed.
 */
