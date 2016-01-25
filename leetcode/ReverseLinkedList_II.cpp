//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 12/24/2012
//

// This works too. 1/24/2016.
class Solution3 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        
        ListNode * hm = NULL, * hn = NULL;
        if (m == 1) {
            for (hn = head; n > 1; -- n) hn = hn->next;
            ListNode *tmp = hn->next;
            hn->next = NULL;
            
            ListNode *t = NULL;
            head = rev(head, t);
            t->next = tmp;
            return head;
        }
        else {
            // hm->next is m-th node, hn is n-th node.
            for (hm = head; m > 2; -- m) hm = hm->next;
            for (hn = head; n > 1; -- n) hn = hn->next;
            
            ListNode *tmp = hn->next;
            hn->next = NULL;
            
            ListNode *t = NULL;
            hm->next = rev(hm->next, t);
            t->next = tmp;
            
            return head;
        }
    }
    
    ListNode* rev(ListNode *h, ListNode *&t) {
        if (h == NULL || h->next == NULL) {
            t = h;
            return h;
        }
        
        ListNode * tmp = h;
        h = rev(h->next, t);
        t->next = tmp;
        t = tmp;
        t->next = NULL;
        return h;
    }  
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 
 * Get the m-th node. keep head of it, add every other node
 * to its head, until the n-th node.
 * 
 * Be careful of:
 * 1) m = n, no need to reverse.
 * 2) m = 1, first node is head.
 * 3) maintain the next pointer of the m-th node at the end.
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL || m == n) return head;
        
        ListNode *n1, *h, *t, *h_bak, *tmp;
        int ct = 1;
        
        if (m == 1) { // head is the m-th node.
            n1 = NULL;
            h = head;
        } else {
            n1 = head;
            while(ct < m - 1) {
                n1 = n1->next;
                ct ++;
            }
            h = n1->next; // h is the m-th node.
            ct ++;
        }
        h_bak = h;
        
        t = h->next; // t is not null, since n < length of list.
        while (ct < n) {
            tmp = t->next;
            t->next = h;
            h = t;
            t = tmp;
            ct ++;
        }
        h_bak->next = tmp; // maintain next ptr of the m-th node.
                
        if (m == 1) head = h;
        else n1->next = h;
        
        return head;
    }
};

// This works too. 11/15/2015
class Solution2 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || head->next == NULL || m >= n) return head;
        
        ListNode *h, *t, *prev, *next;
        n -= m; // will count second node starting from first node.
        
        for (h = head, prev = NULL; m > 1 && h != NULL; -- m, prev = h, h = h->next) {}
        if (h == NULL) return head;
        
        for (t = h->next; n > 1 && t != NULL; -- n, t = t->next) {}
        if (t == NULL) return head;
        
        next = t->next;
        
        rev(h, t);

        if (prev == NULL) head = h;
        else prev->next = h;
        
        t->next = next;

        return head;
    }
    
    void rev(ListNode *&h, ListNode *&t) {
        ListNode *newTail = h;
        t->next = NULL;
        t = NULL;
        
        while (h != NULL) {
            ListNode *tmp = h->next;
            h->next = t;
            t = h;
            h = tmp;
        }
        
        h = t;
        t = newTail;
    }
};

/*
Reverse Linked List II
Difficulty: Medium

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. 
 */
