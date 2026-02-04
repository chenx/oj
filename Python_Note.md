# Python Note

## Define 2D array

```
board = [[11,12,13], [21,22,23]]
m, n = len(board), len(board[0])

TwoDArray1 = [[0] * n] * m  # m*n 2D array
TwoDArray2 = [[0] * n for i in range(m)]  # m*n 2D array

print(f"TwoDArray1: {TwoDArray1}")
print(f"TwoDArray2: {TwoDArray2}")

grid = [[0 for _ in range(n)] for _ in range(m)]
print(f"TwoDGrid: {grid}")

# TwoDArray1: [[0, 0, 0], [0, 0, 0]]
# TwoDArray2: [[0, 0, 0], [0, 0, 0]]
# TwoDGrid: [[0, 0, 0], [0, 0, 0]]
```

## number

Instead of INT_MIN and INT_MAX in C++, there is no limit of number size.

If need a meaning value similar to INT_MIN and INT_MAX, do this:

```
import sys

rint(f'minsize = {-sys.maxsize - 1}, maxsize={sys.maxsize}')
# minsize = -9223372036854775808, maxsize=9223372036854775807
```

## String

len(str) : get string length

str[0] : get char at index 0 of a string

str.lower() : get lower case of a string

str.isalnum() : built-in string method that checks if all characters in the string are alphanumeric (letters or numbers)

str[start: start+len] : Substring, same as str.substr(start, len) in C++

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

- https://www.w3schools.com/python/ref_list_sort.asp
- https://docs.python.org/3/howto/sorting.html

list.sort(reverse=True|False, key=myFunc) 

##### sort list with lambda

Sort the list in place based on the second element (marks):

subject_marks.sort(key=lambda x: x[1])

```
# E.g., for intervals.sort((a, b) => { return a[0] - b[0]; });
# In Python this is:
>>> c
[[1, 2], [2, 3], [0, 4]]
>>> c.sort(key=lambda x : x[0])
>>> c
[[0, 4], [1, 2], [2, 3]]
>>> c.sort(key=lambda x : x[1])
>>> c
[[1, 2], [2, 3], [0, 4]]
```

##### list.sort() vs sorted()

The primary difference is that list.sort() sorts a list in-place and returns None, while sorted() creates and returns a new sorted list from any iterable, leaving the original data unchanged. 

list.sort()

- Modifies in-place: It directly changes the original list object.
- Return value: It returns None. A common mistake is to try and assign the result to a new variable (e.g., new_list = old_list.sort()), which will result in new_list being None.
- Applicability: It is a method of the list class, so it can only be used with lists.
- Memory/Performance: It is slightly more efficient in terms of memory and performance for lists because it doesn't have to create a new list object. 

sorted()

- Does not modify original: It creates and returns a new sorted list, leaving the original iterable unchanged.
- Return value: It returns a new list object, which you typically assign to a variable.
- Applicability: It is a built-in function that accepts any iterable (lists, tuples, strings, dictionaries, sets, etc.), not just lists.
- Memory/Performance: It has a slight performance and memory overhead due to the creation of a new list. 

```
result.sort(key=lambda x : x[index], reverse=rev);

# OR USE:
from operator import itemgetter;

result.sort(key=itemgetter(index), reverse=rev);
```

### Map

https://docs.python.org/3/tutorial/datastructures.html#dictionaries

Use {}, dict(), or OrderedDict().

```
map = {}

set/add/insert:
map[key] = value

get:
map.get(key, None)

has/contains:
key in map 

delete:
del map[key] 
map.pop(key) 

clear:
map.clear()

size:
len(map)

loop:
for key, val in map:
  print(key)
```

Unordered:
```
>>> a = {} # an empty dictionary
>>> dict([('sape', 4139), ('guido', 4127), ('jack', 4098)])
{'sape': 4139, 'guido': 4127, 'jack': 4098}
>>> dict({'sa': 3, 'dg': 4})
{'sa': 3, 'dg': 4}
```

