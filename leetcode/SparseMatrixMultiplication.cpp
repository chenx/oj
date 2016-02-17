// Works. Tested.
// From: https://leetcode.com/discuss/84193/java-easy-version-to-understand
class Solution3 {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int A_Rows = A.size(), A_Columns = A[0].size(), B_Columns = B[0].size();
        vector<vector<int>> C(A_Rows, vector<int>(B_Columns, 0));
        for (int i = 0; i < A_Rows; i++)// 
            for (int j = 0; j < A_Columns; j++) {
                if (A[i][j] == 0)
                    continue;
                for (int k = 0; k < B_Columns; k++) {
                    if (B[j][k] == 0)
                        continue;
                    C[i][k] += A[i][j] * B[j][k];
                }
            }
        return C;
    }
};

// Works. Tested.
// From: https://leetcode.com/discuss/86263/sharing-my-48ms-c-solution
class Solution2 {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size();
        int p = A[0].size();
        int n = B[0].size();

        int i, j, k, a, b;
        vector<vector<int>> C;
        C.resize(m);
        for(i=0; i<m; i++)
            C[i].resize(n, 0);

        unordered_map<int, unordered_map<int, int>> AMap;
        for(i=0; i<m; i++)
            for(j=0; j<p; j++)
                if(A[i][j] != 0)
                    AMap[i][j] = A[i][j];

        unordered_map<int, unordered_map<int, int>> BMap;
        for(j=0; j<p; j++)
            for(k=0; k<n; k++)
                if(B[j][k] != 0)
                    BMap[k][j] = B[j][k];

        for(auto ia=AMap.begin(); ia!=AMap.end(); ia++)
        {
            auto ra = ia->second;
            i = ia->first;
            for(auto ib=BMap.begin(); ib!=BMap.end(); ib++)
            {
                auto rb = ib->second;
                k = ib->first;
                for(auto ia2=ra.begin(); ia2!=ra.end(); ia2++)
                {
                    j = ia2->first;
                    a = ia2->second;
                    if(rb.find(j) != rb.end())
                    {
                        b = rb[j];
                        C[i][k] += a*b;
                    }
                }
            }
        }

        return C;
    }
};

// Brutal force solution. Should work, but times out for large input.
// From: https://leetcode.com/discuss/76524/the-easiest-java-solution-based-on-math
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int rowA = A.size(), colA = A[0].size(), 
            rowB = B.size(), colB = B[0].size();
        vector<vector<int>> rst(rowA, vector<int>(colB, 0));
        for (int i = 0; i < rowA; i++) {
            for (int j = 0; j < colA; j++) {
                for (int k = 0; k < colB; k++) {
                    rst[i][k] += (A[i][j] * B[j][k]);
                }
            }
        }
        return rst;
    }
};


/**
Sparse Matrix Multiplication
Difficulty: Medium

Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
 */
