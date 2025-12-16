// Reservoir sampling.
// Time: O(n)
// Space: O(1)
class Solution {
    ListNode* h;
public:
    Solution(ListNode* head) {
        h = head;
    }
    
    int getRandom() {
        ListNode* head = h;
        int i = 0, v = head->val;
        for (; head; head = head->next) {
            ++ i;
            if (rand() % i == 0) v = head->val;
        }
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */


/**
382. Linked List Random Node
Medium

Given a singly linked list, return a random node's value from the linked list. Each node must have the 
same probability of being chosen.

Implement the Solution class:

    Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
    int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the 
        list should be equally likely to be chosen.
 */
