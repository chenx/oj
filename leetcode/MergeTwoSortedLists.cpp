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

// Works too. Shortest.
class Solution4 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode * n = & dummy;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) add(n, l1);
            else add(n, l2);
        }
        n->next = (l1 != NULL) ? l1 : l2;

        return dummy.next;
    }
    
    void add(ListNode *& n, ListNode *& l) {
        n->next = l;
        n = l;
        l = l->next;
        n->next = NULL; // works too without this.
    }
};


// This works too. Seems most simple. 11/15/2015
class Solution3 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode *h = NULL, *t = NULL;
        
        while (l1 != NULL && l2 != NULL) {
            ListNode *tmp = (l1->val <= l2->val) ? l1 : l2;
            if (h == NULL) { h = t = tmp; }
            else { t->next = tmp; t = tmp; }

            if (l1 == tmp) l1 = l1->next;
            else l2 = l2->next;
        }
        
        t->next = (l1 != NULL) ? l1 : l2;
        
        return h;        
    }
};


//
// This works too.
//
class Solution2 {
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


class Solution1 {
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


/**
Merge Two Sorted Lists
Difficulty: Easy

Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
 */
