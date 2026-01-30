#
# In a Python OrderedDict, the items are stored and iterated over in the order in which their keys were first inserted.
#
# The popitem() method for Dict: remove the last (inserted) time. LIFO.
#
# The popitem() method for a Python OrderedDict removes and returns a (key, value) pair. 
# Unlike a standard dictionary's popitem(), it accepts a last parameter (a boolean) to 
# control the order of removal. True - remove last (LIFO), False - remove first (FIFO).
#
# Python's OrderedDict is a hybrid data structure: DLL + HashMap, making it ideal for impleting LRU cache.
#
class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = collections.OrderedDict()

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        
        self.cache.move_to_end(key)
        return self.cache[key]
        
    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.move_to_end(key)
        self.cache[key] = value
        
        if len(self.cache) > self.capacity:
            self.cache.popitem(False)
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

/**
146. LRU Cache
Solved
Medium
Topics
conpanies iconCompanies

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the 
        key-value pair to the cache. If the number of keys exceeds the capacity from this operation, 
        evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.
 */
