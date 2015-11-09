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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<Integer>();
        if (root == null) return ans;
        
        Queue<TreeNode> row = new LinkedList<TreeNode>();
        
        row.add(root);
        while (! row.isEmpty()) {
            int len = row.size();
            for (int i = 0; i < len; ++ i) {
                TreeNode n = row.peek();
                row.remove();
                if (n.left != null) row.add(n.left);
                if (n.right != null) row.add(n.right);
                
                if (i == len - 1) ans.add(n.val);
            }
        }
        
        return ans;        
    }
}

/**
Binary Tree Right Side View
Difficulty: Medium

Given a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

You should return [1, 3, 4]. 
 */
