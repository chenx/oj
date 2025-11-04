// From https://leetcode.com/problems/maximum-swap/editorial/
// 2 passes:
// 1) from right to left, find the largest digit to the right of the current digit
// 2) from left to right, for the first digit less than its RHS largest digit, swap
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size();

        vector<int> maxOnRight(n, 0);
        maxOnRight[n-1] = n-1;
        for (int i = n-2; i >= 0; -- i) {
            if (str[i+1] > str[maxOnRight[i+1]]) maxOnRight[i] = i + 1;
            else maxOnRight[i] = maxOnRight[i+1];
        }

        for (int i = 0; i < n-1; ++ i) {
            if (str[i] < str[maxOnRight[i]]) {
                swap(str[i], str[maxOnRight[i]]);
                break;
            }
        }
        return stoi(str);
    }
};

/**
670. Maximum Swap
Medium

You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.

 

Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.

Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.
 */
