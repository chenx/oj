// Should work. Not tested.
// From: https://leetcode.com/discuss/95042/two-clean-c-solutions-for-your-reference
class Solution {
public:
    int dfs(vector<NestedInteger>& nestedList, int depth) {
        int ans = 0;
        for (auto ni : nestedList)
            ans += ni.isInteger() ? ni.getInteger() * depth : dfs(ni.getList(), depth + 1);
        return ans;
    }

    int depthSum(vector<NestedInteger>& nestedList) {
        return dfs(nestedList, 1);
    }
};


// Should work. Tested locally. XC.
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return getSum(nestedList, 1);
    }

    int getSum(vector<NestedInteger> nestedList, int depth) {
        int sum = 0;
        for (int i = 0, n = nestedList.size(); i < n; ++ i) {
            if (nestedList[i].isInteger())
                sum += nestedList[i].getInteger() * depth;
            else {
                sum += getSum(nestedList[i].getList(), depth + 1);
            }
        }
        return sum;
    }
};

/**
 * Nested List Weight Sum
 * Difficulty: easy
 *
 * Given a nested list of integers, returns the sum of all integers in the list weighted by their depth
 * For example, given the list {{1,1},2,{1,1}} the function should return 10 (four 1's at depth 2, one 2 at depth 1)
 * Given the list {1,{4,{6}}} the function should return 27 (one 1 at depth 1, one 4 at depth 2, one 6 at depth2)
 *
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
