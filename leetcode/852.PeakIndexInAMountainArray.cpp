// Binary search.
// From: https://leetcode.com/problems/peak-index-in-a-mountain-array/editorial/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int L = 0, R = arr.size() - 1;
        while (L < R) {
            int M = L + (R-L)/2;
            if (arr[M] < arr[M+1]) {
                L = M + 1;
            } else {
                R = M;
            }
        }
        return L;
    }
};

// Linear scan.
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; ++ i) {
            if (arr[i] > arr[i+1]) return i;
        }
        return arr.size() - 1;
    }
};


/**
852. Peak Index in a Mountain Array
Medium

You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.

 

Example 1:

Input: arr = [0,1,0]
Output: 1

Example 2:

Input: arr = [0,2,1,0]
Output: 1

Example 3:

Input: arr = [0,10,5,2]
Output: 1
 */
