// 10/24/2014


// Assumption: sorted ASC.
// Note the min is the only one less than its immediate left member.
// Every other element is larger than its immediate left member.
// This works and is O(n).
// From: http://www.mitbbs.com/article_t/JobHunting/32810093.html, by smalleye.
//
class Solution {
public:
    int findMin(vector<int> &num) {
        int L = 0, R = num.size() - 1;
        
        while (L < R) {
            int M = L + (R - L) / 2;

            if (num[M] < num[R]) {
                R = M;
            } else if (num[M] == num[R]) {
                -- R;
            } else {
                L = M + 1;
            }
        }
        
        return num[L];
    }
};
