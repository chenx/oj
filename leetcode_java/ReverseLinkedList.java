/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
// Iterative version.
public class Solution2 {
    public ListNode reverseList(ListNode head) {
        ListNode h = null, tmp;
        while (head != null) {
            tmp = head;
            head = head.next;
            tmp.next = h;
            h = tmp;
        }
        return h;
    }
}

// recursive version.
public class Solution {
    public ListNode reverseList(ListNode head) {
        tail = null;
        return rev(head);
    }
    
    private ListNode rev(ListNode h) {
        if (h == null || h.next == null) {
            tail = h;
            return h;
        }
        
        ListNode tmp = h;
        h = rev(h.next);
        tail.next = tmp;
        tail = tmp;
        tail.next = null;
        return h;
    }
    
    private ListNode tail;
}

/**
Reverse Linked List

Reverse a singly linked list.

click to show more hints.
Hint:

A linked list can be reversed either iteratively or recursively. Could you implement both?
 */
