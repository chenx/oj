//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/18/2012
// @Last modified: 12/18/2012
//

// This works too.
class Solution4 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;
        
        // find list length, normalize k.
        int n = 0; // list length
        ListNode * h = head;
        for (; h != NULL; h = h->next) ++ n;
        k = k % n;
        if (k == 0) return head;
        
        // find new tail node.
        ListNode * t = head;
        for (int i = n - k - 1; i > 0; -- i) t = t->next;
        // now t is the new tail node.
        
        h = head; // save old head node.
        head = t->next; // new head node.
        t->next = NULL;
        
        // find tail of old list, link it to old head.
        for (t = head; t->next != NULL; t = t->next) ;
        t->next = h; 
        
        return head;
    }
};
 
// This works too. And seem more clear.
class Solution3 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;
        
        int len = 0;
        ListNode *h = head, *t = NULL; // t is tail node.
        while (h != NULL) {
            t = h;
            h = h->next;
            ++ len;
        }
        
        k = k % len;
        if (k == 0) return head;
        
        k = len - 1 - k;
        for (h = head; k > 0; -- k) h = h->next; // h becomes new tail node.
        
        t->next = head;
        head = h->next;
        h->next = NULL;
        
        return head;        
    }
};

// This works too.
class Solution2 {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (! head || ! head->next) return head;
        
        ListNode * n1 = head;
        //int ct = 0; // optional, can make it more efficient if k >> ct
        while (n1 && k > 0) {
            n1 = n1->next;
            -- k;
            //++ ct; // optional, can make it more efficient if k >> ct
        }
        
        if (n1 == NULL) return rotateRight(head, k); 
        //if (n1 == NULL) return rotateRight(head, k % ct); // optional, can make it more efficient if k >> ct
        
        ListNode * n2 = head;
        while (n1->next) {
            n1 = n1->next;
            n2 = n2->next;
        }
        
        // move n2->next and beyond to head
        n1->next = head;
        head = n2->next;
        n2->next = NULL;
        
        return head;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * Special conditions to consider:
 * - if list length L < k, rotate (k % L) right.
 * - if L == k, don't rotate.
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (NULL == head || k == 0) return head;
        
        ListNode * n1 = head, * n2 = head;
        int ct = 0;
        while (n2 != NULL && ct < k) {
            n2 = n2->next;
            ct ++;
        }
        if (ct < k) return rotateRight(head, k % ct);
        if (n2 == NULL) return head;
        
        while(n2->next != NULL) {
            n2 = n2->next;
            n1 = n1->next;
        }
        n2->next = head;
        head = n1->next;
        n1->next = NULL;
        
        return head;
    }
};


/*
Problem:

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

 */
