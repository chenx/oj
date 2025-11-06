// Works.
// Time: O(n), Space: O(1) because set size <= 3.
class Solution {
    public int thirdMax(int[] nums) {
        int firstMax = Integer.MIN_VALUE;
        int secondMax = Integer.MIN_VALUE;
        int thirdMax = Integer.MIN_VALUE;
        HashSet<Integer> set = new HashSet();
        
        for (int num : nums) {
            if (set.size() <= 3) set.add(num);

            // This number is already used once, thus we skip it.
            if (firstMax == num || secondMax == num || thirdMax == num) {
                continue;
            }
            
            if (firstMax <= num) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = num;
            } else if (secondMax <= num) {
                thirdMax = secondMax;
                secondMax = num;
            } else if (thirdMax <= num) {
                thirdMax = num;
            }
        }
        
        if (thirdMax == Integer.MIN_VALUE) return set.size() >= 3 ? thirdMax : firstMax;
        return thirdMax;
    }
}

// From: https://leetcode.com/problems/third-maximum-number/editorial/
// Time: O(n)
class Solution {
    public int thirdMax(int[] nums) {
        long firstMax = Long.MIN_VALUE;
        long secondMax = Long.MIN_VALUE;
        long thirdMax = Long.MIN_VALUE;
        
        for (int num : nums) {
            // This number is already used once, thus we skip it.
            if (firstMax == num || secondMax == num || thirdMax == num) {
                continue;
            }
            
            if (firstMax <= num) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = num;
            } else if (secondMax <= num) {
                thirdMax = secondMax;
                secondMax = num;
            } else if (thirdMax <= num) {
                thirdMax = num;
            }
        }
        
        // If third max was never updated, it means we don't have 3 distinct numbers.
        if (thirdMax == Long.MIN_VALUE) {
            int ans = (int) firstMax;
            return ans;
        }
        
        int ans = (int) thirdMax;
        return ans;
    }
}


/**
414. Third Maximum Number
Easy

Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.
 */
