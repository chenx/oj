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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<Integer>();
        if (root == null) return list;
        
        Stack<TreeNode> s = new Stack<TreeNode>();
        s.push(root);
        
        while (! s.empty()) {
            TreeNode n = s.peek();
            s.pop();
            list.add(n.val);
            
            if (n.left != null) s.push(n.left);
            if (n.right != null) s.push(n.right);
        }
        
        Collections.reverse(list);
        
        return list;
    }
}

/**
Binary Tree Postorder Traversal
Difficulty: Hard

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
 */
