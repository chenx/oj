// From: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/editorial/
// Another method is counting with a map, which has space O(n).
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size = arr.size() / 4;
        for (int i = 0; i < arr.size() - size; ++ i) {
            if (arr[i] == arr[i + size]) return arr[i];
        }
        return 0;
    }
};


/**
1287. Element Appearing More Than 25% In Sorted Array
Easy

Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that 
occurs more than 25% of the time, return that integer.

 

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6

Example 2:

Input: arr = [1,1]
Output: 1
 */
