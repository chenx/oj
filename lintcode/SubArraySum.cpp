class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        int sum = 0;
        unordered_map<int, int> s;
        s[0] = -1;   // <- note this!  For situation where the subarray starts from index 0.
        for (int i = 0; i < nums.size(); ++ i) {
            sum += nums[i];
            if (s.find(sum) != s.end()) return vector<int>({s[sum] + 1, i});
            s[sum] = i;
        }
        return vector<int>({-1,-1});
    }
};


/**
Subarray Sum

Given an integer array, find a subarray where the sum of numbers is zero. 
Your code should return the index of the first number and the index of the last number.
Have you met this question in a real interview?
Notice

There is at least one subarray that it's sum equals to zero.
Example

Given [-3, 1, 2, -3, 4], return [0, 2] or [1, 3].

 */
