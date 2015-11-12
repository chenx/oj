/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        if (head == null) return null;
        
        // duplicate list.
        RandomListNode h;
        for (h = head; h != null; h = h.next.next) {
            RandomListNode h2 = new RandomListNode(h.label);
            h2.next = h.next;
            h.next = h2;
        }
        
        // copy random pointer.
        for (h = head; h != null; h = h.next.next) {
            h.next.random = (h.random == null ? null : h.random.next);
        }
        
        // split. be careful of this loop.
        h = head.next;
        RandomListNode tail = head, t = h;
        
        while (tail != null) {
            tail.next = t.next;
            tail = tail.next;
            if (tail == null) break;

            t.next = tail.next;
            t = t.next;
        }
        
        return h;
    }
}

/**
Copy List with Random Pointer
Difficulty: Hard

A linked list is given such that each node contains an additional 
random pointer which could point to any node in the list or null.

Return a deep copy of the list. 
 */
