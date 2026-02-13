import bisect

class TimeMap:

    def __init__(self):
        self.map : dict[str, dict[int, str]] = {} # map<key, map<timestamp, value>>
        
    # Time: O(1)
    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.map:
            self.map[key] = {}
        self.map[key][timestamp] = value
        
    # Time: O(log(n))
    def get(self, key: str, timestamp: int) -> str:
        if not key in self.map:
            return ""

        sorted_keys = sorted(self.map[key].keys())
        upper_bound = bisect.bisect_right(sorted_keys, timestamp)
        if upper_bound > 0:
            return self.map[key][sorted_keys[upper_bound - 1]]
        else:
            return ""

        


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)

/**
981. Time Based Key-Value Store
Solved
Medium
Topics
conpanies iconCompanies

Design a time-based key-value data structure that can store multiple values for the same key at different time stamps 
and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

    TimeMap() Initializes the object of the data structure.
    void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
    String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. 
        If there are multiple such values, it returns the value associated with the largest timestamp_prev.
        If there are no values, it returns "".
 */
