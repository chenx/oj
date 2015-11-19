/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null) return head;
        
        ListNode dummy = new ListNode(0);
        
        while (head != null) {
            ListNode tmp = head;
            head = head.next;
            ListNode prev = dummy;
            while (prev.next != null && prev.next.val < tmp.val) {
                prev = prev.next;
            }
            // now insert after prev.
            tmp.next = prev.next;
            prev.next = tmp;
        }
        
        return dummy.next;
    }
}


/**
Insertion Sort List
Difficulty: Medium

Sort a linked list using insertion sort.
 */
