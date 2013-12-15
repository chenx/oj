//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 12/13/2012
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        // Now both are not null.
        int carry, sum;
        ListNode * s = NULL, * s_head; // can name s as tail to be more clear
            
        add(l1->val + l2->val, &sum, &carry, &s);
        s_head = s;
        
        for (l1 = l1->next, l2 = l2->next; l1 != NULL && l2 != NULL; 
             l1 = l1->next, l2 = l2->next) {
            add(l1->val + l2->val + carry, &sum, &carry, &s);
        }
        
        for ( ; l1 != NULL; l1 = l1->next) {
            add(l1->val + carry, &sum, &carry, &s);
        }
        
        for ( ; l2 != NULL; l2 = l2->next) {
            add(l2->val + carry, &sum, &carry, &s);
        }
        
        if (carry != 0) {
            s->next = new ListNode(carry);
            s = s->next;
        }
        
        return s_head;        
    }
    
    // *s points to the last node in the list.
    void add(int val, int * sum, int * carry, ListNode ** s) {
        if(val >= 10) {
            *sum = val - 10;
            *carry = 1;
        }
        else {
            *sum = val;
            *carry = 0;
        }
        
        if (*s == NULL) {
            *s = new ListNode(*sum);
        } else {
            (*s)->next = new ListNode(*sum);
            *s = (*s)->next;            
        }
    }
};

 
/*
// unoptimized version, this works.
class Solution {
public:
    ListNode *addTwoNumbers_v1(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        // both not null.
        int carry, sum;
        ListNode * s, * s_head;
        
        sum = l1->val + l2->val;
        carry = 0;
        if (sum >= 10) {
            carry = 1;
            sum -= 10;
        }
        s = s_head = new ListNode(sum);
        
        for (l1 = l1->next, l2 = l2->next; l1 != NULL && l2 != NULL; l1 = l1->next, l2 = l2->next) {
            sum = l1->val + l2->val + carry;
            carry = 0;
            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            }
            s->next = new ListNode(sum);
            s = s->next;
        }
        
        for ( ; l1 != NULL; l1 = l1->next) {
            sum = carry + l1->val;
            carry = 0;
            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            }
            s->next = new ListNode(sum);
            s = s->next;
        }
        
        for ( ; l2 != NULL; l2 = l2->next) {
            sum = carry + l2->val;
            carry = 0;
            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            }
            s->next = new ListNode(sum);
            s = s->next;
        }
        
        if (carry != 0) {
            s->next = new ListNode(carry);
            s = s->next;
        }
        
        return s_head;        
    }
};
*/
