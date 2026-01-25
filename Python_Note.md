# Python Note

## String

len(str) : get string length

str[0] : get char at index 0 of a string

str.lower() : get lower case of a string

str.isalnum() : built-in string method that checks if all characters in the string are alphanumeric (letters or numbers)


### Convert number to string

str(num)

### Convert string to number

num = '123'
int(num)

### Split string to char array

a = 'abc d'
arr = list(a) # ['a', 'b', 'c', ' ', 'd']

### Split string

Use split() function, which use ' ' as default delimiter

a = 'abc'
a.split() # ['abc']

c = 'a b'
c.split() # ['a', 'b']

c.split('a') # ['', ' b']

c.split("b") # ['a ', '']

## Initialize an array of size n with default value -1

const DP = [-1] * n


## Methods

### No list

Python does not have built-in, dedicated classes for a linked list or doubly linked list in its core library. 
However, it provides powerful, built-in data structures for the functionalities of stacks, queues, and priority queues.

### Array

In Python, lists are built-in, highly flexible data structures that can store elements of different types, 
while arrays (from the built-in array module or NumPy library) are specialized for storing homogeneous data (elements of the same type)

import array as arr
a = arr.array('i', [1,2,3])

https://www.geeksforgeeks.org/python/difference-between-list-and-array-in-python/

In Python's built-in array module, a *typecode* is a single character that specifies the homogeneous data type of elements the array will hold. This is done to store data efficiently in a compact, contiguous block of memory, similar to C-style arrays. 

https://python.readthedocs.io/fr/stable/library/array.html

### List
```
a = [1, 2, 3];

append()	Adds an element at the end of the list
pop()	Removes the element at the specified position, or last element if no position is specified

clear()	Removes all the elements from the list
copy()	Returns a copy of the list, or use: a[:]

count()	Returns the number of elements with the specified value: a.count(2) = 1

extend()	Add the elements of a list (or any iterable), to the end of the current list: b = [4]; a.extend(b) # [1,2,3,4]

index()	Returns the index of the first element with the specified value: a.idnex(3) # 2

insert()	Adds an element at the specified position: b.insert(1, 9) # [1, 9, 2, 3]
remove()	Removes the first item with the specified value

reverse()	Reverses the order of the list
sort()	Sorts the list
```

Loop through a list:
- for x in a: print(x)


#### sort array with custom comparator

intervals.sort((a, b) => { return a[0] - b[0]; });

#### Remove/replace array elements in place

The splice() method of Array instances changes the contents of an array by removing or replacing existing elements and/or adding new elements in place.

The splice() method returns an array containing the deleted elements. If no elements are removed, it returns an empty array.

```
// https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/splice
splice(start)
splice(start, deleteCount)
splice(start, deleteCount, item1)
splice(start, deleteCount, item1, item2)
splice(start, deleteCount, item1, item2, /* …, */ itemN)
```

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
