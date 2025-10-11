// Sorted Map + Binary Search
// Time: set: O(L⋅M⋅logM), get: O(N⋅(L⋅logM+logM)).
// Space: set: O(M⋅L), set: O(1)
//
// java.util.TreeMap: floorKey() and ceilingKey()
// floorKey(key):
//     Returns the greatest key in the map <= the given key, or null otherwise.
// ceilingKey(key):
//     Returns the least key >= the given key, or null otherwise.
class TimeMap {
    HashMap<String, TreeMap<Integer, String>> map;

    public TimeMap() {
        map = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        if (map.get(key) == null) {
            map.put(key, new TreeMap<Integer, String>());
        }
        map.get(key).put(timestamp, value);
    }
    
    public String get(String key, int timestamp) {
        if (!map.containsKey(key)) return "";
        Integer floorKey = map.get(key).floorKey(timestamp);
        if (floorKey != null) {
            return map.get(key).get(floorKey);
        } 
        return "";
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */

/**
981. Time Based Key-Value Store

Design a time-based key-value data structure that can store multiple values for the same key 
at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

    TimeMap() Initializes the object of the data structure.
    void set(String key, String value, int timestamp) Stores the key key with the value value 
        at the given time timestamp.
    String get(String key, int timestamp) Returns a value such that set was called previously, 
        with timestamp_prev <= timestamp. If there are multiple such values, it returns the value 
        associated with the largest timestamp_prev. If there are no values, it returns "".
 */
