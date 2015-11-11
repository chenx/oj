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
    public void flatten(TreeNode root) {
        if (root == null) return;
        
        TreeNode head = null, tail = null;
        Stack<TreeNode> s = new Stack<TreeNode>();
        s.push(root);
        
        while (! s.empty()) {
            TreeNode n = s.peek();
            s.pop();
            
            if (n.right != null) s.push(n.right);
            if (n.left != null) s.push(n.left);

            if (head == null) {
                head = tail = n;
            } else {
                tail.right = n;
                tail = n;
            }
            n.left = n.right = null;
        } 
    }
}

/**
Flatten Binary Tree to Linked List
Difficulty: Medium

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

click to show hints.
Hints:

If you notice carefully in the flattened tree, each node's right child 
points to the next node of a pre-order traversal.

 */
