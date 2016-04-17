// O(n) pre-processing, O(1) each query.
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        vector<long long> S;
        long long sum = 0;
        for (int i = 0; i < A.size(); ++ i) {
            sum += A[i];
            S.push_back(sum);
        }
        
        vector<long long> ans;
        for (int i = 0; i < queries.size(); ++ i) {
            Interval & q = queries[i];
            ans.push_back(S[q.end] - S[q.start] + A[q.start]);
        }
        return ans;
    }
};

/**
 Interval Sum

Given an integer array (index from 0 to n-1, where n is the size of this array), 
and an query list. Each query has two integers [start, end]. For each query, 
calculate the sum number between index start and end in the given array, 
return the result list.

Notice

We suggest you finish problem Segment Tree Build, Segment Tree Query and Segment Tree Modify first.
Example

For array [1,2,7,8,5], and queries [(0,4),(1,2),(2,4)], return [23,9,20]
Challenge

O(logN) time for each query

 */
