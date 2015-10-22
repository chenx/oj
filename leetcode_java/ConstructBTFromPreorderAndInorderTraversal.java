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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return build(preorder, inorder, 0, 0, preorder.length - 1);
    }
    
    TreeNode build(int[] preorder, int[] inorder, int p, int L, int R) {
        if (L > R) return null;
        TreeNode n = new TreeNode(preorder[p]);
        int M = getMid(inorder, preorder[p], L, R);
        n.left = build(preorder, inorder, p+1, L, M-1);
        n.right = build(preorder, inorder, p+(M-L)+1, M+1, R);
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
Construct Binary Tree from Preorder and Inorder Traversal
Total Accepted: 47037 Total Submissions: 175778 Difficulty: Medium

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 
*/