Ordered:
```
>>> from collections import OrderedDict;
>>> m = {"A1" : [1,2], "B3" : [3], 'C': [0]}
>>> m = OrderedDict(sorted(m.items(), key = lambda t : t[0]))
>>> m
OrderedDict({'A1': [1, 2], 'B3': [3], 'C': [0]})
>>> m = OrderedDict(sorted(m.items(), key = lambda t : t[1]))
>>> m
OrderedDict({'C': [0], 'A1': [1, 2], 'B3': [3]})
>>> m = OrderedDict(sorted(m.items(), key = lambda t : t[0], reverse=True))
>>> m
OrderedDict({'C': [0], 'B3': [3], 'A1': [1, 2]})

for k, v in m.items():
    print(k, v)

for k in m.keys(): 
    print(k)

for v in m.keys(): 
    print(v)
```

Increase the value of a map item:
```
m = {}
m[x] = m.get(x, 0) + 1
# m.get(x, 0) return 0 if x does not exist in m
```

### Set

https://docs.python.org/3/tutorial/datastructures.html#sets

Curly braces {} or the set() function can be used to create sets. 
Note: to create an empty set you have to use set(), not {}; the latter creates an empty dictionary.

```
set1 = set()

set/add/insert:
set1.add(key)

has/contains:
key in set1 

delete:
set1.remove(key)
set1.pop() # removes random member

clear:
set1.clear()

size:
len(set1)

loop:
for x in set1:
  print(x)
```

```
basket = {'apple', 'orange', 'apple', 'pear', 'orange', 'banana'}
print(basket)  # {'orange', 'banana', 'pear', 'apple'}

a = set('abracadabra')
a                                  # unique letters in a
{'a', 'r', 'b', 'c', 'd'}

for i in a:
    print(i)
```

get first value: set.values().next().value

### Stack

Example of using a list as a stack

```
stack = []
stack.append('a') # Push
stack.append('b') # Push
print(stack.pop()) # Pop, outputs 'b'
print(stack.pop()) # Pop, outputs 'a'
```

### Queue

Example of using deque as a queue

```
from collections import deque

queue = deque(["apple", "banana", "cherry"])

queue.append("date") # Enqueue
queue.pop() # pops 'date'

print(queue.popleft()) # Dequeue, outputs 'apple'
print(queue.popleft()) # Dequeue, outputs 'banana'
queue.appendleft('a') # adds 'a' to the beginning

q[0]  # similar to q.front()
q[-1] # similar to q.back()
```

### priority queue

```
import heapq

# Example of using heapq as a priority queue
# Elements are stored as tuples (priority, value)
priority_queue = []
heapq.heappush(priority_queue, (2, 'medium_priority'))
heapq.heappush(priority_queue, (1, 'high_priority'))
heapq.heappush(priority_queue, (3, 'low_priority'))

# Elements are popped in order of priority (lowest number first)
print(heapq.heappop(priority_queue)) # Outputs (1, 'high_priority')
print(heapq.heappop(priority_queue)) # Outputs (2, 'medium_priority')
print(heapq.heappop(priority_queue)) # Outputs (3, 'low_priority')
```

Max heap (Python 3.14) native max heap:

```
import heapq

# Initialize an empty list to act as the max heap
max_heap = []

# Push items onto the max heap
heapq.heappush_max(max_heap, 10)
heapq.heappush_max(max_heap, 30)
heapq.heappush_max(max_heap, 20)
heapq.heappush_max(max_heap, 5)

# The largest element is at index 0 (the root)
print(f"Largest element (peek): {max_heap[0]}")

# Pop the largest element
largest = heapq.heappop_max(max_heap)
print(f"Popped largest element: {largest}")
print(f"Heap after pop: {max_heap}")

# Convert an existing list into a max heap in-place
data = [4, 7, 2, 8, 1, 3]
heapq.heapify_max(data)
print(f"Heapified max heap: {data}")
```

Also can use heappush and heappop for or max heap, use negative value for each element of the heap

