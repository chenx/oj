// Works. Same as Solution, but code cleaned.
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        quickSelect(nums, 0, n - 1, n - k);
        return nums[n - k];
    }
    
    void quickSelect(vector<int> &nums, int left, int right, int k) {
        if (left >= right) return;
        
        swap(nums[left + (right - left)/2], nums[left]);
        int pivot = nums[left], L = left + 1, R = right;
        
        while (L <= R) {
            while (L <= R && nums[L] < pivot) ++ L;
            while (L <= R && nums[R] > pivot) -- R;
            if (L < R) swap(nums[L ++], nums[R --]);
            else ++ L;
        }
        
        swap(nums[left], nums[R]);
        if (k < R) quickSelect(nums, left, R - 1, k);
        else if (k > R) quickSelect(nums, R + 1, right, k);
    }
};

// Works.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        findKth(nums, 0, len - 1, len - k);
        return nums[len - k];
    }
    
    void findKth(vector<int> & nums, int left, int right, int k) {
        if (left >= right) return;
        
        swap(nums[left], nums[left + (right - left) / 2]); // no need for "mid".
        int pivot = nums[left];
        int L = left + 1, R = right;
        
        while (L <= R) { // here and below, 3 "L <= R" is demanded!
            // seems for 1-3) below, < or <=, > or >=, < or <= don't matter. but keep as is now when coding.
            while (L <= R && nums[L] < pivot) ++ L; // 1)
            while (L <= R && nums[R] > pivot) -- R; // 2)
            if (L < R) { // 3)
                swap(nums[L], nums[R]);
                ++ L; -- R;
            }
            else {
                ++ L;
            }
        }
        swap(nums[left], nums[R]); // here and below, use "R", not "mid"!
        
        if (R < k) findKth(nums, R+1, right, k);
        if (R > k) findKth(nums, left, R-1, k);
    }
    
};


/**
Kth Largest Element in an Array
Difficulty: Medium

Find the kth largest element in an unsorted array. Note that it is the 
kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
 */
