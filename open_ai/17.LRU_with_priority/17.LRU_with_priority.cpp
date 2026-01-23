// 12:05 - 12:54
/**
Design and implement a basic Least Recently Used (LRU) cache with the following methods: 
void addKey(string key) int getCountForKey(string key) 
Additionally, maintain a max heap to record all entries with a specific priority. 
Discuss how you would handle changes in priority.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    string key;
    int priority;

    Node(string key) : key(key), priority(1) {}

    void add() {
        ++ priority;
    }

    bool operator<(Node& node) const {
        if (priority != node.priority) {
            return priority < node.priority;
        } 
        return key < node.key;
    }
};

class MaxHeap {
    vector<Node> arr;
    unordered_map<string, int> cache; // <key, pos in arr>

    int getParent(int pos) {
        return (pos - 1)/2;
    }

    void heapify(int pos) {
        // cout << "heapify: pos=" << pos << endl;
        int parent = getParent(pos);
        while (pos > 0 && arr[parent] < arr[pos]) {
            swap(arr[pos], arr[parent]);
            swap(cache[arr[pos].key], cache[arr[parent].key]);

            pos = getParent(pos);
        }
    }

public:
    void addKey(string key) {
        if (cache.count(key)) {
            arr[cache[key]].add();
            heapify(cache[key]);
        } else {
            arr.push_back(Node(key));
            int pos = arr.size() - 1;
            cache[key] = pos;
            // heapify(pos); // No need since it's priority 1 is the smallest.
        }
    }

    int getCountForKey(string key) {
        return arr[cache[key]].priority;
    }

    string top() {
        if (arr.size() == 0) return "";
        return arr[0].key;
    }

    void dump() {
        int count = 0;
        for (auto& node : arr) {
            cout << count ++ << ": " << node.key << ", " << node.priority << endl;
        }
        cout << endl;
    }
};

class LRU {
    MaxHeap maxHeap;

public:
    void addKey(string key){
        maxHeap.addKey(key);
    }

    string top() {
        return maxHeap.top();
    }
    
    int getCountForKey(string key) {
        return maxHeap.getCountForKey(key);
    }

    void dump() {
        maxHeap.dump();
    }
};


class LRUTest {
    void test1() {
        cout << "hi" << endl;
        LRU lru;

        lru.addKey("a");
        lru.addKey("b");
        lru.addKey("c");
        cout << "lru.top = " << lru.top() << endl;
        lru.dump();

        lru.addKey("b");
        lru.addKey("b");
        cout << "lru.top = " << lru.top() << endl;
        lru.dump();

        lru.addKey("a");
        cout << "lru.top = " << lru.top() << endl;
        lru.dump();

        lru.addKey("a");
        lru.dump();
        lru.addKey("a");
        cout << "lru.top = " << lru.top() << endl;
        lru.dump();

        cout << "a.count = " << lru.getCountForKey("a") << endl;
        cout << "a.count = " << lru.getCountForKey("a") << endl;
        cout << "b.count = " << lru.getCountForKey("b") << endl;
        cout << "b.count = " << lru.getCountForKey("b") << endl;
    }
public:
    void run_tests() {
        test1();
    }
};

int main() {
    LRUTest test;
    test.run_tests();
    return 0;
}

/**
3. Heapify
Heapify is the process of rearranging the elements in a binary tree (often represented as an array) 
to maintain the heap property. 

    Down-Heapify (Sink Down): Used when a node is smaller than its children (in max-heap) or larger 
            than its children (in min-heap). The node is swapped with its largest child (max-heap) 
            or smallest child (min-heap) and moves down the tree.
    Up-Heapify (Bubble Up): Used during insertion to move a new element up to its correct position. 

4. Building a Heap (Complexity: O(n))
 */
