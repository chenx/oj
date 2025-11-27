// Works. 
// From: 
// - https://github.com/studyPlacement/CodeHub/blob/main/Solution3756
// - https://www.youtube.com/watch?v=EkWxqKanyWw
class Solution {
    int mod = 1000000007;
    public int[] sumAndMultiply(String s, int[][] queries) {
        int n = s.length();
        long prefixSum[] = new long[n];
        long preNonZeroNumber[] = new long[n];
        long preCount[] = new long[n];
        
        for(int i=0; i<n; i++){
            int digit = s.charAt(i) - '0';
            if(i > 0){
                prefixSum[i] = prefixSum[i-1];
                preNonZeroNumber[i] = preNonZeroNumber[i-1];
                preCount[i] = preCount[i-1];
            }
            if(digit != 0){
                prefixSum[i] += digit;
                preCount[i]++;
                preNonZeroNumber[i] = ((preNonZeroNumber[i] * 10) % mod + digit)%mod;
            }
        }
        long[] power = new long[n + 1];
        power[0] = 1;
        for (int i = 1; i <= n; i++) {
            power[i] = (power[i - 1] * 10) % mod;
        }
        int m = queries.length;
        int ans[] = new int[m];
        for (int i = 0; i < m; i++) {
            int l = queries[i][0], r = queries[i][1];

            long len = preCount[r] - ((l > 0) ? preCount[l - 1] : 0);
            long x = preNonZeroNumber[r];
            if (l > 0) {
                x = (x - (preNonZeroNumber[l - 1] * power[(int)len] % mod) + mod) % mod;
            }

            long sum = (prefixSum[r] - ((l > 0) ? prefixSum[l - 1] : 0)) % mod;
            ans[i] = (int) ((x * sum) % mod) % mod;
        }

        return ans;
    }
}


// Works, but time out for large input.
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> answer;
        int mod = pow(10, 9) + 7;

        for (auto query : queries) {
            string t = s.substr(query[0], query[1] - query[0] + 1);
            unsigned long long x = 0, sum = 0;
            for (char ch : t) {
                if (ch != '0') {
                    int digit = ch - '0';
                    x = (x * 10 + digit) % mod;
                    sum += digit;
                }
            }
            answer.push_back(x * sum % mod);
        }
        return answer;
    }
};


/**
3756. Concatenate Non-Zero Digits and Multiply by Sum II
Medium

You are given a string s of length m consisting of digits. You are also given a 2D integer array queries, 
where queries[i] = [li, ri].

For each queries[i], extract the

s[li..ri]. Then, perform the following:

    Form a new integer x by concatenating all the non-zero digits from the substring in their original order. 
        If there are no non-zero digits, x = 0.
    Let sum be the sum of digits in x. The answer is x * sum.

Return an array of integers answer where answer[i] is the answer to the ith query.

Since the answers may be very large, return them modulo 109 + 7.

 

Example 1:

Input: s = "10203004", queries = [[0,7],[1,3],[4,6]]

Output: [12340, 4, 9]

Explanation:

    s[0..7] = "10203004"
        x = 1234
        sum = 1 + 2 + 3 + 4 = 10
        Therefore, answer is 1234 * 10 = 12340.
    s[1..3] = "020"
        x = 2
        sum = 2
        Therefore, the answer is 2 * 2 = 4.
    s[4..6] = "300"
        x = 3
        sum = 3
        Therefore, the answer is 3 * 3 = 9.
 */
