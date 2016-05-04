// Modified from Solution. Should work. Tested locally only.
class Solution3 {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.size() <= 1) return true;
        int minVal = INT_MIN;
        stack<int> st;

        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] < minVal) return false;
            while (!st.empty() && preorder[i] > st.top()) {
                minVal = st.top();
                st.pop();
            }

            st.push(preorder[i]);
        }

        return true;
    }
};

// Works too. O(1) space. O(n) time. Tested. Modified from: 
// https://leetcode.com/discuss/59334/simple-accepted-iterative-solution-space-reducing-running
// Idea: In BST, preorder traversal, right branch node is already greater than left branch nodes.
class Solution2 {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return true;
        int minIndex = -1;
        int top = 0, end = 0;

        for (int i = 1; i < preorder.size(); i++) { // "int i = 0" works too.
            if (minIndex != -1 && preorder[i] < preorder[minIndex]) return false;
            //if (preorder[i] > preorder[i - 1]) // not needed
            while (top >= end && preorder[i] > preorder[top]) {
                minIndex = top;
                top--;
            }
            if (top < end) end = i;
            top = i;
        }

        return true;
    }
};

// Works. O(h) space. O(n) time. Tested. Modified from: 
// https://leetcode.com/discuss/59334/simple-accepted-iterative-solution-space-reducing-running
// Idea: In BST, preorder traversal, right branch node is already greater than left branch nodes.
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return true;
        int minVal = INT_MIN;
        stack<int> st;
        st.push(preorder[0]);

        for (int i = 1; i < preorder.size(); i++) {
            if (preorder[i] < minVal) return false;
            //if (preorder[i] > preorder[i - 1]) // no need. st.top is preorder[i-1].
            // remove all elements on st smaller than preorder[i], 
            // so st.top() is always the smallest element so far.
            while (!st.empty() && preorder[i] > st.top()) {
                minVal = st.top();
                st.pop();
            }

            st.push(preorder[i]);
        }

        return true;
    }
};

/**
Verify Preorder Sequence in Binary Search Tree
Difficulty: Medium

Given an array of numbers, verify whether it is the correct 
preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Follow up:
Could you do it using only constant space complexity?
 */
