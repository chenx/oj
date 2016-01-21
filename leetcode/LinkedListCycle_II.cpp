/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Works too. Maybe better.
class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
        
        ListNode *slow = head, *fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            if (slow == fast) {
                slow = head;
                fast = fast->next;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return NULL;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (! head || ! head->next) return NULL;
        ListNode *slow = head, *fast = head->next;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // Be careful: x = slow->next, NOT x = slow.
                ListNode *x = slow->next, *h = head; 
                while (x != h) {
                    x = x->next; h = h->next;
                }
                return x;
            }
        }
        
        return NULL;
    }
    
};


/*

Linked List Cycle II

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space? 
 */
