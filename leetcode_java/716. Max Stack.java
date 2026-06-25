class MaxStack {
    private TreeSet<int[]> maxStack; // [value, count]
    private TreeSet<int[]> valStack; // [count, value]
    private int count;

    public MaxStack() {
        Comparator<int[]> comp = (a, b) -> {
            return a[0] == b[0] ? a[1] - b[1] : a[0] - b[0];
        };
        maxStack = new TreeSet<int[]>(comp);
        valStack = new TreeSet(comp);
    }
    
    public void push(int x) {
        ++ count;
        valStack.add(new int[] {count, x});
        maxStack.add(new int[] {x, count});
    }
    
    public int pop() {
        int[] pair = valStack.pollLast();
        maxStack.remove(new int[] { pair[1], pair[0] });
        return pair[1];
    }
    
    public int top() {
        return valStack.last()[1];
    }
    
    public int peekMax() {
        return maxStack.last()[0];
    }
    
    public int popMax() {
        int[] pair = maxStack.pollLast();
        valStack.remove(new int[] { pair[1], pair[0] });
        return pair[0];
    }
}

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */

/**
716. Max Stack
Solved
Hard
Topics
conpanies iconCompanies

Design a max stack data structure that supports the stack operations and supports finding the stack's maximum element.

Implement the MaxStack class:

    MaxStack() Initializes the stack object.
    void push(int x) Pushes element x onto the stack.
    int pop() Removes the element on top of the stack and returns it.
    int top() Gets the element on the top of the stack without removing it.
    int peekMax() Retrieves the maximum element in the stack without removing it.
    int popMax() Retrieves the maximum element in the stack and removes it. If there is more than one maximum element, 
        only remove the top-most one.

You must come up with a solution that supports O(1) for each top call and O(logn) for each other call.

 

Example 1:

Input
["MaxStack", "push", "push", "push", "top", "popMax", "top", "peekMax", "pop", "top"]
[[], [5], [1], [5], [], [], [], [], [], []]
Output
[null, null, null, null, 5, 5, 1, 5, 1, 5]
 */
