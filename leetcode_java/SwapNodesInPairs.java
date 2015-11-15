/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) return head;
        
        ListNode h = head, prev = null;
        
        while (h != null && h.next != null) {
            ListNode tmp = h.next;
            h.next = tmp.next;
            tmp.next = h;
            
            if (prev == null) head = tmp;
            else prev.next = tmp;
            
            prev = h;
            h = prev.next;
        }
        
        return head;
    }
}

/**
Swap Nodes in Pairs
Difficulty: Medium

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. 
You may not modify the values in the list, only nodes itself can be changed. 
 */
