//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/18/2012
// @Last modified: 12/18/2012
//
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

// This works too.
class Solution2 {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (! head || ! head->next) return head;
        
        ListNode * n1 = head;
        int ct = 0; // optional, can make it more efficient if k >> ct
        while (n1 && k > 0) {
            n1 = n1->next;
            -- k;
            ++ ct; // optional, can make it more efficient if k >> ct
        }
        
        //if (n1 == NULL) return rotateRight(head, k); 
        if (n1 == NULL) return rotateRight(head, k % ct); // optional, can make it more efficient if k >> ct
        
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


/*
Problem:

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

 */