```
maxHeap = []
heapq.heappush(priority_queue, (-2, 'medium_priority'))
heapq.heappush(priority_queue, (-1, 'high_priority'))
heapq.heappush(priority_queue, (-3, 'low_priority'))

print(heapq.heappop(priority_queue))  # (-3, 'low_priority')
print(heapq.heappop(priority_queue))  # (-2, 'medium_priority')
print(heapq.heappop(priority_queue))  # (-1, 'high_priority')
```

#### order property of priority queue element

A "<" relationship is needed between priority queue elements.

This should be enough using a tuple where the first element is used for comparison.

Sometimes, like in leetcode editor, or if comparison is complex, define a node, e.g.,

```
class HeapNode:
    def __init__(self, node: ListNode):
        self.node = node
    
    def __lt__(self, other):
        return self.node.val < other.node.val
```


### copy (shallow and deep)

```
import copy

a = [[1], 2]
shallow_copy = copy.copy(a)
deep_copy = copy.deepcopy(a)
```

### deque

```
from collections import deque;

q = deque()
link = q.popleft();
```

### print 2D grid

```
# Need to define __str__ of Cell

for row in self.cells:
    print(*row) ;
```

### Initialize <string, map<>>

```
self.tables = {table: {} for table in table_names}  # <tableName, map<rowId, row[]>>
```

### heap

```
import heapq;

heapq.heappush(self.minHeap, (expire, [timestamp, amount, expire]))
```

### Array insert/pop

```
a = []
a.pop(i)
a.nsert(i, Node)
```

### Iterator

```
raise StopIteration("end of iterator")

try:
    pass
except StopIteration as e:
    print(f"Exception: {e}")
 iter: return self
```

### isinstance

```
# All return true
print(f"isinstance(1, int): {isinstance(1, int)}")
print(f"isinstance(a, str): {isinstance("a", str)}")
print(f"isinstance([1,2,3], list): {isinstance([1,2,3], list)}")
print(f"isinstance((4,5,6), tuple): {isinstance((1,2,3), tuple)}")
```

### Type declaration in Python3

```
self.tables : dict[str, dict[int, list[str]]] = {table: {} for table in table_names}  # <tableName, map<rowId, row[]>>
self.table_max_id : dict[str, int] = {table : 0 for table in table_names} # <tableName, row_max_id>
self.table_columns : dict[str, list[str]] = {}  # <tableName, columns[]>
self.table_column_index : dict[str, dict[str, int]] = {}  # <tableName, map<columnName, index>>
```

### Ways to share variable between function call (alternative to pass by reference in C++)

Method 1: as class instance variable:  self.var

Method 2: nonlocal var

```
Purpose

By default, when a function assigns a value to a variable, Python treats that variable as local
to the current function's scope, even if a variable with the same name exists in an outer scope.
The nonlocal keyword overrides this default behavior, telling Python to use the variable from
the enclosing scope instead.

How to Use nonlocal

The nonlocal keyword must be used inside a nested function and the variable it references must
already exist in a non-global enclosing scope.
```

Method 3: pass as a list of one element: param = [var], can access the var sa param[0]

### min, max, sum

All apply to lists, not just 2 numbers

### conversion between int and char

char to int: ord('A')
int to char: chr(65) # 'A'

### Replace a char at index i in array

two ways:

```
# method 1
i = 1
a = a[:i] + 'd' + a[i+1:]

# method 2
b = list(a)
b[i] = "d"
a = "".join(b)
```

### list.sort vs sorted

```
Feature 	     list.sort()	                      sorted()
Behavior	     Sorts in-place (mutates original)	Returns a new sorted list
Return Value	 None	                            A new list
Applicability  Lists only	                      Any iterable (list, tuple, dict, etc.)
Original Data	 Modified	                        Unchanged
Memory Usage	 More memory-efficient	            Less memory-efficient (creates a copy)
```

### OrderedDict

The OrderedDict implementation is a hybrid data structure designed to provide the benefits of both a hash table (for fast lookups) and a sequence (for ordered iteration). It achieves this by combining three internal components: 

