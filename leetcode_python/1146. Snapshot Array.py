# Works. Most space efficient in get().
import bisect
class SnapshotArray3:

    def __init__(self, length: int):
        self.snap_id = 0
        self.arr = [[] for _ in range(length)] # each cell is a pair: [snap_id, value]
        
    def set(self, index: int, val: int) -> None:
        # avoid snap multiple times at an index if snap_id didn't change.
        if len(self.arr[index]) > 0 and self.snap_id == self.arr[index][-1][0]:
            # snap_id didn't change, just update value instead of append new item.
            self.arr[index][-1][1] = val
        else:
            self.arr[index].append( [self.snap_id, val] )
        

    def snap(self) -> int:
        self.snap_id += 1
        return self.snap_id - 1


    def get(self, index: int, snap_id: int) -> int:
        snap_index = bisect.bisect_right(self.arr[index], [snap_id, sys.maxsize])
        return self.arr[index][snap_index - 1][1] if snap_index > 0 else 0


# Also works.
# Difference: init element at each cell to [] instead of [0,0];
# then in get(), guard it with "if snap_index > 0 else 0".
import bisect
class SnapshotArray2:

    def __init__(self, length: int):
        self.snap_id = 0
        self.arr = [[] for _ in range(length)] # each cell is a pair: (val, snap_id)
        

    def set(self, index: int, val: int) -> None:
        # if len(self.arr[index]) > 0 and self.snap_id == self.arr[index][-1][0]:
        #     # snap_id didn't change, just update value instead of append new item.
        #     self.arr[index][-1][1] = val
        # else:
        self.arr[index].append( [self.snap_id, val] )
        

    def snap(self) -> int:
        self.snap_id += 1
        return self.snap_id - 1


    def get(self, index: int, snap_id: int) -> int:
        # if len(self.arr[index]) == 0:
        #     return 0
        snap_index = bisect.bisect_right(self.arr[index], [snap_id, sys.maxsize])
        return self.arr[index][snap_index - 1][1] if snap_index > 0 else 0


# From: https://leetcode.com/problems/snapshot-array/editorial/
import bisect
class SnapshotArray:

    def __init__(self, length: int):
        self.snap_id = 0
        self.arr = [[[0,0]] for _ in range(length)] # each cell is a pair: (val, snap_id)
        

    def set(self, index: int, val: int) -> None:
        self.arr[index].append( [self.snap_id, val] )
        

    def snap(self) -> int:
        self.snap_id += 1
        return self.snap_id - 1


    def get(self, index: int, snap_id: int) -> int:
        # Use binary search to find the rightmost insertion index of snapshot ID in the 
        # given version snap_index (so the target index is snap_index - 1).
        snap_index = bisect.bisect_right(self.arr[index], [snap_id, sys.maxsize])
        return self.arr[index][snap_index - 1][1]
        

# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)

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
 */
