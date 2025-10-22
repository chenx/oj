/**
 * @param {number[][]} intervals
 * @return {number}
 */
var minMeetingRooms = function(intervals) {
    intervals.sort((a, b) => a[0] - b[0]);

    const minHeap = new MyMinHeap((a, b) => a - b);
    for (let i = 0; i < intervals.length; ++ i) {
        if (!minHeap.empty() && intervals[i][0] >= minHeap.top()) minHeap.pop();
        minHeap.push(intervals[i][1]);
    }

    return minHeap.size();
};

class MyMinHeap {
    constructor(compareFunc) {
        this.compareFunc = compareFunc;
        this.heap = [];
    }
        
    push(val) {
        // this.heap.unshift(val);
        this.heap.push(val); // this works too.
        this.heap.sort(this.compareFunc);
    }
        
    pop() {
        if (this.size === 0) return null;
        return this.heap.shift();
    }
        
    top() {
        if(this.size === 0) return null;
        return this.heap[0];
    }
        
    size() {
        return this.heap.length;
    }

    empty() {
        return this.heap.length === 0;
    }
};
