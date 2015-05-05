//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/27/2012
// @Last modified: 12/27/2012
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL || head->next == NULL || k <= 1) return head;
        
        // at least 2 nodes in list.
        ListNode * n1 = head, * n2 = getKthNode(n1, k);
        if (n2 == NULL) return head;
        
        ListNode * nextHead, * prevTail = NULL, * newTail;
        
        do {
            nextHead = n2->next;
            
            if (prevTail == NULL) head = reverseList(n1, n2, & newTail);
            else        prevTail->next = reverseList(n1, n2, & newTail);

            prevTail = newTail;
            n1 = nextHead;
            n2 = getKthNode(n1, k);
        } while(n2 != NULL);
        
        newTail->next = nextHead; // don't forget this last processing.
        
        return head;
    }
    
    // reverse list h to t, assumption: len >= 2.
    ListNode * reverseList(ListNode * h, ListNode * t, ListNode ** newTail) {
        ListNode * tmp = h->next, * tmp2;
        *newTail = h;
        h->next = NULL;
        while (h != t) {
            tmp2 = tmp->next;
            tmp->next = h;
            h = tmp;
            tmp = tmp2;
        }
        return h;
    }
    
    ListNode * getKthNode(ListNode * n, int k) {
        int i;
        for (i = 1; i < k; i ++) {
            if (n == NULL) return NULL;
            n = n->next;
        }
        return n;
    }
};

/*
Problem:
        
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5 
 */
