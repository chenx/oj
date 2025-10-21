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

const list = [];
const list = new Array();

push(), pop()
unshift(), shift()
splice()
slice()
includes()
length

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

