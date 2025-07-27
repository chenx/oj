// Works too.
class Solution3 {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

// Works too.
// 
class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        if (! head || ! head->next) return false;
        
        ListNode * slow = head, * fast = head->next; // "slow = head, fast = head;"" works too.
        while (fast && fast->next) { // "fast->next && fast->next->next" works too.
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        
        return false;
    }
};

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
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (! head || ! head->next) return false;
        ListNode *slow = head, *fast = head->next;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        
        return false;
    }
};

/*

Linked List Cycle
Total Accepted: 2253 Total Submissions: 6002

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space? 
 */
