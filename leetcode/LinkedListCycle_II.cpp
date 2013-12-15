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
Total Accepted: 1261 Total Submissions: 4276

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space? 
 */