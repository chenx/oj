// Works too. My version.
// Note: stoi(string), atoi(const char *).
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        for (int i = 0, n = input.length(); i < n; ++ i) {
            if (ispunct(input[i])) {
                vector<int> vl = diffWaysToCompute(input.substr(0, i)), 
                            vr = diffWaysToCompute(input.substr(i+1));
        
                for (int L : vl) {
                    for (int R : vr) {
                        switch(input[i]) {
                            case '+': ans.push_back(L + R); break;
                            case '-': ans.push_back(L - R); break;
                            case '*': ans.push_back(L * R); break;
                        }
                    }
                }
            }
        }
        
        if (ans.size() == 0) ans.push_back(stoi(input));
        return ans;
    }
};

// Works too. Similar to Solution. 
// From: https://leetcode.com/discuss/81431/concise-recursive-solution-in-c
class Solution2 {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i<input.size(); ++i) {
            if (input[i]<'0' || input[i]>'9') {  // '+' or '-' or '*'
                vector<int> left = diffWaysToCompute(input.substr(0, i)); // left sub string
                vector<int> right = diffWaysToCompute(input.substr(i+1)); // right sub string
                for (auto l : left)
                    for (auto r : right) {
                        if (input[i] == '+') res.push_back(l + r);
                        else if (input[i] == '-') res.push_back(l - r);
                        else res.push_back(l * r);
                    }
            }
        }
        if (res.empty()) res.push_back(atoi(input.c_str()));   // only contain number
        return res;
    }
};

// This works. From: 
// https://leetcode.com/discuss/83355/recommend-beginners-implementation-detailed-explanation
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int size=input.size();
        vector<int> result;
        for(int i=0; i<size; i++){
            if(ispunct(input[i])){
                for(int a : diffWaysToCompute(input.substr(0, i)))
                    for(int b : diffWaysToCompute(input.substr(i+1))){
                        if(input[i]=='+')  result.push_back(a+b);
                        if(input[i]=='-')  result.push_back(a-b);
                        if(input[i]=='*')  result.push_back(a*b);
                    }
            }
        }
        /*** the base case is that there are no operator-char ***/
        /*** we return vector<int>{stoi(input)} when this happens ***/
        return result.size() ? result : vector<int>{stoi(input)};
    }
};

/**
Different Ways to Add Parentheses
Difficulty: Medium

Given a string of numbers and operators, return all possible results 
from computing all the different possible ways to group numbers and 
operators. The valid operators are +, - and *.

Example 1

Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2

Output: [0, 2]

Example 2

Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10

Output: [-34, -14, -10, -10, 10]
 */
