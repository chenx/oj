class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq = 0;
        map<int, int> freqCount; // <num, freq>
        for (int num : nums) {
            freqCount[num] ++;
            maxFreq = max(maxFreq, freqCount[num]);
        }

        int sum = 0;
        for (auto [num, freq] : freqCount) {
            if (freq == maxFreq) sum += maxFreq;
        }
        return sum;
    }
};


/**
3005. Count Elements With Maximum Frequency
Easy

You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.

 

Example 1:

Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.
 */
