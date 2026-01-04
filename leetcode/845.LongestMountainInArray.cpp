// Same as Solution.
class Solution2 {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size(), ans = 0, i = 0;
        while (i < n) {
            int j = i;
            // if i is a left-boundary
            if (j + 1 < n && arr[j] < arr[j + 1]) {
                // set j to the peak of this potential mountain
                while (j + 1 < n && arr[j] < arr[j + 1]) j++;

                // if j is really a peak..
                if (j + 1 < n && arr[j] > arr[j + 1]) {
                    // set j to the right-boundary of mountain
                    while (j + 1 < n && arr[j] > arr[j + 1]) j++;
                    // record candidate answer
                    ans = max(ans, j - i + 1);
                }
            }

            i = max(j, i + 1);
        }

        return ans;
    }
};

// From: https://leetcode.com/problems/longest-mountain-in-array/editorial/
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0, base = 0;
        while (base < n) {
            int end = base;
            // if base is a left-boundary
            if (end + 1 < n && arr[end] < arr[end + 1]) {
                // set end to the peak of this potential mountain
                while (end + 1 < n && arr[end] < arr[end + 1]) end++;

                // if end is really a peak..
                if (end + 1 < n && arr[end] > arr[end + 1]) {
                    // set end to the right-boundary of mountain
                    while (end + 1 < n && arr[end] > arr[end + 1]) end++;
                    // record candidate answer
                    ans = max(ans, end - base + 1);
                }
            }

            base = max(end, base + 1);
        }

        return ans;
    }
};


/**
845. Longest Mountain in Array
Medium

You may recall that an array arr is a mountain array if and only if:

    arr.length >= 3
    There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
        arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
        arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given an integer array arr, return the length of the longest subarray, which is a mountain. 
Return 0 if there is no mountain subarray.

 

Example 1:

Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

Example 2:

Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.
 */
