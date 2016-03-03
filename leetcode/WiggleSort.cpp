// Should work. Not tested.
class Solution3 {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size() - 1;
        for (int i = 0; i < len; ++ i) {
            if (i & 1 == 0) {
                if (nums[i] > nums[i+1]) swap(nums[i], nums[i+1]);
            }
            else {
                if (nums[i] < nums[i+1]) swap(nums[i], nums[i+1]);
            }
        }
    }
};

// Works. Tested. Basically same as Solution. Solution is actually better.
// Idea:
// Go through the array once and keep in mind whether we need the 
// current element be larger or smaller than the previous one. If 
// we need it to be larger yet it is actually smaller (or we need 
// smaller but it is larger), swap them. Otherwise, proceed without 
// any operation.
// It can be shown that the method above can always output a valid 
// solution. The proof is left for you :P
// From: https://leetcode.com/discuss/59135/simple-c-solution-with-explanation
class Solution2 {
public:
    void wiggleSort(vector<int>& nums) {
        bool flag = false;
        for (int i = 1; i < nums.size(); i++) {
            if (flag ? (nums[i] >= nums[i - 1]) : (nums[i] <= nums[i - 1]))
                swap(nums[i], nums[i - 1]);
            flag = !flag;
        }
        return ;
    }
};


// Works. Tested. O(n). 
// From: https://leetcode.com/discuss/69508/c-o-n-concise-solution
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int n = nums.size();
        
        for (int i = 0; i < n-1; ++ i) {
            if (i%2 == 0 && nums[i] > nums[i+1]) swap(nums[i], nums[i+1]);
            if (i%2 == 1 && nums[i] < nums[i+1]) swap(nums[i], nums[i+1]);
        }
    }
};


/**
Wiggle Sort
Difficulty: Medium

Given an unsorted array nums, reorder it in-place such that 
nums[0] <= nums[1] >= nums[2] <= nums[3]....

For example, given nums = [3, 5, 2, 1, 6, 4], one possible 
answer is [1, 6, 2, 5, 3, 4].
 */
