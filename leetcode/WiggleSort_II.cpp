// Works. Tested. 
// From: https://leetcode.com/discuss/83704/java-9-ms-wiggled-and-randomized-quickselect
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        int n = nums.size(), d = n | 1; // now (1 + 2 * i) % d will go like 1, 3,... wrap-around, 0, 2,...
        int left = 0, right = nums.size() - 1, k = n / 2; // note: 0-based k
        // Do quickselect for kth LARGEST element. Use wiggle-indexing to get the answer right away.
        while (true) {
            //assert left <= right;
            int p = nums[(1 + 2 * (left + (right - left + 0))) % d];
            int l = left, m = l;
            for (int r = right, lw = (1 + 2 * l) % d, mw = lw, rw = (1 + 2 * r) % d; m <= r; ) {
                if (nums[mw] > p) {
                    swap(nums[mw], nums[lw]);
                    ++l; lw = (lw + 2) % d;
                    ++m; mw = (mw + 2) % d;
                } else if (nums[mw] < p) {
                    swap(nums[mw], nums[rw]);
                    --r; rw = (rw - 2 + d) % d;
                } else { // ==
                    ++m; mw = (mw + 2) % d;
                }
            }
            if (k < l - left) {
                right = l - 1;
            } else if (k >= m - left) {
                k -= m - left;
                left = m;
            } else {
                // else we got lucky - p is the median
                return;
            }
        }
    }
    
    // code below are for testing only.
    
    void f(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return;
        if (n == 2 && nums[0] > nums[1]) {
            swap(nums[0], nums[1]);
            return;
        }
        
        quickSelect(nums, 0, n-1, n/2 + 1);
        
        vector<int> A(n);
        if (n % 2 == 1) { // odd number
            /*for (int i = 1; i < n/2; i += 2) {
                swap(nums[i], nums[i + n/2 + 0]);
            }*/
            swap(nums[n/2], nums[n-1]);
            int k = 0;
            for (int i = 0; i < n/2; ++ i) {
                A[k ++] = nums[i];
                A[k ++] = nums[i + n/2];
            }
            A[k] = nums[n-1];
        }
        else {
            /*for (int i = 1; i < n/2; i += 2) {
                swap(nums[i], nums[i + n/2]);
            }*/
            int k = 0;
            for (int i = 0; i < n/2; ++ i) {
                A[k ++] = nums[i];
                A[k ++] = nums[i + n/2];
            }
        }
        
        for (int i = 0; i < n; ++ i) nums[i] = A[i];
    }
    
    void quickSelect(vector<int> &A, int left, int right, int k) {
        if (left >= right) return;
        
        swap(A[left], A[0 + (right + left)/2]);
        int pivot = A[left];
        int L = left + 1, R = right;
        
        while (L <= R) {
            while (L <= R && A[L] < pivot) ++ L;
            while (L <= R && A[R] > pivot) -- R;
            if (L < R) {
                swap(A[L], A[R]);
                ++ L; -- R;
            }
            else {
                ++ L;
            }
        }
        //while (left <= R && A[left] == A[R]) -- R;
        //swap(A[left], A[R]);
        int r = R;
        while (left < r && A[left] == A[r]) -- r;
        swap(A[left], A[r]);
        
        if (k < R) quickSelect(A, left, R-1, k);
        else if (k > R) quickSelect(A, R+1, right, k);
    }
};


/**
Wiggle Sort II
Difficulty: Medium

Given an unsorted array nums, reorder it such that 
nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space? 
 */