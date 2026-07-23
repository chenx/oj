Let:
* \(V\) = number of unique strings/nodes
* \(E\) = number of relationships/edges
* \(N\) = number of entries in input
* \(K\) = total number of values across all `unordered_sets`

For your example:
```text
a -> b, c, d
b -> c, e
f -> g
```
There are 7 unique nodes and 6 directed relationships, although the graph for DFS has 6 undirected edges.

---

### 1. `find_group` — Union-Find

#### Building the Union-Find
```cpp
for (auto& [key, values] : input) {
    uf.add(key);
    for (string val : values) {
        uf.add(val);
        uf.get_union(key, val);
    }
}
```
There are $N$ calls to `add(key)` and $K$ calls to `add(val)` / `get_union()`.

With Union-Find using union by rank + path compression:
* `find()` amortized: $O(\alpha(V))$
* `union()` amortized: $O(\alpha(V))$

where $\alpha(V)$ is the inverse Ackermann function, effectively a constant for any practical input size.

Therefore:
$$O((V+E)\alpha(V))$$

Since $E$ is essentially the total number of relationships:
$$O((V+E)\alpha(V))$$

#### Building groups
```cpp
for (auto& [key, _] : parent_map) {
    groups[uf.find(key)].push_back(key);
}
```
There are $V$ nodes, and each `find()` is amortized $O(\alpha(V))$:
$$O(V\alpha(V))$$

So far:
$$O((V+E)\alpha(V))$$

#### Sorting each group
```cpp
for (auto& [_, values] : groups) {
    sort(values.begin(), values.end());
}
```
Suppose the connected components have sizes $s_1, s_2, \dots, s_C$. Then the sorting cost is:
$$O\left(\sum_{i=1}^{C} s_i \log s_i\right)$$

In the worst case, all $V$ nodes belong to one group:
$$O(V \log V)$$

#### Sorting result
```cpp
sort(result.begin(), result.end());
```
There can be at most $V$ groups, so the cost is roughly:
$$O(C \log C)$$

However, because each element of `result` is itself a `vector<string>`, vector lexicographical comparison can take multiple string comparisons. A more precise bound depends on string lengths and group contents.

Ignoring string comparison costs, you can think of it as approximately:
$$O(V \log V)$$

#### Overall `find_group`
The dominant terms are:
$$O((V+E)\alpha(V) + V \log V)$$

Since $\alpha(V)$ is effectively constant:
$$O(E + V \log V)$$

assuming string operations and hash operations are $O(1)$ on average.

---

### 2. `find_group_2` — DFS

First, you construct an undirected graph:
```cpp
for (auto& [key, values] : input) {
    for (string val : values) {
        graph[key].insert(val);
        graph[val].insert(key);
    }
}
```
Each relationship is processed once. Using `unordered_set`, insertion is $O(1)$ average. 

So graph construction is:
$$O(E)$$

#### DFS traversal
```cpp
dfs(key, group, used, graph);
```
Each node is visited exactly once:
```cpp
used.insert(s);
```
Each edge is examined from both directions because the graph is undirected.

Therefore:
$$O(V+E)$$

#### Sorting each group
Same as the Union-Find solution:
$$O\left(\sum_{i} s_i \log s_i\right)$$

Worst case:
$$O(V \log V)$$

#### Overall `find_group_2`
Therefore:
$$O(V + E + V \log V)$$

which simplifies to:
$$O(E + V \log V)$$

again assuming average $O(1)$ hash operations and ignoring string length.

---

### Comparison

| Solution | Graph/Group Finding | Sorting | Overall |
| :--- | :--- | :--- | :--- |
| **`find_group` (Union-Find)** | $O((V+E)\alpha(V))$ | $O(V \log V)$ | $O(E + V \log V)$ |
| **`find_group_2` (DFS)** | $O(V+E)$ | $O(V \log V)$ | $O(E + V \log V)$ |

#### Bottom line
Both have essentially the same asymptotic complexity:
$$O(E + V \log V)$$

The DFS solution is technically slightly better for one-shot connected-component detection, because it is $O(V+E)$ before sorting, while Union-Find is $O((V+E)\alpha(V))$. 

However, the difference is practically negligible because:
$$\alpha(V) \approx 1$$
