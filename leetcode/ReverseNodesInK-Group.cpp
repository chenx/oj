//
// http://www.leetcode.com/onlinejudge#
// @Author: X. Chen
// @Created on: 12/27/2012
//

// Works. Tested. More clear. Use dummy node to save code.
class Solution3 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k <= 1) return head;
        
        ListNode dummy(0);
        ListNode * prev = &dummy, * h = head;
        prev->next = head;
        
        while (true) {
            ListNode * t = h;
            for (int i = 1; i < k && t != NULL; ++ i) t = t->next; // i starts with 1 !
            if (t == NULL) break; // less than k nodes left.
            
            ListNode * tail = t->next;
            t->next = NULL;  // don't forget this.
            
            prev->next = rev(h, t);
            t->next = tail;
            
            prev = t;
            h = t->next;
        }
        
        return dummy.next;
    }
    
    ListNode* rev(ListNode *h, ListNode *&t) {
        if (h == NULL || h->next == NULL) return h;
        
        ListNode * tmp = h;
        h = rev(h->next, t);
        t->next = tmp;
        t = tmp;
        t->next = NULL;
        return h;
    }  
};

// This works too. More clear. 11/15/2015
// The key is to find head and tail of each segment to reverse, and keep prev and next.
class Solution2 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 1) return head;
        
        ListNode *h = head, *prev = NULL, *t, *next;
        int ct;
        
        while (h != NULL) {
            for (t = h, ct = k - 1; ct > 0 && t != NULL; -- ct, t = t->next) {}
            if (t == NULL) break; // less than k nodes. be carefull of this!
            
            next = t->next; // prev, next are nodes before/after the segment to reverse.
            rev(h, t);
            
            if (prev == NULL) head = h;
            else prev->next = h;

            prev = t; // don't forget this!
            h = t->next = next;
        }
        
        return head;
    }
    
    // reverse list h to t.
    void rev(ListNode *&h, ListNode *&t) {
        ListNode * new_tail = h;
        t->next = NULL;
        t = NULL;
        
        while (h != NULL) {
            ListNode *tmp = h->next;
            h->next = t;
            t = h;
            h = tmp;
        }
        
        h = t;
        t = new_tail;
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
Reverse Nodes in k-Group
Difficulty: Hard

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5 
 */
