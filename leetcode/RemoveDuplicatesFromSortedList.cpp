//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 12/24/2012
//

// Recursive solution. Works too.
class Solution4 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (! head || ! head->next) return head;
        head->next = deleteDuplicates(head->next);

        if (head->val == head->next->val) {
            ListNode * tmp = head;
            head = head->next;
            delete tmp;
        }
        return head;
    }
    
    // if no need to free duplicated node, can use this (like in Java), only 3 lines then.
    ListNode* deleteDuplicates2(ListNode* head) {
        if (! head || ! head->next) return head;
        head->next = deleteDuplicates(head->next);
        return head->val == head->next->val ? head->next : head;
    }
};

// Works too.
class Solution3 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode * n = & dummy;

        for (n->next = head, n = head; n && n->next; ) {
            if (n->val == n->next->val) {
                ListNode * tmp = n->next;
                n->next = tmp->next;
                delete tmp;
            }
            else n = n->next;
        }
        
        return dummy.next;
    }
};

// Works.
class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode * n = & dummy;

        for (n->next = head; n->next && n->next->next; ) {
            if (n->next->val == n->next->next->val) {
                ListNode * tmp = n->next;
                n->next = tmp->next;
                delete tmp;
            }
            else n = n->next;
        }
        
        return dummy.next;
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        
        // now list contains at least 2 nodes.
        ListNode * tmp;
        
        for (ListNode *n = head; n->next != NULL; ) {
            if (n->next->val == n->val) {
                tmp = n->next;
                n->next = n->next->next;
                delete tmp;
            }
            else {
                n = n->next;
            }            
        }
        
        return head;
    }
};


/**
Remove Duplicates from Sorted List
Difficulty: Easy

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. 
 */
