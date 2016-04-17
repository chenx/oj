class Solution {
public:
    /* you may need to use some attributes here */
    vector<int> base;
    vector<long long> BIT;
    void add(int i, long long v) {
        for (; i <= base.size() + 1; i += (i & -i)) 
            BIT[i] += v;
    }
    long long sum(int i) {
        long long s = 0;
        for (; i > 0; i -= (i & -i))
            s += BIT[i];
        return s;
    }

    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        // write your code here
        base = A;
        BIT.resize(A.size() + 1, 0);
        for (int i = 0; i < base.size(); ++ i) 
            add(i + 1, base[i]);
    }
    
    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        // write your code here
        return sum(end + 1) - sum(start);
    }
    
    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        // write your code here
        add(index + 1, value - base[index]);
        base[index] = value;
    }
};


/**
 Interval Sum II

Given an integer array in the construct method, implement two methods 
query(start, end) and modify(index, value):

    For query(start, end), return the sum from index start to index end in the given array.
    For modify(index, value), modify the number in the given index to value

Notice

We suggest you finish problem Segment Tree Build, Segment Tree Query and Segment Tree Modify first.
Example

Given array A = [1,2,7,8,5].

    query(0, 2), return 10.
    modify(0, 4), change A[0] from 1 to 4.
    query(0, 1), return 6.
    modify(2, 1), change A[2] from 7 to 1.
    query(2, 4), return 14.

Challenge

O(logN) time for query and modify.

 */
