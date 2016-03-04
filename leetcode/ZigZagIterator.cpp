// Works. Tested. By: XC
// This works for any number of input vectors.
class ZigzagIterator3 {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        v.push_back(v1);
        v.push_back(v2);
        index.push_back(0);
        index.push_back(0);
        
        SIZE = v.size();
        for (cur = 0; cur < SIZE; ++ cur) {
            if (index[cur] < v[cur].size()) break;
        }
        
        if (cur == SIZE) cur = 0; // if comment out this, it works too.
    }

    int next() {
        if (! hasNext()) return -1;
        int val = v[cur][index[cur]];
        index[cur] ++;
        
        int cur0 = cur;
        // for (++ cur; ; ++ cur) { // this works too.
        for (++ cur; cur != cur0; ++ cur) { 
            if (cur == SIZE) cur = 0;
            if (cur == cur0) break;
            if (index[cur] < v[cur].size()) break;
        }
        
        return val;
    }

    bool hasNext() {
        if (cur == SIZE) cur = 0;
        if (index[cur] < v[cur].size()) return true;
        return false;
    }
    
private:
    vector<vector<int>> v; // a cycle array for vectors.
    vector<int> index;     // a cycle array for index
    int cur;               // index of current element in array
    int SIZE;              // number of vectors.
};


// Works. Tested. By: XC.
// Idea: pre-process v1 and v2 into a combined vector v.
class ZigzagIterator2 {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        v.resize(v1.size() + v2.size());

        int p1 = 0, p2 = 0, k = 0;
        bool useP1 = true;
        while (p1 < v1.size() && p2 < v2.size()) {
            v[k ++] = useP1 ? v1[p1 ++] : v2[p2 ++];
            useP1 = ! useP1;
        }
        while (p1 < v1.size()) {
            v[k ++] = v1[p1 ++];
        }
        while (p2 < v2.size()) {
            v[k ++] = v2[p2 ++];
        }
        
        index = 0;
    }

    int next() {
        if (! hasNext()) return -1;
        return v[index ++];
    }

    bool hasNext() {
        return index < v.size();
    }
    
private:
    vector<int> v;
    int index;
};


// Works. Tested. By: XC.
// Idea: switch to use v1 or v2.
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        this->v1 = v1;
        this->v2 = v2;
        p1 = p2 = 0;
        useP1 = (p1 < v1.size()) ? true : false; // true - use p1, false - use p2.
    }

    int next() {
        if (! hasNext()) return -1;
        if (useP1) {
            int v = v1[p1 ++];
            useP1 = (p2 < v2.size()) ? false : true;
            return v;
        }
        else {
            int v = v2[p2 ++];
            useP1 = (p1 < v1.size()) ? true : false;
            return v;
        }
    }

    bool hasNext() {
        return p1 < v1.size() || p2 < v2.size();
    }
    
private:
    vector<int> v1, v2;
    int p1, p2;
    bool useP1;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
 
/**
Zigzag Iterator
Difficulty: Medium

Given two 1d vectors, implement an iterator to return their elements alternately.

For example, given two 1d vectors:

v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order 
of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your 
code be extended to such cases?

Clarification for the follow up question - Update (2015-09-18):
The "Zigzag" order is not clearly defined and is ambiguous for 
k > 2 cases. If "Zigzag" does not look right to you, replace 
"Zigzag" with "Cyclic". For example, given the following input:

[1,2,3]
[4,5,6,7]
[8,9]
It should return [1,4,8,2,5,9,3,6,7].
  */
