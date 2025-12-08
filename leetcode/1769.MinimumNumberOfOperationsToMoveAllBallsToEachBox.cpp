// From: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/editorial/
// Sum of Left and Right Moves
// Time: O(n)
// Space: O(1)
class Solution3 {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);

        int ballsToLeft = 0, movesToLeft = 0;
        int ballsToRight = 0, movesToRight = 0;

        // Single pass: calculate moves from both left and right
        for (int i = 0; i < n; i++) {
            // Left pass
            answer[i] += movesToLeft;
            ballsToLeft += boxes[i] - '0';
            movesToLeft += ballsToLeft;

            // Right pass
            int j = n - 1 - i;
            answer[j] += movesToRight;
            ballsToRight += boxes[j] - '0';
            movesToRight += ballsToRight;
        }

        return answer;
    }
};


// Brute force
// Time: O(n^2)
// Space: O(1)
class Solution2 {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (i != j && boxes[j] == '1') result[i] += abs(i - j);
            }
        }
        return result;
    }
};


// Brute force
// Time: O(n^2)
// Space: O(n)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        set<int> set; // <index, 1>
        for (int i = 0; i < boxes.size(); ++ i) {
            if (boxes[i] == '1') set.insert(i);
        }

        vector<int> result(boxes.size(), 0);
        for (int i = 0; i < boxes.size(); ++ i) {
            for (int index : set) {
                if (index != i) result[i] += abs(index - i);
            }
        }
        return result;
    }
};


/**
1769. Minimum Number of Operations to Move All Balls to Each Box
Medium

You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' 
if the ith box is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent 
to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations 
needed to move all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.

 

Example 1:

Input: boxes = "110"
Output: [1,1,3]
 */