- The Dictionary Itself: OrderedDict is a dict subclass, so the object itself stores the key-value pairs, providing O(1) average time complexity for standard dictionary operations like __getitem__, __setitem__, __contains__, and __delitem__.
- A Doubly Linked List: This structure stores the keys in the sequence they were inserted. Each node (link) in the list represents a key's position.
- A Key-to-Node Map: A secondary internal dictionary (often named self.__map in the source code) maps each key to its corresponding node in the doubly linked list. This allows for constant-time (O(1)) access to a specific node when an item needs to be deleted or moved, without having to traverse the linked list linearly. A sentinel node is used to simplify the linked list algorithm.

```
# In a Python OrderedDict, the items are stored and iterated over in the order in which their keys were first inserted.
#
# The popitem() method for Dict: remove the last (inserted) time. LIFO.
#
# The popitem() method for a Python OrderedDict removes and returns a (key, value) pair. 
# Unlike a standard dictionary's popitem(), it accepts a last parameter (a boolean) to 
# control the order of removal. True - remove last (LIFO), False - remove first (FIFO).
```

### sortedcontainers: SortedList, SortedSet, SortedDict

The **sortedcontainers** Python library's **SortedList** uses a segmented-list data structure that is similar to a B-tree, 
but limited to two levels of nodes. This approach leverages the high performance of Python's built-in list operations 
while providing efficient O(log n) time complexity for most operations.

The **sortedcontainers.SortedSet** in Python is a wrapper around the SortedList data structure. 
The SortedList itself is implemented using a segmented list (similar to a B-tree limited to two levels of nodes), 
not a traditional balanced binary search tree or a simple Python set with a sorted list.

The **sortedcontainers.SortedDict** in Python is a hybrid data structure that internally uses a combination of a 
standard Python dictionary and a balanced tree-like structure (specifically, a segmented list with two levels 
of nodes, similar to a B-tree) to maintain efficient operations while keeping keys sorted. 

### Inner function

Inner function can access variables of the outer function.
```
>>> def outer_func(outer_arg):
...     local_var = "Outer local variable"
...     def closure():
...         print(outer_arg)
...         print(local_var)
...         print(another_local_var)
...     another_local_var = "Another outer local variable"
...     return closure
...

>>> closure = outer_func("Outer argument")

>>> closure()
Outer argument
Outer local variable
Another outer local variable
```

### Python closure

https://realpython.com/python-closure/

To create a Python closure, you need the following components:

- An outer or enclosing function: This is a function that contains another function, often referred to as the inner function. The outer function can take arguments and define variables that the inner function can access and update.

- Variables that are local to the outer function: These are variables from its enclosing scope. Python retains these variables, allowing you to use them in the closure, even after the outer function has returned.

- An inner or nested function: This is a function defined inside the outer function. It can access and update the variables from the outer function even after the outer function has returned.

```
>>> def make_counter():
...     count = 0
...     def counter():
...         nonlocal count
...         count += 1
...         return count
...     return counter
...

>>> counter = make_counter()

>>> counter()
1
>>> counter()
2
```

### defaultdict

A **defaultdict** is a subclass of the Python dictionary (dict) in the {Link: collections https://docs.python.org/3/library/collections.html} module that automatically initializes a default value for non-existent keys, preventing KeyError exceptions. It uses a default_factory callable (e.g., list, int, set) to generate these values, simplifying code for counting, grouping, and initializing nested dictionaries.

```
from collections import defaultdict

map = defaultdict(int) # need "int" to know the default value is 0.
map['a'] += 1
print(map['a']) # 1
```

An example using the dict class for comparison:
```
map = {}
if 'a' not in map: map['a'] = 0 # need this to avoid key error
map['a'] += 1
print(map['a']) # 1
```

### Lock

```
from threading import Lock

class Test:
  def __init__(self):
    self.lock = Lock()

  def read(self):
    with self.lock:
      pass
  
  def write(self):
    with self.lock:
      pass
```

Read-Write lock:
https://charemza.name/blog/posts/python/asyncio/read-write-lock/

A read/write lock is made of of two parts: a read lock and a write lock. The read lock can be acquired by multiple tasks concurrently, but only as long as no task holds the write lock; and a write lock can only be acquired if no tasks hold the read lock and no task holds the write lock.

