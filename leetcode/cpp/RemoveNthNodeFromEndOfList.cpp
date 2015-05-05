//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 12/24/2012
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
 * Note: things to be careful about:
 * 1) list length < n
 * 2) list length == n
 * 3) delete n1->next, not n1.
 * 4) release memory of the deleted node.
 */

// This works too. 10/26/2014
class Solution2 {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (n <= 0 || ! head) return head;
        
        ListNode * p1 = head;
        int i = 0;
        for (; i < n; ++ i) {
            if (! p1) break;
            p1 = p1->next;
        }
        
        if (i < n) return head; // n > list.length
        
        if (p1 == NULL) { // n == list.length, remove 1st node.
            p1 = head->next;
            delete head;
            return p1;
        }
        
        ListNode * p2 = head, * prev = NULL;
        while (p1) {
            p1 = p1->next;
            prev = p2;
            p2 = p2->next;
        }
        
        // remove p2.
        prev->next = p2->next;
        delete p2;
        
        return head;
    }
};


class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL || n <= 0) return NULL;
        
        ListNode * n1 = head, * n2 = head, *tmp;
        
        while(n2 != NULL && n > 0) {
            n2 = n2->next;
            n --;
        }
        if (n > 0) return head; // list has < n nodes.
        
        if (n2 == NULL) { // list len == n, head is to be deleted.
            tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        // now n2 and n are different by n nodes. 
        // n1->next is the node to delete.
        
        while (n2->next != NULL) {
            n2 = n2->next;
            n1 = n1->next;
        }
        
        tmp = n1->next;
        n1->next = n1->next->next;
        delete tmp;
        
        return head;
    }
};

/*
Problem:

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

 */
