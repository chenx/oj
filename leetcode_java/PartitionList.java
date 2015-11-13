/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode h1 = null, t1 = null, h2 = null, t2 = null;
        
        while (head != null) {
            ListNode tmp = head.next;
            if (head.val < x) {
                if (h1 == null) h1 = t1 = head;
                else {
                    t1.next = head;
                    t1 = head;
                }
                t1.next = null;
            }
            else {
                if (h2 == null) h2 = t2 = head;
                else {
                    t2.next = head;
                    t2 = head;
                }
                t2.next = null;
            }
            head = tmp;
        }
        
        if (h1 == null) return h2;
        else {
            t1.next = h2;
            return h1;
        }
    }
}


/**
Partition List
Difficulty: Medium

Given a linked list and a value x, partition it such that 
all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5. 
 */
