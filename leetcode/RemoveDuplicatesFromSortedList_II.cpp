//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 12/24/2012
//

// Works. Tested. Best.
class Solution5 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode * n = & dummy;
        n->next = head;
        
        while (n->next && n->next->next) {
            if (n->next->val == n->next->next->val) {
                int dupVal = n->next->val;
                while (n->next && n->next->val == dupVal) {
                    ListNode * tmp = n->next;
                    n->next = tmp->next;
                    delete tmp; // still need to delete n later.
                }
            }
            else {
                n = n->next;
            }
        }

        return dummy.next;
    }
};

// Works too. Tested. Use dummy node. 
class Solution4 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode * n = &dummy;
        bool dup = false;

        for (n->next = head; n->next && n->next->next; ) {
            // must check to make sure n->next->next is not NULL here.
            while (n->next->next && n->next->val == n->next->next->val) {
                ListNode * tmp = n->next;
                n->next = tmp->next;
                delete tmp;
                dup = true;
            }
            
            if (dup) {
                ListNode * tmp = n->next;
                n->next = tmp->next;
                delete tmp;
                dup = false;
            }
            else {
                n = n->next;
            }
        }
        
        return dummy.next;
    }
};

// Works. Use dummy node to simplify code.
class Solution3 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode * n = &dummy;
        bool dup = false;

        for (n->next = head; n->next && n->next->next; ) {
            if (n->next->val == n->next->next->val) {
                ListNode * tmp = n->next;
                n->next = tmp->next;
                delete tmp;
                dup = true;
            }
            else {
                if (dup) { // remove n->next, last of duplicated nodes.
                    ListNode * tmp = n->next;
                    n->next = tmp->next;
                    delete tmp;
                    dup = false;
                }
                else {
                    n = n->next;
                }
            }
        }
        
        if (n->next && dup) { // remove last node of list.
            delete n->next;
            n->next = NULL;
        }
        
        return dummy.next;
    }
};

// This works too.
// Every time when duplicate is found, go all the way to end of duplicates,
// and delete entire duplicated section.
class Solution2 {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *prev = NULL, *p = head;

        while (p != NULL && p->next != NULL) {
            if (p->val != p->next->val) { // remove p->next.
                prev = p;
                p = p->next;
            } else { // duplicate found: p and p->next.
                ListNode * tail = p->next;
                while (tail->next != NULL && p->val == tail->next->val) { tail = tail->next; }

                // duplicates go all the way to list end. Remove from p to list end.
                if (tail == NULL) { // last node
                    if (prev == NULL) {
                        deleteList(head);
                        head = NULL;
                    }
                    else {
                        deleteList(p);
                        prev->next = NULL;
                    }
                    p = NULL;
                    break;
                }
                else { // remove duplicated nodes p to tail.
                    ListNode * n = tail->next;
                    tail->next = NULL;
                    deleteList(p);
                    
                    if (prev == NULL) { head = p = n; }
                    else { prev->next = p = n; }
                }
            }
        }
        
        return head;
    }
    
    void deleteList(ListNode * n) {
        while (n != NULL) {
            ListNode * tmp = n->next;
            delete n;
            n = tmp;
        }
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
 * Every time a pair of duplicates is found, remove the
 * second node, set found = 1.
 * When duplicates is not found, 
 * if found == 1, remove the first node
 *     which is the last of the duplicates.
 * else, shift forward.
 * 
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        
        // now list has at least 2 nodes.
        ListNode *n_prev = NULL, * n = head, * n2 = head->next;
        int found = 0;
        
        while (n2 != NULL) {
            if (n->val == n2->val) { // remove n2
                n->next = n2->next;
                delete n2;
                n2 = n->next;
                found = 1;
            }
            else if (found == 1) { // remove n - lasted one. n2 != null 
                if (n_prev == NULL) {
                    delete n;
                    head = n = n2;
                } else {
                    n_prev->next = n2;
                    delete n;
                    n = n2;
                }
                n2 = n->next;
                found = 0;
            }
            else { // n->val != n2.val, and found == 0.
                n_prev = n; // don't forget this.
                n = n2;
                n2 = n->next;
            }
        }
        
        // last one.
        if (found == 1) { // remove n. n2 == null 
            if (n_prev == NULL) head = NULL; // null
            else n_prev->next = NULL; 
            
            delete n;
        }
                        
        return head;
    }
};


/*
Problem:

Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
 */
