/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        if (! head || ! head->next) return;
        
        ListNode * t = head, * t2 = head->next, *h2 = NULL;
        
        /*
        // This splits odd and even node of input list.
        while(t2 && t2->next) {
            t->next = t2->next;
            t2->next = t2->next->next;
            t = t->next;
            t2 = t2->next;
        }
        
        if (! t2) { }
        else if (! t2->next) {
            t->next = NULL;
        }
        */
        // 1) split at the middle of input list.
        while (t2 && t2->next) {
            t = t->next;
            t2 = t2->next->next;
        }
        h2 = t->next;
        t->next = NULL;
        
        // 2) reverse h2.
        h2 = rev(h2);
        
        // 3) combine. note: h2.len == h.len, or h2.len == h.len - 1
        ListNode * tmp;
        ListNode * h = head;
        while(h2) {
            tmp = h2->next;
            h2->next = h->next;
            h->next = h2;
            h = h2->next;
            h2 = tmp;
        }
    }
    
    ListNode * rev(ListNode * n) {
        if (! n) return NULL;
        
        ListNode * h = n, * tmp = n->next;
        h->next = NULL;
        
        while (tmp) {
            n = tmp;
            tmp = tmp->next;
            n->next = h;
            h = n;
        }
        
        return h;
    }
};

/*

Reorder List
Total Accepted: 862 Total Submissions: 5039

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 

*/