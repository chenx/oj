# Union Find (Disjoint set) 

https://en.wikipedia.org/wiki/Disjoint-set_data_structure

## Implementation

```
// Time: O(m * alpha(n)) for m operations, n elements. alpha(n): reverse ackerman function =~ 1
// Space: O(n)
class UnionFind {
public:
  void add(int x) {  // O(1)
    if (parent.contains(x)) return;
    
    parent[x] = x;
    rank[x] = 0;
  }

  // original, recursive version.
  // Time: O(alpha(n)) =~ O(1)
  int find(int x) {  // O(alpha(n))
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  // iterative version.
  // Time: O(alpha(n)) =~ O(1)
  int find2(int x) {  // O(alpha(n))
    while (parent[x] != x) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return parent[x];
  }
  
  // This does path halving, so it is valid, but it doesn't explicitly update x or fully compress the path.
  // It still works with union-by-rank and gives the standard near-constant amortized complexity.
  int find_not_good(int x) {  // O(alpha(n))
    while (parent[x] != parent[parent[x]]) {
      parent[x] = parent[parent[x]];
    }
    return parent[x];
  }

  // Time: O(alpha(n)) =~ O(1)
  void get_union(int x, int y) {  // O(alpha(n))
    x = find(x);
    y = find(y);
    if (x == y) return;

    int rx = rank[x], ry = rank[y];
    if (rx < ry) {
      parent[x] = y;
    } else if (ry < rx) {
      parent[y] = x;
    } else {
      parent[y] = x;
      ++ rank[x];
    }
  }

  const unordered_map<int, int>& get_parent_map() const {
    return parent;
  }

private:
  unordered_map<int, int> parent;
  unordered_map<int, int> rank;
};
```

## Implementation of the Find() function

If you're comparing these three implementations:

* Your original version
* Standard iterative path halving
* Recursive full path compression

then the answer is: for practical C++ code, standard iterative path halving is usually the best balance of performance and simplicity.

### Comparison

| Implementation | Path technique | Recursion | Performance | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **Your version** | Repeatedly compresses one node | No | Very good | Only modifies the queried node |
| **Iterative path halving** | Path halving | No | Excellent | Usually my recommendation |
| **Recursive** | Full path compression | Yes | Excellent | Very clean, but function-call overhead |

### 1. Your implementation

```cpp
string find(string x) {
    while (parent[x] != parent[parent[x]]) {
        parent[x] = parent[parent[x]];
    }
    return parent[x];
}
```

This repeatedly moves only `x` upward:

```text
a -> b -> c -> d -> e -> f
a -> c -> e -> f
a -> e -> f
a -> f
```

* **The advantage:** It is iterative and can quickly move the queried node to the root.
* **The downside:** It doesn't compress the intermediate nodes `c` and `e`. If those nodes are queried later, they may still have longer paths.

### 2. Iterative path halving

```cpp
string find(string x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
```

This modifies nodes as it walks up:

```text
a -> b -> c -> d -> e -> f

a -> c -> d -> e -> f
     ↓
a -> c -> e -> f
         ↓
a -> c -> e -> f
```

The important benefit is that it compresses the path for multiple nodes encountered during traversal, not just the original node.

It's also:
* Iterative
* No recursion overhead
* Very simple
* Excellent cache behavior
* \(O(\alpha(V))\) amortized with union by rank/size

This would be my choice for performance-oriented C++.

### 3. Recursive full path compression

```cpp
string find(const string& x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
```

This produces stronger compression:

**Before:**
```text
a -> b -> c -> d -> e -> f
```

**After `find(a)`:**
```text
a ─┐
b ─┤
c ─┤
d ─┤──> f
e ─┘
```

So future queries are extremely fast.

However, it uses recursive function calls. With Union-Find's union-by-rank/size, trees are already very shallow, so stack overflow isn't normally a concern, but there is still function-call overhead.

### My recommendation

For your code, I'd use:

```cpp
string find(string x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
```

Combined with:

```cpp
if (rank[rootX] > rank[rootY]) {
    parent[rootY] = rootX;
} else if (rank[rootX] < rank[rootY]) {
    parent[rootX] = rootY;
} else {
    parent[rootY] = rootX;
    rank[rootX]++;
}
```

You get \(O(\alpha(V))\) amortized per operation, which is effectively constant time.

### One caveat

In your specific code, you're using string keys:

```cpp
unordered_map<string, string> parent;
```

The string copying and hashing may cost significantly more than the difference between path halving and full path compression.

For example, this snippet copies the string into `x`:
```cpp
string find(string x)
```

A potentially better approach is to use integer IDs internally:
```text
"a" -> 0
"b" -> 1
"c" -> 2
```

and then Union-Find operates on:
```cpp
vector<int> parent;
vector<int> rank;
```

That will generally be much faster than optimizing the difference between these `find()` implementations.

So, for your specific application, I'd rank the optimizations roughly as:

```text
Integer-based Union-Find
        ↓
Union by rank/size
        ↓
Iterative path halving
        ↓
Reserve unordered_map capacity
```

These will matter much more than choosing between iterative path halving and recursive full path compression.
