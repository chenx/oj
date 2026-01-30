from sortedcontainers import SortedList

class MaxStack:

    def __init__(self):
        self.stack = SortedList()
        self.values = SortedList()
        self.cnt = 0

    def push(self, x: int) -> None:
        self.stack.add((self.cnt, x))
        self.values.add((x, self.cnt))
        self.cnt += 1

    def pop(self) -> int:
        idx, val = self.stack.pop()
        self.values.remove((val, idx))
        return val

    def top(self) -> int:
        return self.stack[-1][1]

    def peekMax(self) -> int:
        return self.values[-1][0]

    def popMax(self) -> int:
        val, idx = self.values.pop()
        self.stack.remove((idx, val))
        return val

/**
The sortedcontainers Python library's SortedList uses a segmented-list data structure that is similar to a B-tree, 
but limited to two levels of nodes. 

This approach leverages the high performance of Python's built-in list operations while providing efficient 
O(log n) time complexity for most operations.
 */

/**
716. Max Stack
Solved
Hard
Topics
conpanies iconCompanies

Design a max stack data structure that supports the stack operations and supports finding the 
stack's maximum element.

Implement the MaxStack class:

    MaxStack() Initializes the stack object.
    void push(int x) Pushes element x onto the stack.
    int pop() Removes the element on top of the stack and returns it.
    int top() Gets the element on the top of the stack without removing it.
    int peekMax() Retrieves the maximum element in the stack without removing it.
    int popMax() Retrieves the maximum element in the stack and removes it. If there is more 
than one maximum element, only remove the top-most one.

You must come up with a solution that supports O(1) for each top call and O(logn) for each other call.
 */

