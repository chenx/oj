class Solution {
    int maxval = 0;

    public int longestConsecutive(TreeNode root) {
        longestPath(root);
        return maxval;
    }
    
    public int[] longestPath(TreeNode root) {
        if (root == null) {
            return new int[] {0,0};
        }
        
        int inr = 0, dcr = 0;
        if (root.left != null) {
            int[] left = longestPath(root.left);
            if (root.val == root.left.val + 1) {
                dcr = left[1] + 1;
            } else if (root.val == root.left.val - 1) {
                inr = left[0] + 1;
            }
        }
        
        if (root.right != null) {
            int[] right = longestPath(root.right);
            if (root.val == root.right.val + 1) {
                dcr = Math.max(dcr, right[1] + 1);
            } else if (root.val == root.right.val - 1) {
                inr = Math.max(inr, right[0] + 1);
            }
        }
        
        maxval = Math.max(maxval, dcr + inr + 1);  // + root
        return new int[] {inr, dcr};
    }
}

/**
549. Binary Tree Longest Consecutive Sequence II

Find the length of Longest Consecutive Path in Binary Tree. The path can be either increasing or decreasing 
i.e. [1,2,3,4] and [4,3,2,1] are both considered valid. The path can be child-parent-child or parent-child.
 */
