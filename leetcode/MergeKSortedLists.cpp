//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/25/2012
// @Last modified: 12/25/2012
//

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
