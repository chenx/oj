// Solution 2. Works too. Use STL list. Better.

#include <list>

struct Node {
    int key, val;
    Node(int k, int v) : key(k), val(v) {}
};


class LRUCache{
    int capacity;
    list<Node> dll;
    unordered_map<int, list<Node>::iterator> ht; // hashtable.
public:
    // @param capacity, an integer
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    // @return an integer
    int get(int key) {
        if (ht.find(key) == ht.end()) return -1;
        
        int val = ht[key]->val;
        dll.splice(dll.begin(), dll, ht[key]);
        ht[key] = dll.begin();
        return val;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        if (ht.find(key) != ht.end()) {
            ht[key]->val = value;
            dll.splice(dll.begin(), dll, ht[key]);
            ht[key] = dll.begin();
            //dll.front().val = value; // works too.
        }
        else {
            dll.push_front(Node(key, value));
            ht[key] = dll.begin();
            
            if (dll.size() > capacity) {
                ht.erase(dll.back().key);
                dll.pop_back();
            }
        }
    }
};


// Solution 1. works.

struct Node {
    int key;
    int val;
    struct Node * prev;
    struct Node * next;
    Node(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}
};

class DLL {
private:
    Node * head;
    Node * tail;
    int _size;
public:
    DLL() : head(NULL), tail(NULL), _size(0) {}
    
    int size() { return _size; }
    bool empty() { return _size == 0; }
    Node * front() { return head; }
    
    void pop_front() {
        if (empty()) return;
        remove(head);
    }
    
    Node * push_back(int key, int val) {
        Node * n = new Node(key, val);
        
        if (head == NULL) {
            head = tail = n;
        }
        else {
            n->next = tail;
            tail->prev = n;
            tail = n;
        }
        
        _size ++;
        
        return n;
    }
    
    void remove(Node * n) {
        if (! n || _size == 0) return;
        
        if (_size == 1) {
            if (n != head) return; // possible if n is an irrelevant node.
            head = tail = NULL;
        }
        else {
            if (n == head) {
                head = head->prev;
                head->next = NULL;
            }
            else if (n == tail) {
                tail = tail->next;
                tail->prev = NULL;
            }
            else {
                n->prev->next = n->next;
                n->next->prev = n->prev;
            }
        }
        
        delete n;
        -- _size;
    }
};

class LRUCache{
    int capacity;
    DLL dll;
    unordered_map<int, Node*> ht; // hashtable.
public:
    // @param capacity, an integer
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    // @return an integer
    int get(int key) {
        if (ht.find(key) == ht.end()) return -1;
        int val = ht[key]->val;
        
        dll.remove(ht[key]);
        ht[key] = dll.push_back(key, val);
        return val;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        if (ht.find(key) != ht.end()) {
            dll.remove(ht[key]);
        }
        
        ht[key] = dll.push_back(key, value);
        
        if (dll.size() > capacity) {
            int k = dll.front()->key;
            dll.remove(dll.front());
            ht.erase(ht.find(k));
        }
    }
};
