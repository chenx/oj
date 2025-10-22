/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
    const minHeap = new MyPriorityQueue((a, b) => a.val - b.val);

    lists.forEach(node => {
        if (node !== null) minHeap.push(node);
    });
    
    let head = null;
    let tail = null;
    while (!minHeap.empty()) {
        const node = minHeap.top();
        minHeap.pop();
        if (node.next !== null) {
            minHeap.push(node.next);
        }
        node.next = null;

        if (head === null) {
            head = tail = node;
        } else {
            tail.next = node;
            tail = node;
        }
    }

    return head;
};

class MyPriorityQueue {
    constructor(compareFunc) {
        this.compareFunc = compareFunc;
        this.heap = [];
    }
        
    push(val) {
        this.heap.unshift(val);
        // this.heap.push(val); // this works too.
        this.heap.sort(this.compareFunc);
    }
        
    pop() {
        if (this.heap.size === 0) return null;
        this.heap.shift();
    }
        
    top() {
        if(this.heap.size === 0) return null;
        return this.heap[0];
    }
        
    size() {
        return this.heap.length;
    }

    empty() {
        return this.heap.length === 0;
    }
};
