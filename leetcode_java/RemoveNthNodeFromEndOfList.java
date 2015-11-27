// This works too. Is most clear.
// Just be careful of case when n == list.length, i.e., remove first node.

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode first = head;
        
        for (; n > 0; -- n) first = first.next;
        if (first == null) { // remove head node.
            head = head.next;
        }
        else {
            ListNode last = head;
            while (first.next != null) {
                first = first.next;
                last  = last.next;
            }
            
            last.next = last.next.next;
        }
        
        return head;        
    }
}

/**
Remove Nth Node From End of List
Difficulty: Easy

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass. 
 */
