# Union Find

## Version 1

```
class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
    
    def find(self, i):
        while self.parent[i] != self.parent[self.parent[i]]:
            i = self.parent[i]
        return self.parent[i]
        # if i == self.parent[i]:
        #     return i
        # return self.find(self.parent[i])

    def union(self, i, j) -> bool:
        a = self.find(i)
        b = self.find(j)
        self.parent[a] = b
```

## Version 2

```
class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [1 for _ in range(n)]
    
    def find(self, i):
        while self.parent[i] != self.parent[self.parent[i]]:
            i = self.parent[i]
        return self.parent[i]
        # if i == self.parent[i]:
        #     return i
        # return self.find(self.parent[i])

    def union(self, i, j) -> bool:
        a = self.find(i)
        b = self.find(j)

        if a == b:
            return False

        if self.rank[a] > self.rank[b]:
            self.parent[b] = a
            self.rank[a] += self.rank[b]
        else:
            self.parent[a] = b
            self.rank[b] = self.rank[a]
```

## Version 3

```
class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [1 for _ in range(n)]
    
    def find(self, i):
        while self.parent[i] != self.parent[self.parent[i]]:
            i = self.parent[i]
        return self.parent[i]
        # if i == self.parent[i]:
        #     return i
        # return self.find(self.parent[i])

    def union(self, i, j) -> bool:
        a = self.find(i)
        b = self.find(j)

        if a == b:
            return False

        if self.rank[a] > self.rank[b]:
            self.parent[b] = a
        elif self.rank[b] > self.rank[a]:
            self.parent[a] = b
        else:
            self.parent[b] = a
            self.rank[a] += 1
```
