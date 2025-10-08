class LRUCache {
    // map (key, node) + dll 
    // dll Node(key, val)
    class Node {
        int key, val;
        Node prev;
        Node next;

        public Node(int key, int val) {
            this.key = key;
            this.val = val;
            this.prev = null;
            this.next = null;
        }
    }
    Node head, tail;
    HashMap<Integer, Node> mp;
    int capacity;
    int size;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.size = 0;
        this.mp = new HashMap<>();

        this.head = new Node(-1, -1);
        this.tail = new Node(-1, -1);
        this.head.next = tail;
        this.tail.prev = head;
    }
    
    public int get(int key) {
        if (mp.get(key) == null) return -1;

        Node node = mp.get(key);
        moveNodeToHead(node);
        return node.val;
    }
    
    public void put(int key, int value) {
        if (mp.get(key) == null) {
            Node node = new Node(key, value);
            node.prev = head;
            node.next = head.next;
            head.next.prev = node;
            head.next = node;
            mp.put(key, node);

            this.size += 1;
            if (this.size > this.capacity) {
                // remove this.tail.prev from mp.
                mp.remove(this.tail.prev.key);
                this.tail.prev.prev.next = this.tail;
                this.tail.prev = this.tail.prev.prev;
                this.size -= 1;
            }
        } else {
            Node node = mp.get(key);
            node.val = value;
            moveNodeToHead(node);
        }
    }

    private void moveNodeToHead(Node node) {
        if (node != this.head.next) {
            node.prev.next = node.next;
            node.next.prev = node.prev;

            node.prev = head;
            node.next = head.next;
            head.next.prev = node;
            head.next = node;
        }    
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

/**
146. LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, 
    add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, 
    evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.
 */
