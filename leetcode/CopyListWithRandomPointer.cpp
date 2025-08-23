#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

// Works. Best solution.
class Solution4 {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        Node *h, *n;
        for (h = head; h; h = n->next) {
            n = new Node(h->val);
            n->next = h->next;
            h->next = n;
        }

        for (h = head; h; h = h->next->next) {
            h->next->random = h->random ? h->random->next : NULL;
        }

        Node* copy = head->next;
        for(h = head; h; h = h->next) {
            n = h->next;
            h->next = n->next;
            n->next = h->next ? h->next->next : NULL;
        }

        return copy;
    }
};

// This works. 2/1/2016
// Pay attention to how split is done.
class Solution3 {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        
        // duplicate.
        for (RandomListNode * h = head; h != NULL; ) {
            RandomListNode * n = new RandomListNode(h->label);
            n->next = h->next;
            h->next = n;
            h = n->next;
        }
        
        // get random ptr.
        for (RandomListNode * h = head; h != NULL; ) {
            h->next->random = h->random == NULL ? NULL : h->random->next;
            h = h->next->next;
        }
        
        // split.
        RandomListNode * tail = head, * h = head->next, * t = h; // head/tail -> h/t
        while (true) {
            tail->next = t->next;
            tail = tail->next;
            if (tail == NULL) break;
            t->next = tail->next;
            t = t->next;
        }
        
        return h;
    }
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
//
// Note, to split the 2 lists, can use this too:
/* RandomListNode * new_head = head->next, *tail = new_head;
   // split the new list from the old list.
   for (RandomListNode * n = head; n != NULL; ) {
       n->next = tail->next;
       n = n->next;
       if (n != NULL) {
           tail->next = n->next;
           tail = tail->next;
       }
    }
*/
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
