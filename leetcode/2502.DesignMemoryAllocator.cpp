class Allocator2 {
private:
    vector<int> memory;

public:
    Allocator(int n) {
        memory = vector<int>(n, 0);
    }
    
    int allocate(int size, int mID) {
        int freeSpaces = 0;

        for (int i = 0; i < memory.size(); ++ i) {
            if (memory[i] == 0) {
                ++ freeSpaces;
                if (freeSpaces == size) {
                    int startIndex = i - size + 1;
                    fill(memory.begin() + startIndex, memory.begin() + i + 1, mID);
                    return startIndex;
                }
            } else {
                freeSpaces = 0;
            }
        }
        return -1;
    }
    
    int freeMemory(int mID) {
        int count = 0;
        for (int i = 0; i < memory.size(); ++ i) {
            if (memory[i] == mID) {
                memory[i] = 0;
                ++ count;
            }
        }
        return count;
    }
};

// From: https://algo.monster/liteproblems/2502
class Allocator {
private:
    vector<int> memory;  // Memory array where 0 indicates free space, positive values indicate allocated block IDs

public:
    // Initialize allocator with n units of memory
    Allocator(int n) {
        memory = vector<int>(n, 0);  // Initialize all memory units as free (0)
    }
  
    // Allocate a contiguous block of 'size' units with identifier 'mID'
    // Returns the starting index of allocated block, or -1 if allocation fails
    int allocate(int size, int mID) {
        int consecutiveFree = 0;  // Counter for consecutive free memory units
      
        for (int i = 0; i < memory.size(); ++i) {
            if (memory[i] > 0) {
                // Current unit is occupied, reset counter
                consecutiveFree = 0;
            } else {
                ++ consecutiveFree;
                if (consecutiveFree == size) {
                    // Found enough consecutive free units, mark the block as allocated with mID
                    int startIndex = i - size + 1;
                    fill(memory.begin() + startIndex, memory.begin() + i + 1, mID);
                    return startIndex;
                }
            }
        }
      
        return -1;  // No suitable contiguous block found
    }
  
    // Free all memory units allocated with identifier 'mID'
    // Returns the number of units freed
    int freeMemory(int mID) {
        int freedUnits = 0;  // Counter for freed memory units
      
        for (int i = 0; i < memory.size(); ++i) {
            if (memory[i] == mID) {
                memory[i] = 0;  // Mark unit as free
                ++freedUnits;
            }
        }      
        return freedUnits;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */

/**
2502. Design Memory Allocator
Medium

You are given an integer n representing the size of a 0-indexed memory array. All memory units are initially free.

You have a memory allocator with the following functionalities:

    Allocate a block of size consecutive free memory units and assign it the id mID.
    Free all memory units with the given id mID.

Note that:

    Multiple blocks can be allocated to the same mID.
    You should free all the memory units with mID, even if they were allocated in different blocks.

Implement the Allocator class:

    Allocator(int n) Initializes an Allocator object with a memory array of size n.
    int allocate(int size, int mID) Find the leftmost block of size consecutive free memory units and allocate it with 
      the id mID. Return the block's first index. If such a block does not exist, return -1.
    int freeMemory(int mID) Free all memory units with the id mID. Return the number of memory units you have freed.
 */
