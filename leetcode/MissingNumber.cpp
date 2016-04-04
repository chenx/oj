// Works.
// XOR from 1 ~ n, then nums[0] ~ nums[n-1].
// Basically same as Solution.
class Solution3 {
public:
    int missingNumber(vector<int>& nums) {
        int v = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            v ^= nums[i] ^ (i+1);
        }
        return v;
    }
};

// Works. Tested.
// Initialize v = nums.size() can be confusing later. Not recommended.
class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int v = nums.size();
        for (int i = 0; i < nums.size(); ++ i) {
            v ^= i;
            v ^= nums[i];
        }
        return v;
    }
};

// Works. Tested.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        
        int x = 0;
        for (int i = 0; i < len; ++ i) {
            x ^= (i+1);
            x ^= nums[i];
        }
        
        return x;
    }
};


/**
Missing Number
Difficulty: Medium
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
For example,
Given nums = [0, 1, 3] return 2.
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity? 
 */
