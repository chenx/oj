
//
// 10/24/2014
// This O(log(n)) solution works too! And is most simple.
// Modified from the result of FindMinimumInRotatedSortedArray_II.
//
class Solution4 {
public:
    int findMin(vector<int> &num) {
        int L = 0, R = num.size() - 1;
        
        while (L < R) {
            int M = L + (R - L) / 2;

            if (num[M] < num[R]) {
                R = M;
            } else {
                L = M + 1;
            }
        }
        
        return num[L];
    }
};

// Works too. Tested. Slightly modified from Solution2.
class Solution3 {
public:
    int findMin(vector<int>& nums) {
        int L = 0, R = nums.size() - 1;
        while (L < R) {
            int M = L + (R-L)/2;
            
            if (M < R && nums[M] > nums[M+1]) return nums[M+1];
            else if (L < M && nums[M-1] > nums[M]) return nums[M];
            
            if (nums[M] < nums[R]) R = M-1;
            else L = M+1;
        }
        return nums[L];
    }
};
    
// 10/16/2014
// Assumption: sorted ASC.
// Note the min is the only one less than its immediate left member.
// Every other element is larger than its immediate left member.
// This works and is O(log(n)).
// This works and is optimized from Solution2.
class Solution2 {
public:
    int findMin(vector<int> &num) {
        int L = 0, R = num.size() - 1;
        
        while (L <= R) {
            if (L == R) { return num[L]; }
            
            int M = L + (R - L) / 2;
            if (M < R && num[M] > num[M+1]) return num[M+1];
            else if (L < M && num[M-1] > num[M]) return num[M];
            
            if (num[M] < num[R]) R = M - 1;
            else L = M + 1;
        }
        
        return num[0];
    }
};



//Find min in sorted rotated array:
//http://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
// This works.
// This includes the case that there are duplicates in array.
// If there is duplicate, it's O(n) and not O(log(n)).
class Solution {
    int findMin(vector<int> &num) {
        return f(num, 0, num.size() - 1);
    }
    
    int f(vector<int> &arr, int low, int high) {
        // This condition is needed to handle the case when array is not
        // rotated at all
        if (high < low)  return arr[0];
     
        // If there is only one element left
        if (high == low) return arr[low];
     
        // Find mid
        int mid = low + (high - low)/2; /*(low + high)/2;*/
     
        // Check if element (mid+1) is minimum element. Consider
        // the cases like {1, 1, 0, 1}
        if (mid < high && arr[mid+1] < arr[mid])
           return arr[mid+1];
     
        // This case causes O(n) time.
        // if array has no duplicate, this can be removed.
        if (arr[low] == arr[mid] && arr[high] == arr[mid])
            return min(f(arr, low, mid-1), f(arr, mid+1, high));
     
        // Check if mid itself is minimum element
        if (mid > low && arr[mid] < arr[mid - 1])
           return arr[mid];
     
        // Decide whether we need to go to left half or right half
        if (arr[high] > arr[mid])
           return f(arr, low, mid-1);
        return f(arr, mid+1, high);
    }
}


/**
Find Minimum in Rotated Sorted Array
Difficulty: Medium

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
 */
