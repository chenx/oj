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
