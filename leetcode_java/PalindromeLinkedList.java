/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    // O(1) space, O(n) time.
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) return true;
        
        ListNode slow = head, fast = head.next, prev = null;

        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        
        if (fast == null) { // odd number of nodes. slow is at center node.
            prev.next = null;
            head = reverseList(head);
            return isEqualList(head, slow.next);
        }
        else { // even number of nodes. slow is at first of center 2 nodes.
            if (prev == null) {
                return slow.val == fast.val;
            }
            else {
                ListNode tmp = slow.next;
                slow.next = null;
                head = reverseList(head);
                return isEqualList(head, tmp);
            }
        }
    }
    
    private boolean isEqualList(ListNode a, ListNode b) {
        while (a != null && b != null) {
            if (a.val != b.val) return false;
            a = a.next;
            b = b.next;
        }
        
        return a == null && b == null;
    }
    
    private ListNode reverseList(ListNode head) {
        ListNode h = null, tmp;
        
        while (head != null) {
            tmp = head;
            head = head.next;
            tmp.next = h;
            h = tmp;
        }
        
        return h;        
    }
}

/**
Palindrome Linked List
Difficulty: Easy

Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
 */
 
