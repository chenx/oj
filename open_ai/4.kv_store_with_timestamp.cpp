#include <ctime>
#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;

/**
 * See: https://github.com/chenx/oj/blob/master/leetcode/981.TimeBasedKeyValueStore.cpp
 *
 * upper_bound returns an iterator points to the first element greater than the given value.
 * To get the floor key (for the element <= given value), decrement the iterator 
 * (when it's not at the beginning of the map, since the map elements are ordered with the
 * smallest element at the beginning).
 */
class KVStore {
    // Versioned kv-store, for given key, the last versio before given timestamp is used.
    unordered_map<string, map<int, string>> map; // <key, <timestamp, value>>

public:
    KVStore() {}
    
    void set(string key, string value, int timestamp) {
        map[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto floorKey = map[key].upper_bound(timestamp);
        // std::map<int, string>::iterator floorKey = map[key].upper_bound(timestamp);
        // if (floorKey == map[key].end()) {
        //     cout << "floorKey is end" << endl;
        // }

        if (floorKey != map[key].begin()) {
            -- floorKey;
            return floorKey->second;
        }
        return "";
    }
};


/**
 * Output:
 * Pass: get(key, 20) = value_10
 * Pass: get(key, 20) = value_15
 */
void test() {
    KVStore kvStore;

    kvStore.set("key", "value_10", 10);
    string v = kvStore.get("key", 20);
    string expect = "value_10";
    if (v == expect) {
        cout << "Pass: get(key, 20) = " << v << endl;
    } else {
        cout << "Fail: get(key, 20) = " << v << ", expect: value_10" << endl;
    }

    kvStore.set("key", "value_15", 15);
    v = kvStore.get("key", 20);
    expect = "value_15";
    if (v == expect) {
        cout << "Pass: get(key, 20) = " << v << endl;
    } else {
        cout << "Fail: get(key, 20) = " << v << ", expect: value_15" << endl;
    }
}

void testTimestamp() {
    time_t timestamp = time(nullptr); // time(NULL) also works
    cout << "Current Unix timestamp: " << timestamp << " seconds since the Epoch\n";
}

int main() {
    test();
    testTimestamp();
    return 0;
}


/**
Prompt: Organize the following into a proper interview question: Implement a time-based KV store using real timestamps. 
Specify how to write tests, mock timestamps, ensure strictly increasing timestamps, handle locks under multithreading, 
and compare lock implementations for performance. Also implement versioned KV store. Implement KVStore class supporting 
set and get, persisting to and restoring from the file system. Keys and values are strings (may contain any characters, 
including newlines). Custom serialization/deserialization must be implemented (no Python built-in libraries like json).

Follow-up questions:

- How to ensure update consistency under multithreading.
- How to handle get with a future timestamp 
  (e.g., at timestamp = 10 add "value_10", get("key", 20) should return "value_10", 
   at timestamp 15 add "value_15", then get("key", 20) should return "value_15").

Key points:
- Choose a convenient method for serialization/deserialization.
- Compare global lock vs per-key lock vs optimistic lock.
 */
