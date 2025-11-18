// Same as Solution.
class Solution2 {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> result(n);  // Store the count of people each person can see
        stack<int> monotonicStack;  // Monotonic decreasing stack to track heights

        for (int i = n - 1; i >= 0; i--) { // Traverse from right to left
            while (! monotonicStack.empty() && monotonicStack.top() < heights[i]) {
                result[i]++;
                monotonicStack.pop(); // Pop all people shorter (visible) than current person
            }
          
            if (! monotonicStack.empty()) {
                result[i]++; // this person is taller and blocking the view, but still visible.
            }
          
            monotonicStack.push(heights[i]); // Add current person's height to the stack
        }
        return result;
    }
};

// From: https://algo.monster/liteproblems/1944
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> result(n);  // Store the count of people each person can see
        stack<int> monotonicStack;  // Monotonic decreasing stack to track heights

        for (int i = n - 1; i >= 0; i--) { // Traverse from right to left
            // Pop all people shorter than current person
            // These people can be seen by the current person
            while (! monotonicStack.empty() && monotonicStack.top() < heights[i]) {
                result[i]++;
                monotonicStack.pop();
            }
          
            // If stack still has elements, the top element is taller
            // and blocks the view, but this person can still be seen
            if (! monotonicStack.empty()) {
                result[i]++;
            }
          
            // Add current person's height to the stack
            monotonicStack.push(heights[i]);
        }
        return result;
    }
};

/**
1944. Number of Visible People in a Queue
Hard

There are n people standing in a queue, and they numbered from 0 to n - 1 in left to right order. 
You are given an array heights of distinct integers where heights[i] represents the height of the ith person.

A person can see another person to their right in the queue if everybody in between is shorter than 
both of them. More formally, the ith person can see the jth person if i < j and 
min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).

Return an array answer of length n where answer[i] is the number of people the ith person can see 
to their right in the queue.
 */
