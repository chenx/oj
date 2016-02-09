// All 3 methods below are O(N) time, O(1) space.
class Solution {
public:
    // Works. Tested.
    // Similar to the problem "Find first missing positive".
    int findDuplicate3(vector<int>& A) {
        int len = A.size(), i;
        for (i = 0; i < len; ++ i) {
            while (A[i] != i + 1 && A[i] != A[A[i] - 1]) {
                swap(A[i], A[A[i] - 1]);
            }
            if (A[i] != i + 1 && A[A[i] - 1] == A[i]) return A[i];
        }
        return len; // actually this doesn't matter. will always return above.
    }
    
    // Works. Tested.
    // From: https://leetcode.com/discuss/68501/java-o-n-solution
    int findDuplicate2(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return -1;
        
        int i = 0;
        while (i < len) {
            if (nums[i] != i + 1) {
                if (nums[i] == nums[nums[i]-1]) return nums[i];
                swap(nums[i], nums[nums[i]-1]);
            } else {
                ++ i;
            }
        }
        return i;
    }

    // Works. Tested.
    // Similar to find cycle in loop.
    // From: https://leetcode.com/discuss/69766/share-my-solution-o-n-time-o-1-space-12-ms
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        int finder = 0;
    
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
    
            if (slow == fast)
                break;
        }
        while (true)
        {
            slow = nums[slow];
            finder = nums[finder];
            if (slow == finder)
                return slow;
        }        
    }
};

/**
Find the Duplicate Number
Difficulty: Hard

Given an array nums containing n + 1 integers where each integer is 
between 1 and n (inclusive), prove that at least one duplicate number 
must exist. Assume that there is only one duplicate number, find the 
duplicate one.

Note:

    You must not modify the array (assume the array is read only).
    You must use only constant, O(1) extra space.
    Your runtime complexity should be less than O(n2).
    There is only one duplicate number in the array, but it could be 
    repeated more than once.

 */
