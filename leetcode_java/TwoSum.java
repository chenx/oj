class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> m = new HashMap<>();
        int[] v = new int[2];
        for (int i = 0; i < nums.length; i ++) {
            if (m.containsKey(nums[i])) 
                v = new int[] {m.get(nums[i]), i};
            else 
                m.put(target - nums[i], i);
        }
        return v;
    }
}

public class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ans = new int[2];
        ans[0] = ans[1] = -1;

        int len = nums.length;
        if (len == 0) return ans;
        
        HashMap<Integer, Integer> h = new HashMap<Integer, Integer>();

        for (int i = 0; i < len; ++ i) {
            if (h.containsKey(nums[i])) {
                ans[0] = h.get(nums[i]);
                ans[1] = i+1;
                break;
            }
            else {
                h.put(target - nums[i], i + 1);
            }
        }
        
        return ans;
    }
}


/**
Two Sum
Difficulty: Medium

Given an array of integers, find two numbers such that they add up to 
a specific target number.

The function twoSum should return indices of the two numbers such that 
they add up to the target, where index1 must be less than index2. 
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 
 */
