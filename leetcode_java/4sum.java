public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        int len = nums.length;
        
        for (int L = 0; L < len - 3; ++ L) {
            if (L > 0 && nums[L] == nums[L-1]) continue;
            
            List<List<Integer>> sum3 = threeSum(nums, L+1, target - nums[L]);
            for (int i = 0; i < sum3.size(); ++ i) {
                ans.add(Arrays.asList(nums[L], 
                    sum3.get(i).get(0), 
                    sum3.get(i).get(1), 
                    sum3.get(i).get(2)));
            }
        }
        return ans;
    }
    
    private List<List<Integer>> threeSum(int[] nums, int left, int target) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        int len = nums.length;
        
        for (int R = 2; R < len; ++ R) {
            if (R < len - 1 && nums[R] == nums[R+1]) continue;
            for (int L = left, M = R - 1; L < M; ) {
                int sum = nums[L] + nums[R] + nums[M];
                if (sum == target) {
                    ans.add(Arrays.asList(nums[L], nums[M], nums[R]));
                    ++ L; -- M;
                    while (L < M && nums[L] == nums[L-1]) ++ L;
                    while (L < M && nums[M] == nums[M+1]) -- M;
                }
                else if (sum < target) {
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
4Sum
Difficulty: Medium

Given an array S of n integers, are there elements a, b, c, 
and d in S such that a + b + c + d = target? Find all unique 
quadruplets in the array which gives the sum of target.

Note:

    Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
    The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
 */
