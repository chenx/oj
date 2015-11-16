//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/25/2012
// @Last modified: 12/25/2012
//

// complexity: (n1 + n2 + .. + nk) * log(k)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 

//
// Solution 4. This works too. O(n^2 log(k))
// Prefer this over Solution 2, for more standard use of priority_queue.
// Best solution so far.
//
class comp {
public:    
    bool operator()(const ListNode * a, const ListNode * b) const {
        return a->val > b->val; // min heap.
    }
};

class Solution4 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode * head = NULL, * tail = NULL;
        priority_queue<ListNode *, vector<ListNode *>, comp> pq;
        
        int n = lists.size();
        for (int i = 0; i < n; ++ i) {
            if (lists[i] != NULL) pq.push(lists[i]);
        }
        
        while (! pq.empty()) {
            ListNode * tmp = pq.top();
            pq.pop();
            append(head, tail, tmp);
            if (tmp->next != NULL) pq.push(tmp->next);
        }
        return head;
    }
    
    void append(ListNode *& head, ListNode *&tail, ListNode * tmp) {
        if (head == NULL) {
            head = tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tail->next;
        }
    }
};


// For min heap, use ">".
bool cmp(const ListNode * a, const ListNode * b) {
    return a->val > b->val;
}

// This works too. Is the best solution. 
// Uses std fuctions: make_heap, push_heap, pop_heap.
// See: http://www.cplusplus.com/reference/algorithm/make_heap/
// Be careful that a list could be empty.
// O(n^2log(n)). 11/19/2014.
class Solution3 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();

        vector<ListNode *> h;
        for (int i = 0; i < n; ++ i) { 
            if (lists[i]) h.push_back(lists[i]); 
        }
        
        if (h.size() == 0) return NULL;
        if (h.size() == 1) return h[0];
        
        make_heap(h.begin(), h.end(), cmp);
        
        ListNode * head = NULL, * tail = NULL;
        
        while (! h.empty()) {
            // get top element (smallest), add to list.
            pop_heap(h.begin(), h.end(), cmp);
            ListNode * node = h.back();
            
            if (head == NULL) { head = tail = node; }
            else { tail->next = node; tail = tail->next; }
            
            h.pop_back();
            
            // add next element to heap.
            if (node->next) {
                h.push_back(node->next);
                push_heap(h.begin(), h.end(), cmp);
                node->next = NULL;
            }
        }
        
        return head;
    }
};


// This should work.
// But times out for large test cases. O(n^3).
// Merge sort: O(m+n). So complexity is: 
// n+n + (2n+n) + (3n+n) + ... + ((n-1)*n+n) => O(n^3).
// 11/19/2014.
class Solution2 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        if (n == 0) return NULL;
        if (n == 1) return lists[0];
        
        ListNode * head = merge(lists[0], lists[1]);
        for (int i = 2; i < n; ++ i) {
            head = merge(head, lists[i]);
        }
        return head;
    }
    
    ListNode * merge(ListNode * a, ListNode * b) {
        if (! a) return b;
        if (! b) return a;
        
        ListNode * head = NULL, * tail = NULL;
        while (a && b) {
            if (a->val < b->val) {
                add(head, tail, a);
            }
            else {
                add(head, tail, b);
            }
        }
        
        if (a) { tail->next = a; }
        if (b) { tail->next = b; }
        return head;
    }
    
    void add(ListNode * &head, ListNode * &tail, ListNode * &a) {
        if (head == NULL) {
            head = tail = a;
        }
        else {
            tail->next = a;
            tail = a;
        }
        a = a->next;
        tail->next = NULL;
    }
};

// This works. O(n^2log(n)).
class Solution {
    ListNode ** Heap; // a min heap.
    int Heap_count;
    int Heap_size;
    
    void swap(ListNode ** a, ListNode ** b) {
        //printf("before swap: %d, %d -- ", a->val, b->val);
        ListNode * tmp = *a;
        *a = *b;
        *b = tmp;
        //printf("after swap: %d, %d -- \n", a->val, b->val);
    }
    
    void Heap_Insert(ListNode * n) {
        if (n == NULL) return;
        
        Heap[Heap_count ++] = n;
        for (int i = Heap_count - 1, p = (i-1)/2;
             i >= 1;
             i = p, p = (i-1)/2) {
            if (Heap[i]->val >= Heap[p]->val) break;
            else swap(&Heap[i], &Heap[p]); 
        }    
        printf("after insert %d: ", n->val); Heap_dump();    
    }
    
    ListNode * Heap_Top() {
        if (Heap_count == 0) return NULL;
        return Heap[0];
    }
    
    void Heap_Pop() {
        if (Heap_count == 0) return;
        //delete Heap[0]; // don't delete!
        Heap[0] = Heap[-- Heap_count];
        int i = 0;
        while (i < Heap_count) {
            int c = getSmallerChild(i);
            if (c == -1) break;
            if (Heap[i]->val <= Heap[c]->val) break;
            swap(&Heap[i], &Heap[c]);
            i = c;
        }
    }
    
    int Heap_Count() { return Heap_count; }
    
    void Heap_dump() {
        printf("Heap: ");
        for (int i = 0; i < Heap_count; i ++) {
            printf("%d ", Heap[i]->val);
        }
        puts("");
    }
    
    int getSmallerChild(int i) {
        int lc = 2*i + 1;
        int rc = 2*i + 2;
        if (lc >= Heap_count) return -1;
        if (rc == Heap_count) return lc;
        return (Heap[lc]->val <= Heap[rc]->val) ? lc : rc;
    }


public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int len = lists.size();
        if (len == 0) return NULL;
        if (len == 1) return lists[0];
        
        ListNode * head = NULL, * tail, * tmp;
        Heap = new ListNode*[len];
        Heap_size = len;
        Heap_count = 0;
        int i;
        
        for (i = 0; i < len; i ++) {
            Heap_Insert(lists[i]);
        }
        
        Heap_dump();
        
        while(Heap_Count() > 0) {
            tmp = Heap_Top()->next;
            if (head == NULL) {
                head = tail = Heap_Top();
            } else {
                tail->next = Heap_Top();
                tail = tail->next;
            }
            tail->next = NULL;
            
            Heap_Pop();
            Heap_Insert(tmp);
        }
        
        return head;
    }
};

void writeList(ListNode * n) {
    for (ListNode * m = n; m != NULL; m = m->next) {
        printf("%d ", m->val);
    }
    puts("");
}

int main() {
    Solution s;
    vector<ListNode *> lists;
    ListNode * n1 = new ListNode(1);
    ListNode * n2 = new ListNode(0);
    lists.push_back(n1);
    lists.push_back(n2);
    
    ListNode * n = s.mergeKLists(lists);
    writeList(n);
    
    return 0;
}


/**
Merge k Sorted Lists
Difficulty: Hard

Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity. 
 */
