// No extra space. Better than Solution3.
// From: https://leetcode.com/problems/product-of-array-except-self/editorial/
// Time: O(n), Space: O(1)
class Solution4 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        result[0] = 1;
        for (int i = 1; i < n; ++ i) {
            result[i] = result[i-1] * nums[i-1];
        }

        int prod = 1;
        for (int i = n-1; i > 0; -- i) {
            result[i] = result[i] * prod;
            prod *= nums[i];
        }
        result[0] = prod;

        return result;
    }
};

// Adapted from Solution2. No extra space.
// Space: O(1)
class Solution3 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        result[0] = nums[0];
        for (int i = 1; i < n-1; ++ i) {
            result[i] = result[i-1] * nums[i];
        }
        result[n-1] = result[n-2];

        int prod = nums[n-1];
        for (int i = n-2; i > 0; -- i) {
            result[i] = result[i-1] * prod;
            prod *= nums[i];
        }
        result[0] = prod;

        return result;
    }
};

// Works too. Tested.
class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return vector<int>(0);
        
        vector<int> A(n), B(n), ans(n);
        
        A[0] = nums[0];
        for (int i = 1; i < n; ++ i) A[i] = A[i-1] * nums[i];
        
        B[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; -- i) B[i] = B[i+1] * nums[i];
        
        ans[0] = B[1];      // <----- note this!
        ans[n-1] = A[n-2];  // <----- note this!
        for (int i = 1; i < n-1; ++ i) ans[i] = A[i-1] * B[i+1];
        
        return ans;
    }
};


/*
Example: nums = {2, 3, 4}

A: 2, 6, 24
B: 24, 12, 4

result: 12, 8, 6 
*/

class Solution {
public:
    // This works. Uses O(2n) extra space, for L[] and R[].
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return nums;

        vector<int> L(len);
        L[0] = nums[0];
        for (int i = 1; i < len; ++ i) L[i] = L[i-1] * nums[i];
        
        vector<int> R(len);
        R[len - 1] = nums[len - 1];
        for (int i = len - 2; i >= 0; -- i) R[i] = R[i+1] * nums[i];
        
        vector<int> ans(len);
        ans[0] = R[1];
        for (int i = 1; i < len - 1; ++ i) ans[i] = L[i-1] * R[i+1];
        ans[len - 1] = L[len - 2];
        
        return ans;
    }
    
    // This works too. Uses no extra space.
    vector<int> productExceptSelf2(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return nums;
        
        vector<int> ans(len);
        ans[0] = nums[0];
        for (int i = 1; i < len; ++ i) {
            ans[i] = ans[i-1] * nums[i];
        }
        
        for (int i = len - 2; i >= 0; -- i) {
            nums[i] *= nums[i+1];
        }
        
        ans[len - 1] = ans[len - 2];
        for (int i = len - 2; i >= 1; -- i) {
            ans[i] = ans[i-1] * nums[i+1];
        }
        ans[0] = nums[1];
        
        return ans;
    }
};


/**
Product of Array Except Self
Difficulty: Medium

Given an array of n integers where n > 1, nums, return an array output 
such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array 
does not count as extra space for the purpose of space complexity analysis.)
 */
