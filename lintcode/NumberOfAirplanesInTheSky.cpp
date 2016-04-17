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
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        int n = airplanes.size();
        if (n <= 1) return n;
        vector<int> A(n), B(n);
        for (int i = 0; i < airplanes.size(); ++ i) {
            A[i] = airplanes[i].start;
            B[i] = airplanes[i].end;
        }
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        int ct = 0, maxCt = 0;
        for (int i = 0, j = 0; i < n && j < n; ) {
            if (A[i] < B[j]) {
                if (++ ct > maxCt) maxCt = ct;
                ++ i;
            }
            else {
                -- ct;
                ++ j;
            }
        }
        
        return maxCt;
    }
};


/**
Number of Airplanes in the Sky

Given an interval list which are flying and landing time of the flight. 
How many airplanes are on the sky at most?

Notice

If landing and flying happens at the same time, we consider landing should happen at first.
Example

For interval list

[
  [1,10],
  [2,3],
  [5,8],
  [4,7]
]

Return 3

 */
