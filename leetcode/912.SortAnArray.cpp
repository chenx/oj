// Merge sort.
class Solution {
    vector<int> copy;
public:
    vector<int> sortArray(vector<int>& nums) {
        copy = vector<int>(nums.size());
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);

        int i = left, j = mid+1, k = left;
        for (; i <= mid && j <= right; ) {
            if (nums[i] < nums[j]) copy[k ++] = nums[i ++];
            else copy[k ++] = nums[j ++];
        }
        while (i <= mid) copy[k ++] = nums[i ++];
        while (j <= right) copy[k ++] = nums[j ++];
        
        for (int i = left; i <= right; ++ i) {
            nums[i] = copy[i];
        }
    }
};

// Quick sort.
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;

        swap(nums[left], nums[left + (right - left)/2]);
        int pivot = nums[left], L = left + 1, R = right;

        while (L <= R) {
            while (L <= R && nums[L] <= pivot) ++ L;
            while (L <= R && nums[R] >= pivot) -- R;
            if (L < R) {
                swap(nums[L ++], nums[R --]);
            } else {
                ++ L;
            }
        }

        swap(nums[left], nums[R]);
        quickSort(nums, left, R - 1);   // !
        quickSort(nums, R + 1, right);  // !
    }
};


/**
912. Sort an Array
Medium

Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
 */
