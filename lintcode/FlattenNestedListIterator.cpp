/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    //vector<NestedInteger> base;
    vector<int> base;
    int index;
    
    void getBase(vector<NestedInteger> &nestedList) {
        for (int i = 0; i < nestedList.size(); ++ i) {
            if (nestedList[i].isInteger()) base.push_back(nestedList[i].getInteger());
            else {
                vector<NestedInteger> n = nestedList[i].getList();
                getBase(n);
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        base.clear();
        index = 0;
        getBase(nestedList);
    }

    // @return {int} the next element in the iteration
    int next() {
        return base[index ++];
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        return index < base.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */
 
 
 /**
Flatten Nested List Iterator

Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may 
also be integers or other lists.

Example

    Given the list [[1,1],2,[1,1]], By calling next repeatedly until 
    hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

    Given the list [1,[4,[6]]], By calling next repeatedly until hasNext 
    returns false, the order of elements returned by next should be: [1,4,6].

  */
