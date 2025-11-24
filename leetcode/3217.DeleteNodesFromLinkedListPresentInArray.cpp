
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode dummy;
        dummy.next = head;

        set<int> set(nums.begin(), nums.end());

        for (ListNode* n = &dummy; n->next != NULL; ) {
            if (set.contains(n->next->val)) {
                n->next = n->next->next;
            } else {
                n = n->next;
            }
        }
        return dummy.next;
    }
};


/**
3217. Delete Nodes From Linked List Present in Array
Medium

You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.

 

Example 1:

Input: nums = [1,2,3], head = [1,2,3,4,5]

Output: [4,5]

Explanation:

Remove the nodes with values 1, 2, and 3.

Example 2:

Input: nums = [1], head = [1,2,1,2,1,2]

Output: [2,2,2]
 */
