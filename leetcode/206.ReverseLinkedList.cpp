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
        //if (! head || ! head->next) return head; // works with or without this.
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

// Iterative version. This works.
class Solution3 {
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

// Recursive version.
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* t = nullptr;
        return rev(head, t);
    }

    ListNode* rev(ListNode* head, ListNode*& tail) {
        if (! head) return nullptr;
        if (! head->next) {
            tail = head;
            return head;
        }

        ListNode* h = rev(head->next, tail);
        if (tail) {
            tail->next = head;
            tail = head;
            tail->next = nullptr;
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
        t->next = NULL; // REMEMBER This !!!
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
