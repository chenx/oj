// For a valid triangle, sum of the smaller 2 sides > the largest side.
// From https://leetcode.com/problems/largest-perimeter-triangle/
// Best.
// O(nlogn)
class Solution2 {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        for (int i = A.size() - 3; i >= 0; --i) {
            if (A[i] + A[i + 1] > A[i + 2]) {
                return A[i] + A[i + 1] + A[i + 2];
            }
        }
        return 0;
    }
};

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        sort(nums.begin(), nums.end());

        int maxVal = 0;
        for (int i = 0; i < n; ++ i) {
            for (int j = i + 1; j < n; ++ j) {
                for (int k = j + 1; k < n; ++ k) {
                    if (nums[i] + nums[j] > nums[k]) {
                        // can form a triangle.
                        maxVal = max(maxVal, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }
        return maxVal;
    }
};

/**
976. Largest Perimeter Triangle
Easy

Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, 
formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.
 */
