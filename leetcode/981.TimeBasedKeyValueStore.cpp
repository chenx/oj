class TimeMap {
    unordered_map<string, map<int, string>> map; // <key, <timestamp, value>>

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        map[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        // if (! map.contains(key)) return "";
        auto floorKey = map[key].upper_bound(timestamp);
        if (floorKey == map[key].begin()) {
            return "";
        } else {
            -- floorKey;
            return floorKey->second;
        }
    }
};

/**
  To find the equivalent of Java floorKey(), one must use the upper_bound() method. upper_bound(key) 
  returns an iterator to the first element whose key is greater than the given key. To get the 
  "floor" key (less than or equal to), you must:

  - Get the upper_bound iterator.
  - If the iterator is not at the beginning of the map, decrement it to point to the element 
    immediately preceding the upper bound, which is the floor.
 */

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */


/**
981. Time Based Key-Value Store
Medium

Design a time-based key-value data structure that can store multiple values for the same key at different 
time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

    TimeMap() Initializes the object of the data structure.
    void set(String key, String value, int timestamp) Stores the key key with the value value at the given 
        time timestamp.
    String get(String key, int timestamp) Returns a value such that set was called previously, with 
        timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with 
        the largest timestamp_prev. If there are no values, it returns "".
 */
