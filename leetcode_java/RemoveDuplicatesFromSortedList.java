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
        
        ListNode h = head;
        while (h != null && h.next != null) {
            if (h.val == h.next.val) {
                h.next = h.next.next;
            }
            else {
                h = h.next;
            }
        }
        
        return head;
    }
}

/**
Remove Duplicates from Sorted List
Difficulty: Easy

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. 
 */
