// From: https://leetcode.com/problems/reverse-pairs/editorial/
// Modified Merge Sort
// Time complexity: O(nlogn)
// Space complexity: O(n). Additional space for BITS array 
class Solution2 {
public:
    void merge(vector<int>& A, int start, int mid, int end) {
        int n1 = (mid - start + 1);
        int n2 = (end - mid);
        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++) L[i] = A[start + i];
        for (int j = 0; j < n2; j++) R[j] = A[mid + 1 + j];

        int i = 0, j = 0;
        for (int k = start; k <= end; k++) {
            if (j >= n2 || (i < n1 && L[i] <= R[j])) A[k] = L[i++];
            else A[k] = R[j++];
        }
    }

    int mergesort_and_count(vector<int>& A, int start, int end) {
        if (start >= end) return 0;

        int mid = (start + end) / 2;
        int count = mergesort_and_count(A, start, mid) + mergesort_and_count(A, mid + 1, end);
        int j = mid + 1;
        for (int i = start; i <= mid; i++) {
            while (j <= end && A[i] > A[j] * 2LL)
                j++;
            count += j - (mid + 1);
        }
        merge(A, start, mid, end);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergesort_and_count(nums, 0, nums.size() - 1);
    }
};


// From: https://leetcode.com/problems/reverse-pairs/editorial/
// Time complexity: O(nlogn)
// Space complexity: O(n). Additional space for BITS array 
class Solution {
private:
    void update(vector<int>& BIT, int index, int val) {
        while (index > 0) {
            BIT[index] += val;
            index -= index & (-index);
        }
    }

    int query(vector<int>& BIT, int index) {
        int sum = 0;
        while (index < BIT.size()) {
            sum += BIT[index];
            index += index & (-index);
        }
        return sum;
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> copy(nums);

        sort(copy.begin(), copy.end());

        vector<int> BITS(n + 1, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += query(BITS, lower_bound(copy.begin(), copy.end(), 2LL * nums[i] + 1) - copy.begin() + 1);
            update(BITS, lower_bound(copy.begin(), copy.end(), nums[i]) - copy.begin() + 1, 1);
        }
        return count;
    }
};


/**
493. Reverse Pairs
Hard

Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

    0 <= i < j < nums.length and
    nums[i] > 2 * nums[j].

 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 */
