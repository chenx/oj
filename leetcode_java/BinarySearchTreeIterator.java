/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class BSTIterator {
    private Stack<TreeNode> s;
    private TreeNode n;
    private TreeNode next;

    public BSTIterator(TreeNode root) {
        if (root == null) {
            next = null;
        }
        else {
            s = new Stack<TreeNode>();
            n = root;
            next();
        }
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return next != null;
    }

    /** @return the next smallest number */
    public int next() {
        TreeNode cur = next;
        
        while (n != null) {
            s.push(n);
            n = n.left;
        }
        
        if (s.empty()) {
            next = null;
        }
        else {
            n = s.peek();
            s.pop();
            next = n;
            
            n = n.right;
        }
        
        return cur != null ? cur.val : -1;
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = new BSTIterator(root);
 * while (i.hasNext()) v[f()] = i.next();
 */
 
 
 /**
Binary Search Tree Iterator
Difficulty: Medium

Implement an iterator over a binary search tree (BST). 
Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and 
uses O(h) memory, where h is the height of the tree. 
  */
