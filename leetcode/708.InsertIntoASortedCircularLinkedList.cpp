
// From: https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/editorial/
// 3 cases.
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (! head) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }

        bool insert = false;
        Node *prev = head, *cur = head->next;
        do {
            if (prev->val <= insertVal && insertVal <= cur->val) {
                insert = true;
            } else if (prev->val > cur->val) {
                if (insertVal >= prev->val || insertVal <= cur->val) {
                    insert = true;
                }
            }

            if (insert) {
                Node *node = new Node(insertVal, cur);
                prev->next = node;
                return head;
            }

            prev = cur, cur = cur->next;
        } while (prev != head);

        Node *node = new Node(insertVal, head->next);
        head->next = node;
        return head;
    }
};

/**
708. Insert into a Sorted Circular Linked List
Medium

Given a Circular Linked List node, which is sorted in non-descending order, write a function to insert a value insertVal into the list 
such that it remains a sorted circular list. The given node can be a reference to any single node in the list and may not necessarily 
be the smallest value in the circular list.

If there are multiple suitable places for insertion, you may choose any place to insert the new value. After the insertion, the circular 
list should remain sorted.

If the list is empty (i.e., the given node is null), you should create a new single circular list and return the reference to that 
single node. Otherwise, you should return the originally given node.
 */
