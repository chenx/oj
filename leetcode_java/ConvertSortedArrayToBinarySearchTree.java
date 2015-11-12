/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        return convert(nums, 0, nums.length - 1);
    }
    
    private TreeNode convert(int[] nums, int L, int R) {
        if (L > R) return null;
        if (L == R) return new TreeNode(nums[L]);
        
        int M = L + (R - L)/2;
        TreeNode root = new TreeNode(nums[M]);
        root.left = convert(nums, L, M - 1);
        root.right = convert(nums, M + 1, R);
        return root;
    }
}

/**
Convert Sorted Array to Binary Search Tree
Difficulty: Medium

Given an array where elements are sorted in ascending order, 
convert it to a height balanced BST.
 */
