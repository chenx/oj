class LFUCache2 {
    // key: frequency, value: list of original key-value pairs that have the same frequency.
    map<int, list<pair<int, int>>> frequencies;
    // key: original key, value: iterator of key/value pair iterator in the frequencies map's list.
    map<int, pair<int, list<pair<int, int>>::iterator>> cache;
    int capacity;
    int minf; // minimum frequency.

    void insert(int key, int frequency, int value) {
        frequencies[frequency].push_back({key, value});
        cache[key] = {frequency, --frequencies[frequency].end()};
    }

public:
    LFUCache(int capacity) : capacity(capacity), minf(0) {}

    int get(int key) {
        if (! cache.contains(key)) {
            return -1;
        }
        const int f = cache[key].first;
        const auto it = cache[key].second;
        const pair<int, int> kv = *it;
        frequencies[f].erase(it);
        if (frequencies[f].empty()) {
            frequencies.erase(f);

            if (minf == f) {
                ++minf;
            }
        }

        insert(key, f + 1, kv.second);
        return kv.second;
    }

    void put(int key, int value) {
        if (cache.contains(key)) {
            cache[key].second->second = value;
            get(key);
            return;
        }
        if (capacity == cache.size()) {
            cache.erase(frequencies[minf].front().first);
            frequencies[minf].pop_front();

            if (frequencies[minf].empty()) {
                frequencies.erase(minf);
            }
        }

        minf = 1;
        insert(key, 1, value);
    }
};


class LFUCache {
    // key: frequency, value: list of original key-value pairs that have the same frequency.
    map<int, list<pair<int, int>>> frequencies;
    // key: original key, value: pair of frequency and the iterator
    // corresponding key in the frequencies map's list.
    map<int, pair<int, list<pair<int, int>>::iterator>> cache;
    int capacity;
    int minf;

    void insert(int key, int frequency, int value) {
        frequencies[frequency].push_back({key, value});
        cache[key] = {frequency, --frequencies[frequency].end()};
    }

public:
    LFUCache(int capacity) : capacity(capacity), minf(0) {}

    int get(int key) {
        const auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }
        const int f = it->second.first;
        const auto iter = it->second.second;
        const pair<int, int> kv = *iter;
        frequencies[f].erase(iter);
        if (frequencies[f].empty()) {
            frequencies.erase(f);

            if (minf == f) {
                ++minf;
            }
        }

        insert(key, f + 1, kv.second);
        return kv.second;
    }

    void put(int key, int value) {
        if (capacity <= 0) {
            return;
        }
        const auto it = cache.find(key);
        if (it != cache.end()) {
            it->second.second->second = value;
            get(key);
            return;
        }
        if (capacity == cache.size()) {
            cache.erase(frequencies[minf].front().first);
            frequencies[minf].pop_front();

            if (frequencies[minf].empty()) {
                frequencies.erase(minf);
            }
        }

        minf = 1;
        insert(key, 1, value);
    }
};


/**
460. LFU Cache
Hard

Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

    LFUCache(int capacity) Initializes the object with the capacity of the data structure.
    int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
    void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. 
        When the cache reaches its capacity, it should invalidate and remove the least frequently used key before 
        inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), 
        the least recently used key would be invalidated.

To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the 
smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter 
for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.
 */
