// This works. 11/15/2015
// The key is to find head and tail of each segment to reverse, and keep prev and next.

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    private ListNode newHead, newTail;
    
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || head.next == null || k == 1) return head;
        
        ListNode h = head, prev = null, t, next;
        int ct;
        
        while (h != null) {
            for (t = h, ct = k - 1; ct > 0 && t != null; -- ct, t = t.next) {}
            if (t == null) break; // less than k nodes. be carefull of this!
            
            next = t.next; // prev, next are nodes before/after the segment to reverse.

            rev(h, t);
            h = newHead; 
            t = newTail;
            
            if (prev == null) head = h;
            else prev.next = h;

            prev = t; // don't forget this!
            h = t.next = next;
        }
        
        return head;
    }
    
    // reverse list h to t.
    void rev(ListNode h, ListNode t) {
        newTail = h;
        t.next = null;
        t = null;
        
        while (h != null) {
            ListNode tmp = h.next;
            h.next = t;
            t = h;
            h = tmp;
        }
        
        newHead = t;
    }
}


/*
Reverse Nodes in k-Group
Difficulty: Hard

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5 
 */
