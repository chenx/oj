class Node {
    constructor(key, value) {
        this.key = key;
        this.value = value;
        this.prev = null;
        this.next = null;
    }
};

// Class node can also be defined as:
// var Node = function(key, value) {
//     this.key = key;
//     this.value = value;
//     this.prev = null;
//     this.next = null;
// }

/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) { // Map + DLL
    this.map = new Map();
    this.capacity = capacity;
    this.size = 0;

    this.head = new Node();
    this.tail = new Node();
    this.head.next = this.tail;
    this.tail.prev = this.head;
};

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    if (this.map.get(key) == null) return -1;

    // return value, move node to front of DLL.
    const node = this.map.get(key);
    this.moveToFront(node);
    return node.value;
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    if (this.map.get(key) == null) {
        // add to front of DLL and map.
        let node = new Node(key, value);
        this.map.set(key, node);

        node.prev = this.head;
        node.next = this.head.next;
        this.head.next.prev = node;
        this.head.next = node;

        this.size += 1;
        if (this.size > this.capacity) { // remove from back of DLL
            this.map.delete(this.tail.prev.key);  // Don't forget this.
            this.tail.prev = this.tail.prev.prev;
            this.tail.prev.next = this.tail;
            this.size -= 1;
        }
    } else {
        // Update value, and move node to front of DLL.
        const node = this.map.get(key);
        node.value = value;

        this.moveToFront(node);
    }
};

LRUCache.prototype.moveToFront = function(node) {
    if (node.prev != this.head) {
        node.prev.next = node.next;
        node.next.prev = node.prev;

        node.prev = this.head;
        node.next = this.head.next;
        this.head.next.prev = node;
        this.head.next = node;
    }
}

/** 
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
