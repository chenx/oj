//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/5/2012
// @Last modified: 1/5/2012
//

// This works too. Slightly different.
class Solution2 {
public:
    ListNode *partition(ListNode *head, int x) {
        // split the original list into 2, based on x. Then combine.
        if (head == NULL || head->next == NULL) return head;
        
        ListNode * h1 = NULL, * t1 = NULL, 
                 * h2 = NULL, * t2 = NULL; // don't forget to intialize to NULL.
        while (head != NULL) {
            if (head->val < x) { addNodeToList(h1, t1, head); }
            else { addNodeToList(h2, t2, head); }
        }
        
        if (t1 == NULL) return h2; // don't forget t1 could be NULL.
        else {
            t1->next = h2;
            return h1;
        }
    }
    
    // h and t can be ptr to ptr or reference of ptr.
    // v can be both, or just a ptr.
    void addNodeToList(ListNode * &h, ListNode * &t, ListNode *& v) {
        if (NULL == h) {
            h = t = v;
        }
        else {
            t->next = v;
            t = t->next;
        }
        v = v->next;
        t->next = NULL; // This is necessary.
    }
};

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
    ListNode *partition(ListNode *head, int x) {
        // split the original list into 2, based on x. Then combine.
        if (head == NULL || head->next == NULL) return head;
        
        ListNode * h1 = NULL, * t1 = NULL, 
                 * h2 = NULL, * t2 = NULL, * tmp; // don't forget to intialize to NULL.
        while (head != NULL) {
            tmp = head->next;
            if (head->val < x) { addNodeToList(h1, t1, head); }
            else { addNodeToList(h2, t2, head); }
            head = tmp;
        }
        
        if (t1 == NULL) return h2; // don't forget t1 could be NULL.
        
        t1->next = h2;
        return h1;
    }
    
    // h and t can be ptr to ptr or reference of ptr.
    // v can be both, or just a ptr.
    void addNodeToList(ListNode * &h, ListNode * &t, ListNode * v) {
        if (NULL == h) {
            h = t = v;
        }
        else {
            t->next = v;
            t = t->next;
        }
        v->next = NULL; // This is necessary!
    }
};


/*
Problem:

Given a linked list and a value x, partition it such that all nodes less than x come 
before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
 */
