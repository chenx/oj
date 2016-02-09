// This works. Tested.
// From: http://www.danielbit.com/blog/puzzle/leetcode/leetcode-missing-ranges
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& A, int start, int end) {
        int n = A.size();
        int prev = start - 1, cur;
        for (int i = 0; i <= n; ++ i) {
            cur = (i == n ? end + 1 : A[i]);
            if (cur - prev >= 2) {
                ranges.push_back( getRange(prev + 1, cur - 1) );
            }
            prev = cur;
        }
        
        return ranges;
    }
    
    string getRange(int a, int b) {
        if (a == b) return to_string(a);
        else return to_string(a) + "->" + to_string(b);
    }
};


/**
Missing Ranges

Given a sorted integer array where the range of elements are [0, 99] inclusive, return its missing ranges.
For example, given [0, 1, 3, 50, 75], return [“2”, “4->49”, “51->74”, “76->99”]
 */
