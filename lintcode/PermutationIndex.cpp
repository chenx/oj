//
// Idea: the order number = 
// sum{i = 1 to n}{ (number of elements smaller than A[i] to its right) * Factorial(n - i) }
// By: X.C., 4/18/2016
//
class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        int n = A.size();
        vector<long long> F(n); // factorial
        F[0] = 1;
        for (int i = 1; i < n; ++ i) F[i] = i * F[i-1];

        long long order = 1; // 1-based.
        for (int i = 0; i < n; ++ i) {
            order += F[n-1 - i] * countSmaller(A, i);
        }
        return order;
    }

    // Return number of elements A[i+1]..A[n-1] that is less than A[i].
    // Now O(n), can reduce to O(log(n)) using Ordered Statistics Tree.
    // See: CountOfSmallerNumbersAfterSelf.cpp
    int countSmaller(vector<int> & A, int i) {
        int ct = 0, v = A[i];
        for (++ i; i < A.size(); ++ i)
            if (A[i] < v) ++ ct;
        return ct;

    }
};


/**
Permutation Index

Given a permutation which contains no repeated number, find its index in all 
the permutations of these numbers, which are ordered in lexicographical order. 
The index begins at 1.

Example

Given [1,2,4], return 1.
 */
