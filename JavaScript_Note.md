# JavaScript Note

## String

str.length (Java: str.length())

str.charAt()

str.toLowerCase()

There is no isAlnum(), need to define yourself.

var isAlnum = (c) => {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

### Convert number to string

num.toString()

### Convert stringi to number

1) parseInt()
   - let num = parseInt(str);
   - let hexInt = parseInt('0xF', 16);

2) Number() or +
   - let num = Number(1.23);
   - let num2 = +'1.23';

3) Math.floor(), Math.ceil(), or Math.round()

Use parseInt() when you need to extract an integer from a string that might contain 
non-numeric characters after the initial number (e.g., "100px").

Use Number() or the unary plus operator (+) when you expect the entire string to 
represent a valid number, and you want to convert it, potentially including decimal values.


### Split string to char array

const arr = str.split('');

## Initialize an array of size n with default value -1

const DP = new Array(n).fill(-1);


## Methods

### No list

Javascript has no built-in data structure of linked list, doubly linked list, stack, queue or priority_queue.

Linked list, stack and queue can be mimicked by Array.

DLL and priority queue have to be implemented.

### Array
```
const list = [];
const list = new Array();

push(), pop()
unshift(), shift()
splice()
slice()
includes()
length
```

Loop through an array:
- for (const n of arr)
- arr.forEach()

#### sort array with custom comparator

intervals.sort((a, b) => { return a[0] - b[0]; });

### Map

```
const map = new Map();
set(k,v)
has(k)
get(k)
delete(k)
clear()
size

// iterate through map entries
for (const [key, value] of map.entries()) {}

// Initialize with values
const entries = [['{', '}'], ['[', ']'], ['(', ')']];
const map = new Map(entries);
```

### Set

```
const set = new Set()
add(v)
has(v)
delete(v)
clear()
size
```

get first value: set.values().next().value

### Sort

```
function(intervals) {
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
```
