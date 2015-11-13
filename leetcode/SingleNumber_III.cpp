// This works. 
// Modified from: https://leetcode.com/discuss/67701/simple-solution-in-java
// There are many ways to solving this. 
// E.g., sort first, but that's O(nlogn). Or use a hash to count occurences, but space is O(n).
// Key is to find a property to separate the 2 numbers.
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0, len = nums.size();
        for (int i = 0; i < len; ++ i) {
            x ^= nums[i];
        }
        
        int mask = x & ~(x - 1); // or x & (~x + 1)
        vector<int> v(2, 0); // initialize to 0.
        
        for (int i = 0; i < len; ++ i) {
            // must put "()" around & statement.
            if ((nums[i] & mask) == 0) v[0] ^= nums[i]; 
            else v[1] ^= nums[i];
        }

        return v;        
    }
};

// This also works. 
// From https://leetcode.com/discuss/61036/20-ms-c-solution
class Solution2 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xXor = nums[0];
        for (int i = 1; i<nums.size(); i++) {
            xXor = xXor ^ nums[i];
        }
    
        // another way to get marker.
        int marker = 1; 
        while ((marker & xXor) != marker) {
            marker = marker << 1;
        }
    
        int resultX = 0;
        for (int i = 0; i<nums.size(); i++) {
            if (nums[i] & marker) {
                resultX = resultX^nums[i];
            }
        }
    
        int resultY = resultX^xXor;
    
        return vector<int>{resultX, resultY};       
    }
};

// This works too.
// From: https://leetcode.com/discuss/58189/3-line-c-o-1-space-o-n-time
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a = 0, b = 0, s = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        for (auto n : nums) (n & s & -s) ? a ^= n : b ^= n;
        return vector<int>{a, b};
    }
};

/**
Single Number III
Difficulty: Medium

Given an array of numbers nums, in which exactly two elements appear 
only once and all the other elements appear exactly twice. 
Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:

    The order of the result is not important. 
    So in the above example, [5, 3] is also correct.
    
    Your algorithm should run in linear runtime complexity. 
    Could you implement it using only constant space complexity?

 */
