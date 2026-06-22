// See https://leetcode.com/problems/snapshot-array/editorial/
// Similar to https://leetcode.com/problems/time-based-key-value-store/
// Use upper_bound function of map.
// Time for n set/get: O(nlogn + k). k = store.length, n = number of calls to set.
// Space: O(n + k)
class SnapshotArray {
    vector<map<int, int>> store; // map<snap_id, value>
    int snap_id;
public:
    SnapshotArray(int length) : store(vector<map<int, int>>(length)), snap_id(0) {
        
    }
    
    void set(int index, int val) {
        store[index][snap_id] = val;
    }
    
    int snap() {
        return snap_id ++;
    }
    
    int get(int index, int snap_id) {
        auto it = store[index].upper_bound(snap_id);
        if (it == store[index].begin()) {
            return 0;
        } else {
            -- it;
            return it->second;
        }
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

/**
1146. Snapshot Array
Solved
Medium
Topics
conpanies iconCompanies
Hint

Implement a SnapshotArray that supports the following interface:

    SnapshotArray(int length) initializes an array-like data structure with the given length. Initially, each element equals 0.
    void set(index, val) sets the element at the given index to be equal to val.
    int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
    int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id

 

Example 1:

Input: ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
Output: [null,null,0,null,5]
Explanation: 
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array[0] = 5
snapshotArr.snap();  // Take a snapshot, return snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5
 */
