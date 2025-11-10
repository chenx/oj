class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n - 1;
        
        while (left < right) {
            int mid = right - (right - left) / 2;
            if (nums[mid] - nums[0] - mid < k) {
                left = mid;
            } else{
                right = mid - 1;
            }
        }
        
        return nums[0] + k + left;
    }

    int missingElement2(vector<int>& nums, int k) {
        set<int> set;
        for (int n : nums) set.insert(n);
        int p = nums[0];
        while (true) {
            if (! set.contains(p)) -- k;
            if (k == 0) return p;

            ++ p;
        }
    }
};

/**
1060. Missing Element in Sorted Array
Medium

Given an integer array nums which is sorted in ascending order and all of its elements are unique and given also an integer k, 
return the kth missing number starting from the leftmost number of the array.
 */
