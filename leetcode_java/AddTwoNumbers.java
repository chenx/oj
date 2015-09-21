/**
 * Add Two Numbers.
 *
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */
 
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    private int carry;
    
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        carry = 0;
        
        ListNode head = null, tail = null;
        for (; l1 != null && l2 != null; l1 = l1.next, l2 = l2.next) {
            if (head == null) {
                head = tail = getNode(l1.val + l2.val);
            }
            else {
                tail.next = getNode(l1.val + l2.val + carry);
                tail = tail.next;
            }
        }
        
        for (; l1 != null; l1 = l1.next) {
            tail.next = getNode(l1.val + carry);
            tail = tail.next;
        }
        
        for (; l2 != null; l2 = l2.next) {
            tail.next = getNode(l2.val + carry);
            tail = tail.next;
        }
        
        if (carry > 0) {
            tail.next = getNode(carry);
            tail = tail.next;
        }
        
        return head;
    }
    
    private ListNode getNode(int sum) {
        if (sum > 9) {
            sum -= 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        
        return new ListNode(sum);
    }
}
