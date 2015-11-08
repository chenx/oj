/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) return false;
        
        ListNode fast = head.next, slow = head;
        
        while (fast != null && fast.next != null) {
            if (fast == slow) return true; // it works too if put this at the end of cycle.
            slow = slow.next;
            fast = fast.next.next;
        }
        
        return false;
    }
}

/**
Linked List Cycle
Difficulty: Medium

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space? 
 */
