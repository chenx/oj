/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
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
    public TreeNode sortedListToBST(ListNode head) {
        if (head == null) return null;
        if (head.next == null) return new TreeNode(head.val);
        
        ListNode prev = null, slow = head, fast = head.next;
        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        
        TreeNode root = new TreeNode(slow.val);
        if (prev == null) { // remember to have this branch.
            root.left = null;
            root.right = sortedListToBST(slow.next);
        }
        else {
            prev.next = null;
            root.left = sortedListToBST(head);
            root.right = sortedListToBST(slow.next);
        } 

        return root;
    }
}

/**
Convert Sorted List to Binary Search Tree
Difficulty: Medium

Given a singly linked list where elements are sorted in ascending order, 
convert it to a height balanced BST.
 */
