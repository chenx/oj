/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) return;
        
        // split
        ListNode slow = head, fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode h2 = slow.next;
        slow.next = null;
        
        // reverse 2nd list.
        h2 = reverse(h2);
        
        // now combine.
        ListNode h = head;
        while (h2 != null) {
            ListNode tmp = h2.next;
            h2.next = h.next;
            h.next = h2;
            h = h2.next;
            h2 = tmp;
        }

        /* // this also works.
        ListNode tail = head;
        ListNode h1 = head.next;
        while (h1 != null && h2 != null) {
            tail.next = h2;
            tail = h2;
            h2 = h2.next;
            tail.next = h1;
            tail = h1;
            h1 = h1.next;
        }
        tail.next = h1 != null ? h1 : h2;
        */
    }
    
    private ListNode reverse(ListNode h) {
        ListNode tmp = null;
        while (h != null) {
            ListNode t = h.next;
            h.next = tmp;
            tmp = h;
            h = t;
        }
        return tmp;
    }
}

/**
Reorder List
Difficulty: Medium

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 
 */
