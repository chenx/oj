/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Iterative version. This works too.
class Solution4 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * h = NULL;
        
        while (head != NULL) {
            ListNode * tmp = h;
            h = head;
            head = head->next;
            h->next = tmp;
        }
        
        return h;
    }
};

// Iterative. This works too.
class Solution3 {
public:
    ListNode* reverseList(ListNode* head) {
        //if (head == NULL || head->next == NULL) return head; // not necessary.
        ListNode *h = NULL, *tmp;
        
        while (head != NULL) {
            tmp = head;
            head = head->next;
            tmp->next = h;
            h = tmp;
        }
        
        return h;
    }
};

// Iterative version. This works.
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * h = NULL;
        while (head != NULL) {
            ListNode * tmp = head->next;
            head->next = h;
            h = head;
            head = tmp;
        }
        
        return h;
    }
};

// Recursive version. This works too.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * tail = NULL;
        return rev(head, tail);
    }
    
    ListNode* rev(ListNode *h, ListNode *&t) {
        if (h == NULL || h->next == NULL) {
            t = h;
            return h;
        }
        
        ListNode * tmp = h;
        h = rev(h->next, t);
        t->next = tmp;
        t = tmp;
        t->next = NULL;
        return h;
    }
};

/**
Reverse Linked List

Reverse a singly linked list.

click to show more hints.
Hint:

A linked list can be reversed either iteratively or recursively. Could you implement both?
 */
