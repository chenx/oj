/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null || head.next == null || m >= n) return head;
        
        ListNode h, t, prev, next;
        n -= m; // will count second node starting from first node.
        
        for (h = head, prev = null; m > 1 && h != null; -- m, prev = h, h = h.next) {}
        if (h == null) return head;
        
        for (t = h.next; n > 1 && t != null; -- n, t = t.next) {}
        if (t == null) return head;
        
        next = t.next;
        
        rev(h, t);
        h = newHead;
        t = newTail;
        
        if (prev == null) head = h;
        else prev.next = h;
        
        t.next = next;

        return head;
    }
    
    private void rev(ListNode h, ListNode t) {
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
    
    private ListNode newHead, newTail;
}

/**
Reverse Linked List II
Difficulty: Medium

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. 
 */
