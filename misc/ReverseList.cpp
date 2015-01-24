/**
 * Reverse a linked list.
 */

// This works. Most simple solution.
// 3 pointers, including input list head.
class Solution { 
public: 
    ListNode * reverseList(ListNode * n) { 
        ListNode * h = NULL;
        while (n != NULL) {
            ListNode * tmp = n->next;
            n->next = h;
            h = n;
            n = tmp;
        }
        
        return h;
    } 
};
