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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        if (root == null) return list;
        
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        int level_ct = 1;
        
        while (! q.isEmpty()) {
            int ct = 0;
            List<Integer> levelList = new ArrayList<Integer>();
            while (level_ct > 0) {
                -- level_ct;
                TreeNode n = q.peek();
                q.remove();
                levelList.add(n.val);
                
                if (n.left != null) {
                    q.add(n.left);
                    ++ ct;
                }
                if (n.right != null) {
                    q.add(n.right);
                    ++ ct;
                }
            }
            
            list.add(levelList);
            level_ct = ct;
        }
        
        Collections.reverse(list); // Only difference from BinaryTreeLevelOrderTraversal.
        return list;
    }
}

/**
Binary Tree Level Order Traversal II
Difficulty: Easy

Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]
 */
