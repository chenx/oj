/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null) return head;
        
        int len = 0;
        ListNode h = head, t = null;
        while (h != null) {
            t = h;
            h = h.next;
            ++ len;
        }
        
        k = k % len;
        if (k == 0) return head;
        
        k = len - 1 - k;
        for (h = head; k > 0; -- k) h = h.next;
        
        t.next = head;
        head = h.next;
        h.next = null;
        
        return head;
    }
}

/**
Rotate List
Difficulty: Medium

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
 */
