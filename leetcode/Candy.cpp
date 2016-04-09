// Works too.
class Solution3 {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;
        
        vector<int> A(n, 0);
        A[0] = 1;
        for (int i = 1; i < n; ++ i) {
            A[i] = (ratings[i] > ratings[i-1]) ? A[i-1] + 1 : 1;
        }
        
        for (int i = n - 2; i >= 0; -- i) {
            if (ratings[i] > ratings[i+1]) A[i] = max(A[i], A[i+1] + 1);
        }
        
        int sum = 0;
        for (auto c : A) sum += c;
        return sum;
    }
};

// This works.
int minimalCandies(vector<int> &ratings) {
    int n = ratings.size();
    if (n == 0) return 0;
    
    int c[n];
    
    c[0] = 1;
    for (int i = 1; i < n; ++ i) {
        if (ratings[i] > ratings[i-1]) c[i] = c[i-1] + 1;
        else c[i] = 1;
    }
    
    for (int i = n-2; i >= 0; -- i) {
        if (ratings[i] > ratings[i+1]) {
            c[i] = max(c[i+1] + 1, c[i]);
        }
    }
    
    int sum = 0;
    for (int i = 0; i < n; ++ i) sum += c[i];
    
    return sum;
}

// This works too.
class Solution2 {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        if (n == 0) return 0;
        
        vector<int> c1(n), c2(n);
        
        c1[0] = 1;
        for (int i = 1; i < n; ++ i) c1[i] = (ratings[i] > ratings[i-1]) ? (c1[i-1] + 1) : 1;
        
        c2[n-1] = 1;
        for (int i = n-2; i >= 0; -- i) c2[i] = (ratings[i] > ratings[i+1]) ? (c2[i+1] + 1) : 1;
        
        int sum = 0;
        for (int i = 0; i < n; ++ i) sum += max(c1[i], c2[i]);
        
        return sum;
    }
};

/*

http://stackoverflow.com/questions/11292913/candies-interviewstreet


You can do this in two passes. Start with everyone having one candy.

First loop i from 1 to n-1 (zero based), if rating[i] > rating[i-1] then candies[i] = candies[i-1]+1

Then loop i from n-2 to 0; if rating[i] > rating[i+1] then candies[i] = max(candies[i], candies[i+1]+1)

It's pretty easy to show this gives you a valid distribution of candies, 
since the second loop can't break anything fixed by the first, and all 
possible rating discrepancies must be caught by one of the two loops. 
It's not as obvious that this will use the minimum number of candies, 
but if you examine each assignment closely you can show that the conditions 
prove a lower bound on the number of candies required (by a particular individual) at each step.


*/

/**
Candy
Difficulty: Hard

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give? 
 */
