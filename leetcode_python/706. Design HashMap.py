class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.next = None

class MyHashMap:

    def __init__(self):
        self.size = 2069
        self.arr = [Node(0, 0) for _ in range(self.size)]

    def put(self, key: int, value: int) -> None:
        tail = self.arr[key % self.size]
        while tail.next:
            if tail.next.key == key:
                tail.next.val = value
                return
            tail = tail.next

        # insert at the end.
        tail.next = Node(key, value)
        

    def get(self, key: int) -> int:
        tail = self.arr[key % self.size]
        while tail.next:
            if tail.next.key == key:
                return tail.next.val
            tail = tail.next
        return -1


    def remove(self, key: int) -> None:
        tail = self.arr[key % self.size]
        while tail.next:
            if tail.next.key == key:
                tail.next = tail.next.next
                return
            tail = tail.next


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)

/**
706. Design HashMap
Solved
Easy
Topics
conpanies iconCompanies

Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

    MyHashMap() initializes the object with an empty map.
    void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists 
        in the map, update the corresponding value.
    int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains 
        no mapping for the key.
    void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.

 

Example 1:

Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]
 */
