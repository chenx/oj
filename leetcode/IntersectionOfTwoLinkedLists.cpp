/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Works.
class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // if (! headA || ! headB) return NULL; // Good but not necessary.
        int lena = 0, lenb = 0;
        
        for (ListNode * n = headA; n != NULL; n = n->next) ++ lena;
        for (ListNode * n = headB; n != NULL; n = n->next) ++ lenb;
        
        while (lena > lenb) { headA = headA->next; -- lena; }
        while (lena < lenb) { headB = headB->next; -- lenb; }
        
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};

//
// This works. O(n+m) time, O(1) space.
// Concept: first find length of both lists, then start from where 
// distance is the same to the end for both lists, find common node.
//
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (! headA || ! headB) return NULL;
        
        int lena = 0, lenb = 0;
        for (ListNode * a = headA; a; a = a->next) ++ lena;
        for (ListNode * b = headB; b; b = b->next) ++ lenb;
        
        if (lena > lenb) {
            for (int n = lena - lenb; n > 0; -- n) headA = headA->next;
        }
        else {
            for (int n = lenb - lena; n > 0; -- n) headB = headB->next;
        }
        
        while (headA) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};

/**
 * Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.
 *
 * @since: 11/27/2014
 */
