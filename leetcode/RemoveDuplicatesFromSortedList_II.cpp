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