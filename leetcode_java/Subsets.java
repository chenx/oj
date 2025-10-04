class Solution2 {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        
        ans.add(new ArrayList<Integer>()); // empty list
        
        for (int i = 0; i < nums.length; ++ i) {
            for (int j = 0, len = ans.size(); j < len; ++ j) {
                List<Integer> copy = new ArrayList<>(ans.get(j));
                copy.add(nums[i]);
                ans.add(copy);
            }
        }
        return ans;
    }
}

public class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        int n = nums.length, len = (1 << n);
        Arrays.sort(nums);
        
        for (int i = 0; i < len; ++ i) {
            List<Integer> v = new ArrayList<Integer>();
            for (int j = 0; j < n; ++ j) {
                if ( (i & (1 << j)) != 0) {
                    v.add(nums[j]);
                }
            }
            ans.add(v);
        }
        
        return ans;
    }
}

/**
Subsets
Difficulty: Medium

Given a set of distinct integers, nums, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
 */
