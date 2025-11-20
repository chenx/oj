class UnionFind {
    vector<int> group;
    vector<int> rank;
public:
    UnionFind(int size) {
        group.resize(size, 0);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++ i) {
            group[i] = i;
            rank[i] = 0;
        }
    }

    /** Return the id of group that the person belongs to. */
    int find(int person) {
        if (group[person] != person) {
            group[person] = find(group[person]);
        }
        return group[person];
    }

    /**
     * If it is necessary to merge the two groups that x, y belong to.
     * Not: union is a keyword in C++, don't use it for function name.
     */
    bool unite(int a, int b) {
        int groupA = find(a);
        int groupB = find(b);
        bool isMerged = false;

        if (groupA == groupB) return isMerged;

        // Otherwise, merge the two groups.
        isMerged = true;
        // Merge the lower-rank group into the higher-rank group.
        if (rank[groupA] > rank[groupB]) {
            group[groupB] = groupA;
        } else if (rank[groupA] < rank[groupB]) {
            group[groupA] = groupB;
        } else {
            group[groupA] = groupB;
            rank[groupB] += 1;
        }

        return isMerged;
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        // In order to ensure that we find the _earliest_ moment,
        // first of all we need to sort the events in chronological order.
        sort(logs.begin(), logs.end(), comp); // sort by first value, then 2nd, then 3rd.

        // Initially, we treat each individual as a separate group.
        int groupCount = n;
        UnionFind uf(n);

        for (auto log : logs) {
            int timestamp = log[0];
            int friendA = log[1];
            int friendB = log[2];
            if (uf.unite(friendA, friendB)) {
                groupCount -= 1;
            }

            if (groupCount == 1) {
                return timestamp;
            }
        }

        // There are still more than one groups left,
        //  i.e. not everyone is connected.
        return -1;
    }

    static bool comp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
};


/**
1101. The Earliest Moment When Everyone Become Friends
Medium

There are n people in a social group labeled from 0 to n - 1. You are given an array logs where 
logs[i] = [timestampi, xi, yi] indicates that xi and yi will be friends at the time timestampi.

Friendship is symmetric. That means if a is friends with b, then b is friends with a. Also, 
person a is acquainted with a person b if a is friends with b, or a is a friend of someone acquainted with b.

Return the earliest time for which every person became acquainted with every other person. 
If there is no such earliest time, return -1.
 */
