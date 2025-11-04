// From: https://leetcode.com/problems/finding-pairs-with-a-certain-sum/editorial/
// Let n and m be the lengths of the arrays nums1​ and nums2​, respectively, 
// and let q1​ and q2​ be the number of times the operations add(index, val) and getPairs(tot) are called.
// Time complexity: O(n+m+q1​+q2​⋅n)
// Space complexity: O(n+m)
class FindSumPairs {
    int[] arr1;
    int[] arr2;
    HashMap<Integer, Integer> count; // num in nums2, count

    public FindSumPairs(int[] nums1, int[] nums2) {
        arr1 = nums1;
        arr2 = nums2;
        count = new HashMap<Integer, Integer>();
        for (int num : arr2) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }
    }
    
    public void add(int index, int val) {
        count.put(arr2[index], count.get(arr2[index]) - 1);
        arr2[index] += val;
        count.put(arr2[index], count.getOrDefault(arr2[index], 0) + 1);
    }
    
    public int count(int tot) {
        int ct = 0;
        for (int num : arr1) {
            int val = tot - num;
            ct += count.getOrDefault(val, 0);
        }
        return ct;
    }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs obj = new FindSumPairs(nums1, nums2);
 * obj.add(index,val);
 * int param_2 = obj.count(tot);
 */


/**
1865. Finding Pairs With a Certain Sum
Medium

You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:

    Add a positive integer to an element of a given index in the array nums2.
    Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).

Implement the FindSumPairs class:

    FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
    void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
    int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.

 */
