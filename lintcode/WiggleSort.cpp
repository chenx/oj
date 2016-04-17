class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        for (int i = 1; i < nums.size(); ++ i) {
            if ((i & 1) && nums[i-1] > nums[i])  swap(nums[i-1], nums[i]);
            if (!(i & 1) && nums[i-1] < nums[i]) swap(nums[i-1], nums[i]);
        }
    }
};


/**
Wiggle Sort

Given an unsorted array nums, reorder it in-place such that

nums[0] <= nums[1] >= nums[2] <= nums[3]....

Have you met this question in a real interview?
Notice

Please complete the problem in-place.
Example

Given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].

 */
