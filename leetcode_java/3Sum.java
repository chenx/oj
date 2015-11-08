// This works.
// from: https://leetcode.com/discuss/67914/easiest-java-solution
public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if(nums == null || nums.length < 2) return result;
        Arrays.sort(nums);
    
        int len = nums.length;
        for(int i = 0; i < len; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;           // Skip same results
            int target = 0 - nums[i];
            int j = i + 1, k = len - 1;
            while(j < k) {
                if(nums[j] + nums[k] == target) {
                    result.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    while(j < k && nums[j] == nums[j + 1]) j++;     // Skip same results
                    while(j < k && nums[k] == nums[k - 1]) k--;     // Skip same results
                    j ++; k--;
                } else if(nums[j] + nums[k] < target) {
                    j ++;
                } else {
                    k --;
                }
            }
        }
        return result;
    }
}


// This works too.
public class Solution2 {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        int len = nums.length;
        
        for (int R = 2; R < len; ++ R) {
            if (R < len - 1 && nums[R] == nums[R+1]) continue;
            for (int L = 0, M = R - 1; L < M; ) {
                int sum = nums[L] + nums[R] + nums[M];
                if (sum == 0) {
                    ans.add(Arrays.asList(nums[L], nums[M], nums[R]));
                    ++ L; -- M;
                    while (L < M && nums[L] == nums[L-1]) ++ L;
                    while (L < M && nums[M] == nums[M+1]) -- M;
                }
                else if (sum < 0) {
                    ++ L;
                }
                else {
                    -- M;
                }
            }
        }
        
        return ans;
    }
}

/**
3Sum
Difficulty: Medium

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

 */
