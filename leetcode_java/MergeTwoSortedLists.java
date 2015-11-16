/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        
        ListNode h = null, t = null;
        
        while (l1 != null && l2 != null) {
            ListNode tmp = (l1.val <= l2.val) ? l1 : l2;
            if (h == null) { h = t = tmp; }
            else { t.next = tmp; t = tmp; }

            if (l1 == tmp) l1 = l1.next;
            else l2 = l2.next;
        }
        
        t.next = (l1 != null) ? l1 : l2;
        
        return h;
    }
}

/**
Merge Two Sorted Lists
Difficulty: Easy

Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes 
of the first two lists.
 */
