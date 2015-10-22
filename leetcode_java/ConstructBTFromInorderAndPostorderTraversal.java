// This works.
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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return build(inorder, postorder, postorder.length - 1, 0, postorder.length - 1);
    }
    
    TreeNode build(int[] inorder, int[] postorder, int p, int L, int R) {
        if (L > R) return null;
        TreeNode n = new TreeNode(postorder[p]);
        int M = getMid(inorder, postorder[p], L, R);
        n.left = build(inorder, postorder, p-(R-M)-1, L, M-1);
        n.right = build(inorder, postorder, p-1, M+1, R);
        return n;
    }
    
    int getMid(int[] inorder, int val, int L, int R) {
        for (int i = L; i <= R; ++ i) {
            if (inorder[i] == val) return i;
        }
        return -1;        
    }
}

/**
Construct Binary Tree from Inorder and Postorder Traversal
Total Accepted: 42001 Total Submissions: 153397 Difficulty: Medium

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 
 */
