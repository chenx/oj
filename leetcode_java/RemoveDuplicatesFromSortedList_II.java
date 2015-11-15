/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) return head;
        
        ListNode h = head, prev = null;
        
        while (h != null && h.next != null) {
            if (h.val != h.next.val) { prev = h; h = h.next; }
            else {
                // find last node t whose value equals h's value.
                ListNode t = h.next;
                for (; t.next != null && t.next.val == h.val; t = t.next) ;
                
                // now remove nodes from h to t.
                if (prev == null) h = head = t.next;
                else h = prev.next = t.next;
            }
        }
        
        return head;
    }
}

/**
Remove Duplicates from Sorted List II
Difficulty: Medium

Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3. 
 */
