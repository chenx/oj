/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class cmp {
public:
    bool operator()(const ListNode * a, const ListNode * b) {
        return a->val > b->val;
    }
}; 
 
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> minPQ;
        
        for (auto L : lists) {
            if (L != NULL) minPQ.push(L);
        }
        
        ListNode dummy(0);
        ListNode * n = &dummy;
        
        while (! minPQ.empty()) {
            n->next = minPQ.top();
            minPQ.pop();
            n = n->next;
            if (n->next != NULL) minPQ.push(n->next);
        }
        return dummy.next;
    }
};


