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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<Integer>();
        if (root == null) return list;
        
        Stack<TreeNode> s = new Stack<TreeNode>();
        s.push(root);
        
        while (! s.empty()) {
            TreeNode n = s.peek();
            s.pop();
            
            list.add(n.val);
            
            if (n.right != null) s.push(n.right);
            if (n.left != null) s.push(n.left);
        }
        
        return list;
    }
}

/**
Binary Tree Preorder Traversal
Difficulty: Medium

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
 */
