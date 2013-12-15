int totalPath(vector<vector<bool> > &blocked) {
        int m = blocked.size(); //
        if (m == 0) return 0;
        int n = blocked[0].size();
        if (n == 0) return 0;
        
        int i, j;
        int a[m][n];

        for (j = 0; j < n; j ++) { 
            if (blocked[0][j] == 0) a[0][j] = 1;
            else {
                for (; j < n; j ++) a[0][j] = 0;
                break;
            }
        }
        for (i = 0; i < m; i ++) { 
            if (blocked[i][0] == 0) a[i][0] = 1;
            else {
                for (; i < m; i ++) a[i][0] = 0;
                break;
            }
        }
        
        for (i = 1; i < m; i ++) {
            for (j = 1; j < n; j ++) {
                if (blocked[i][j] == 1) a[i][j] = 0;
                else a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }
        
        return a[m-1][n-1];
}

// same as http://cssauh.com/xc/code/leetcode/UniquePaths_II.cpp