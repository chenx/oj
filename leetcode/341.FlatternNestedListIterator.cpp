// Use 2 stacks.
// See: Solution 3 at https://leetcode.com/problems/flatten-nested-list-iterator/editorial/
// N = total number of integers within the nested list, L = total number of lists within the nested list
// Time: O(L/N) or O(1). O(1) if stack top is integer. Average is O((N+L)/N) = O(L/N).
// Space: O(D). D - max depth of nested list
class NestedIterator6 {
    stack<vector<NestedInteger>> listStack;
    stack<int> indexStack;

    void makeStackTopInt() {
        while (! indexStack.empty()) {
            int index = indexStack.top();
            if (index == listStack.top().size()) {
                listStack.pop();
                indexStack.pop();
            } else {
                if (listStack.top()[index].isInteger()) {
                    break;
                }

                listStack.push(listStack.top()[index].getList());
                indexStack.top() ++; // <--!!! Avoids infinite loop
                indexStack.push(0);
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        listStack.push(nestedList);
        indexStack.push(0);
    }
    
    int next() {
        if (! hasNext()) return -1;
        int index = indexStack.top() ++;
        return listStack.top()[index].getInteger();
    }
    
    bool hasNext() {
        makeStackTopInt();
        return ! indexStack.empty();
    }
};


class NestedIterator5 {
    vector<int> list;
    int len, index;

    void flatten(vector<NestedInteger> &nestedList) {
        for (int i = 0; i < nestedList.size(); ++ i) {
            if (nestedList[i].isInteger()) {
                list.push_back(nestedList[i].getInteger());
            } else {
                flatten(nestedList[i].getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
        len = list.size();
        index = 0;
    }
    
    int next() {
        return list[index ++];
    }
    
    bool hasNext() {
        return index < len;
    }
};

// Works.
class NestedIterator4 {
    vector<int> list;
    int len, index;

    void flatten(vector<NestedInteger> &nestedList, vector<int>& list) {
        for (int i = 0; i < nestedList.size(); ++ i) {
            if (nestedList[i].isInteger()) {
                list.push_back(nestedList[i].getInteger());
            } else {
                flatten(nestedList[i].getList(), list);
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList, list);
        len = list.size();
        index = 0;
    }
    
    int next() {
        if (!hasNext()) return -1;
        return list[index ++];
    }
    
    bool hasNext() {
        return index < list.size();
    }
};

// Should work. Tested locally. XC.
class NestedIterator3 {
    stack<NestedInteger> s;

    void add(vector<NestedInteger> & nestedList) { 
        // Note: order of push is backwards!
        for (int i = nestedList.size() - 1; i >= 0; -- i)
            s.push(nestedList[i]);
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        add(nestedList);
    }

    int next() {
        if (! hasNext()) return 0;

        while (! s.top().isInteger()) {
            NestedInteger t = s.top();
            s.pop();
            add(t.getList());
        }

        int val = s.top().getInteger();
        s.pop();
        return val;
    }

    bool hasNext() {
        return ! s.empty();
    }
};


// Should work. Not tested. Use a stack.
// From: https://leetcode.com/discuss/95892/concise-c-without-storing-all-values-at-initialization
class NestedIterator2 {
private:
    stack<NestedInteger> nodes;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int size = nestedList.size();
        for (int i = size - 1; i >= 0; -- i) {
            nodes.push(nestedList[i]);
        }
    }

    int next() {
        int result = nodes.top().getInteger();
        nodes.pop();
        return result;
    }
    
    bool hasNext() {
        while(! nodes.empty()) {
            NestedInteger curr = nodes.top();
            if (curr.isInteger()) {
                return true;
            }
    
            nodes.pop();
            vector<NestedInteger>& adjs = curr.getList();
            int size = adjs.size();
            for (int i = size - 1; i >= 0; -- i) {
                nodes.push(adjs[i]);
            }
        }
    
        return false;
    }
};

// Should work. Tested locally.
// Flattern the nestedList into a vector in constructor.
// See: http://massivealgorithms.blogspot.com/2016/04/leecode-341-flatten-nested-list-iterator.html
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        ans.clear();
        idx = 0;
        dfs(nestedList);
    }

    int next() {
        return ans[idx ++];
    }

    bool hasNext() {
        return idx < ans.size();
    }

private:
    void dfs(vector<NestedInteger> &nestedList){
        int n = nestedList.size();
        for (int i = 0; i < n; ++ i){
            if (nestedList[i].isInteger()) 
                ans.push_back(nestedList[i].getInteger());
            else 
                dfs(nestedList[i].getList());
        }
    }

    vector<int> ans;
    int idx;
};


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
 
 /**
  * Your NestedIterator object will be instantiated and called as such:
  * NestedIterator i(nestedList);
  * while (i.hasNext()) cout << i.next();
  */
 
 /**
 Flatten Nested List Iterator 
 Difficulty: Medium
 
 
  */
