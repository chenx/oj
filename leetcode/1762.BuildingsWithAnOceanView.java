// Use vector as stack.
// Time: O(n)
// Space: O(n)
class Solution2 {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> result;
        for (int i = heights.size() - 1; i >= 0; -- i) {
            if (result.empty() || heights[i] > heights[result.back()]) result.push_back(i);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        // use a stack, go from right to left
        // if stack is empty or new building height > stack top height, push to stack; otherwise ignore

        stack<int> stack;
        for (int i = heights.size() - 1; i >= 0; -- i) {
            if (stack.empty() || heights[i] > heights[stack.top()]) stack.push(i);
        }

        vector<int> ans;
        while (! stack.empty()) {
            ans.push_back(stack.top());
            stack.pop();
        }
        return ans;
    }
};

/**
1762. Buildings With an Ocean View
Medium

There are n buildings in a line. You are given an integer array heights of size n that represents the heights of the buildings in the line.

The ocean is to the right of the buildings. A building has an ocean view if the building can see the ocean without obstructions. 
Formally, a building has an ocean view if all the buildings to its right have a smaller height.

Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.

 */
