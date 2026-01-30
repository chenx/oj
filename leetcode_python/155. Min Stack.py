class MinStack:

    def __init__(self):
        self.minStack = []
        self.valStack = []

    def push(self, val: int) -> None:
        if len(self.valStack) == 0:
            self.minStack.append(val)
        else:
            self.minStack.append(min(val, self.minStack[-1]))

        self.valStack.append(val)


    def pop(self) -> None:
        if len(self.valStack) == 0:
            return
        
        self.valStack.pop()
        self.minStack.pop()
        

    def top(self) -> int:
        if len(self.valStack) == 0:
            return -1
        
        return self.valStack[-1]

    def getMin(self) -> int:
        if len(self.minStack) == 0:
            return -1
        
        return self.minStack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()

/**
155. Min Stack
Solved
Medium
Topics
conpanies iconCompanies
Hint

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

    MinStack() initializes the stack object.
    void push(int val) pushes the element val onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.
 */
