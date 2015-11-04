public class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> s = new HashSet<Integer>();
        for (int i = 0, len = nums.length; i < len; ++ i) {
            if (s.contains(nums[i])) return true;
            s.add(nums[i]);
        }
        return false;
    }
}

/**
Contains Duplicate
Difficulty: Easy

Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice 
in the array, and it should return false if every element is distinct. 
 */
