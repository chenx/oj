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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        if (root == null) return list;
        
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        int level_ct = 1;
        int level = 0;
        
        while (! q.isEmpty()) {
            ++ level;
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
            
            if ((level & 1) == 0) Collections.reverse(levelList);
            list.add(levelList);
            level_ct = ct;
        }
        
        return list;        
    }
}


/**
Binary Tree Zigzag Level Order Traversal
Difficulty: Medium

Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]
 */
