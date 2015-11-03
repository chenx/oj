/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        conn(root, null);
    }
    
    private void conn(TreeLinkNode root, TreeLinkNode next) {
        if (null == root) return;
        root.next = next;
        
        TreeLinkNode n = getNext(next);
        conn(root.right, n);
        conn(root.left, root.right != null ? root.right : n);
    }
    
    private TreeLinkNode getNext(TreeLinkNode next) {
        if (null == next) return null;
        if (next.left != null) return next.left;
        if (next.right != null) return next.right;
        return getNext(next.next);
    }
}

/**
Populating Next Right Pointers in Each Node II
Difficulty: Hard

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

    You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

 */
