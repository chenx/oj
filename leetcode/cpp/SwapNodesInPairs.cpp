//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/26/2012
// @Last modified: 12/26/2012
//
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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        
        // split first.
        ListNode * n1 = head, * t1 = n1;
        ListNode * n2 = head->next, * t2 = n2;
        
        for (ListNode * n = n2->next; n != NULL; n = n->next) {
            t1->next = n;
            t1 = n;
            
            n = n->next;
            if (n == NULL) break;

            t2->next = n;
            t2 = n;
        }
        
        t1->next = NULL;
        t2->next = NULL;
        
        // Then merge.
        ListNode * t = head = n2; 
        n2 = n2->next;
        while (n1 != NULL && n2 != NULL) {
            t->next = n1;
            t = n1;
            n1 = n1->next;
            
            t->next = n2;
            t = n2;
            n2 = n2->next;
        }
        
        if (n1 != NULL) t->next = n1;
        if (n2 != NULL) t->next = n2;
        
        return head;
    }
};


//
// This works too.
//
class Solution2 {
public:
    ListNode *swapPairs(ListNode *head) {
        if (! head || ! head->next) return head;
        ListNode * n1 = head, * n2 = head->next;
        ListNode * prev = NULL, * next = n2->next;
        
        // swap first 2 nodes.
        n1->next = next;
        n2->next = n1;
        head = n2;
        
        prev = n1;
        
        while (next && next->next) {
            n1 = next;
            n2 = next->next;
            next = n2->next;
            
            n2->next = n1;
            n1->next = next;
            prev->next = n2;
            
            prev = n1;
        }
        
        return head;
    }
};

// This works too. Use a dummy node. 11/8/2014
class Solution3 {
public:
    ListNode *swapPairs(ListNode *head) {
        if (! head || ! head->next) return head;
        
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode * prev = dummy, * n1 = head, * n2;
        
        while (n1 && n1->next) {
            n2 = n1->next;
            n1->next = n2->next;
            n2->next = n1;
            prev->next = n2;
            
            prev = n1;
            n1 = n1->next;
        }
        
        head = dummy->next;
        delete dummy;
        return head;
    }
};

// This also works. 
// Note the use of a local variable dummy, which does not need manual delete.
class Solution4 {
public:
    ListNode *swapPairs(ListNode *head) {
        if (! head || ! head->next) return head;
        
        ListNode dummy(0);
        ListNode * prev = & dummy;
        prev->next = head;
        ListNode * p = head;
        
        while (p && p->next) {
            ListNode * tmp = p->next;
            prev->next = tmp;
            p->next = tmp->next;
            tmp->next = p;
            
            prev = p;
            p = prev->next;
        }
        
        return dummy.next;
    }
};

/*
Problem:

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the 
values in the list, only nodes itself can be changed.

 */
