class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;

        // Based on patience sort:
        // if nums[i] > all current elem in INC seq, put at the end;
        // else, insert in the middle, replace the next larger value.
        // 1, 3, 6, 2, 5 : 1, 3, 6 -> 1, 2, 6 -> 1, 2, 5

        int result[] = new int[n];
        int len = 0;
        for (int i = 0; i < n; ++ i) {
            if (len == 0 || nums[i] > result[len - 1]) {
                result[len ++] = nums[i];
            } else {
                int L = 0, R = len - 1;
                while (L <= R) {
                    int M = L + (R-L)/2;
                    if (nums[i] > result[M]) {
                        L = M + 1;
                    } else {
                        R = M - 1;
                    }
                }
                result[L] = nums[i];
            }
        }
        return len;
    }
}

// O(n log(n))
public class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        if (n <= 1) return n;
    
        int[] B = new int[n]; // LIS sequence
        int len = 1;
        B[0] = nums[0];
    
        for (int i = 1; i < n; ++ i) {
            int L = 0, R = len - 1;
            while (L <= R) {
                int M = L + (R - L) / 2;
                if (B[M] < nums[i]) L = M + 1;
                else R = M - 1;
            }
    
            B[L] = nums[i];
            if (L == len) ++ len;
        }
    
        return len;
    }
}

/**
Longest Increasing Subsequence
Difficulty: Medium

Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. 
Note that there may be more than one LIS combination, it is only necessary for you 
to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity? 
 */
 
