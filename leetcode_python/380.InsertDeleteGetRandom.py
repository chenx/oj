import random

class RandomizedSet:

    def __init__(self):
        self.nums : List[int] = []
        self.posMap : dict[int, int] = {}
        

    def insert(self, val: int) -> bool:
        if val in self.posMap:
            return False

        self.nums.append(val)
        self.posMap[val] = len(self.nums) - 1
        return True
        

    def remove(self, val: int) -> bool:
        if not val in self.posMap:
            return False
        
        # swap val with the last element
        valIndex = self.posMap[val]
        endVal = self.nums[-1]
        endIndex = len(self.nums) - 1
        self.nums[valIndex] = endVal
        self.posMap[endVal] = valIndex
        self.posMap.pop(val)
        self.nums.pop()
        return True
        

    def getRandom(self) -> int:
        # randint(a, b), return random number in [a, b], inclusive.
        randIndex = random.randint(0, len(self.nums) - 1)
        return self.nums[randIndex]


class RandomizedSet:

    def __init__(self):
        self.arr = []
        self.positionMap = {}

    def insert(self, val: int) -> bool:
        if val in self.positionMap:
            return False

        self.arr.append(val)
        self.positionMap[val] = len(self.arr) - 1
        return True
        

    def remove(self, val: int) -> bool:
        if not val in self.positionMap: 
            return False

        n = len(self.arr)
        index = self.positionMap[val]
        self.arr[index], self.arr[n-1] = self.arr[n-1], self.arr[index]
        
        self.positionMap[self.arr[index]] = index
        del self.positionMap[val]

        self.arr.pop()
        return True
        

    def getRandom(self) -> int:
        n = len(self.arr)
        if n == 0:
            return -1
        index = int(n * random.random())
        return self.arr[index]
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()

/**
380. Insert Delete GetRandom O(1)
Solved
Medium
Topics
conpanies iconCompanies

Implement the RandomizedSet class:

    RandomizedSet() Initializes the RandomizedSet object.
    bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
    bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
    int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least 
        one element exists when this method is called). Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in average O(1) time complexity.
 */
