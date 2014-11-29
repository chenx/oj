// 
// This works.
// Note the first step of finding rotation point can be improved from O(n) to O(log N).
//
class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        // first find rotation point.
        int i = 1, n = nums.size();
        if (n == 1) return;
        
        for (; i < n; ++ i) {
            if (nums[i] < nums[i-1]) {
                break; // i-1 is rotation position.
            }
        }
        
        if (i == n) { return; } // no rotation.

        rev(nums, 0, i - 1);
        rev(nums, i, n - 1);
        rev(nums, 0, n - 1);
    }
    
    void rev(vector<int> &num, int begin, int end) {
        while (begin < end) {
            swap(num[begin], num[end]);
            ++ begin, -- end;
        }
    }
};

/**
Recover Rotated Sorted Array 

Given a rotated sorted array, recover it to sorted array in-place.

E.g.,
[4, 5, 1, 2, 3] -> [1, 2, 3, 4, 5]

Challenge:
In-place, O(1) extra space and O(n) time.

Note:
What is rotated array:
    - For example, the orginal array is [1,2,3,4], The rotated array of it can be [1,2,3,4], [2,3,4,1], [3,4,1,2], [4,1,2,3]
 */
