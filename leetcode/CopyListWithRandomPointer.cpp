#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


void dump(RandomListNode * n) {
    while (n) {
        cout << n->label << "(" << n->random->label << ")" << " -> ";
        n = n->next;
    }
    cout << endl;
}

// 1->2 => 1->1'->2->2'. 1'->random = 1->random->next.
// This works, improved from copyListWithRandomPtr2.
RandomListNode* copyListWithRandomPtr(RandomListNode *head) {
    if (! head) return NULL;
    
    RandomListNode *h, *n;
    
    // duplicate the existing list.
    for (h = head; h; h = n->next) {
        n = new RandomListNode(h->label);
        n->next = h->next;
        h->next = n;
    }
    
    // populate random pointer of the new list.
    for (h = head; h; h = h->next->next) {
        h->next->random = h->random ? h->random->next : NULL;
    }
    
    RandomListNode * new_head = head->next;

    // split the new list from the old list.
    for (h = head; h; h = h->next) {
        n = h->next;
        h->next = h->next->next;
        
        n->next = h->next ? h->next->next : NULL;
    }
    
    return new_head;
}
          
// This works.
RandomListNode* copyListWithRandomPtr2(RandomListNode *head) {
    if (! head) return NULL;
    
    RandomListNode * h = head;
    while (h) {
        RandomListNode * n = new RandomListNode(h->label);
        n->next = h->next;
        h->next = n;
        h = h->next->next;
    }
    
    for (h = head; h; h = h->next->next) {
        h->next->random = h->random ? h->random->next : NULL;
    }
    //dump(head); return NULL;
    
    RandomListNode * new_head = head->next;
    RandomListNode * t;
    
    for (h = head; h; h = h->next) {
        t = h->next;
        h->next = h->next->next;
        
        if (h->next == NULL) t->next = NULL;
        else t->next = h->next->next;
    }
    
    return new_head;
}
 

// This does NOT work.         
RandomListNode* copyListWithRandomPtr_not_work(RandomListNode *head) {
    if (! head) return NULL;
    
    RandomListNode *h2 = NULL, *t2 = NULL, *h = head, *h_prev = NULL; // h2/t2: copy
    
    
    while (h != NULL) {
        if (h2 == NULL) {
            h2 = t2 = new RandomListNode(h->label+10);
            t2->random = h;
            t2->next = NULL;
            
            h_prev = h;
            h = h->next;
            h_prev->next = t2;
        }
        else {
            t2->next = new RandomListNode(h->label+10);
            t2 = t2->next;
            t2->next = NULL;
            
            t2->random = h;
            h_prev = h;
            h = h->next;
            h_prev->next = t2;
        }
    }
    
    for (h = head, t2 = h2; t2 != NULL; ) {
        t2->random = t2->random->random->next;
        
        if (h->next->next == NULL) h->next = NULL;
        else h->next = h->next->next->random;
        
        h = h->next;
        t2 = t2->next;
    }
    
    return h2;
}


void test1() {
    cout << "test1" << endl;
    RandomListNode * L = new RandomListNode(1);
    L->random = L;
    dump(L);
    
    RandomListNode * L2 = copyListWithRandomPtr(L);
    dump(L2);
}

void test2() {
    cout << "test2" << endl;
    RandomListNode * L = new RandomListNode(1);
    L->next = new RandomListNode(2);
    L->random = L->next;
    L->next->random = L;
    dump(L);
    
    RandomListNode * L2 = copyListWithRandomPtr(L);
    dump(L2);
}

int main() {
    test1();
    test2();    
    return 0;
}


/*

 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list. 

*/