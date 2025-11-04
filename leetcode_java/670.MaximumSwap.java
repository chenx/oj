// From https://leetcode.com/problems/maximum-swap/editorial/
// 2 passes:
// 1) from right to left, find the largest digit to the right of the current digit
// 2) from left to right, for the first digit less than its RHS largest digit, swap
class Solution {
    public int maximumSwap(int num) {
        char[] arr = Integer.toString(num).toCharArray();
        int n = arr.length;
        int[] maxOnRight = new int[n];

        maxOnRight[n-1] = n-1;
        for (int i = n-2; i >= 0; -- i) {
            if (arr[i+1] > arr[maxOnRight[i+1]]) maxOnRight[i] = i+1;
            else maxOnRight[i] = maxOnRight[i+1];
        }

        for (int i = 0; i < n-1; ++ i) {
            if (arr[i] < arr[maxOnRight[i]]) {
                char ch = arr[i];
                arr[i] = arr[maxOnRight[i]];
                arr[maxOnRight[i]] = ch;
                break;
            }
        }

        String result = new String(arr);
        return Integer.valueOf(result);
    }
}

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
