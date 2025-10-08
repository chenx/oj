class MyHashMap {
    struct Node {
        int key, val;
        Node* next;
        Node(int k, int v) : key(k), val(v), next(NULL) {}
    };
    // Array where each cell is a Linked List.
    vector<Node*> array;
    int size;
    int capacity;
public:
    MyHashMap() {
        size = 0;
        capacity = 2069;
        array = vector<Node*>(capacity, new Node(0, 0));
    }
    
    void put(int key, int value) {
        int i = key % capacity;
        Node * node = array[i];
        for (; node->next != NULL; node = node->next) {
            if (node->next->key == key) { // exists
                node->next->val = value; // update value
                return; // exists
            }
        }
        node->next = new Node(key, value);
        ++ size;
    }
    
    int get(int key) {
        int i = key % capacity;
        Node * node = array[i];
        for (; node->next != NULL; node = node->next) {
            if (node->next->key == key) return node->next->val;
        }
        return -1; // not found.
    }
    
    void remove(int key) {
        int i = key % capacity;
        Node * node = array[i];
        for (; node->next != NULL; node = node->next) {
            if (node->next->key == key) {
                Node * tmp = node->next;
                node->next = node->next->next;
                delete tmp;
                -- size;
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

/**
706. Design Hashmap

Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

    MyHashMap() initializes the object with an empty map.
    void put(int key, int value) inserts a (key, value) pair into the HashMap. 
      If the key already exists in the map, update the corresponding value.
    int get(int key) returns the value to which the specified key is mapped, 
      or -1 if this map contains no mapping for the key.
    void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
 */
