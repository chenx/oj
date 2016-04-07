// Should work. Not tested.
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
