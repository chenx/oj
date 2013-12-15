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
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode * n, *nh;
        if (l1->val < l2->val) {
            nh = n = l1;
            l1 = l1->next;
        } else {
            nh = n = l2;
            l2 = l2->next;
        }
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                n->next = l1;
                l1 = l1->next;
            } else {
                n->next = l2;
                l2 = l2->next;
            }
            n = n->next // don't forget to move the tail.
        }
        
        if (l1 != NULL) n->next = l1;
        else n->next = l2;
        
        return nh;
    }
};

//
// This works too.
//
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (! l1) return l2;
        if (! l2) return l1;
        
        // now both l1 and l2 are not NULL.
        ListNode * head = NULL, * tail = NULL;
        while (l1 && l2) {
            addNode(
                l1->val < l2->val ? l1 : l2,
                head,
                tail
                );
        }

        tail->next = l1 ? l1 : l2;
        
        return head;
    }
    
    void addNode (ListNode *& n, ListNode *& head, ListNode *& tail) {
        if (! head) {
            head = tail = n;
        }
        else {
            tail->next = n;
            tail = n;
        }
        n = n->next;
        tail->next = NULL;
    }
};