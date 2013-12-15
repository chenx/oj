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


/*
Problem:

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.

 */