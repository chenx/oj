/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeElements(ListNode head, int val) {
        while (head != null && head.val == val) { // remove head.
            head = head.next;
        }
        
        if (head == null) return null;
        
        ListNode n = head;
        while (n.next != null) { 
            if (n.next.val == val) { // remove head->next
                n.next = n.next.next;
            }
            else {
                n = n.next;
            }
        }
        
        return head;
    }
}

// This works too.
public class Solution2 {
    public ListNode removeElements(ListNode head, int val) {
        if (head == null) return null;
        
        ListNode h = head, prev = null;
        
        while (h != null) {
            if (h.val == val) {
                if (prev == null) h = head = h.next;
                else h = prev.next = h.next;
            }
            else {
                prev = h;
                h = h.next;
            }
        }
        
        return head;
    }
}

/**
Remove Linked List Elements
Difficulty: Easy

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5 
 */
