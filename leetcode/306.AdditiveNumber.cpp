// From: https://algo.monster/liteproblems/306
// Time: O(n^3)
// Space: O(n)
class Solution7 {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        // Try all possible combinations of first two numbers
        // i represents the end position of the first number (exclusive)
        for (int i = 1; i < min(n - 1, 19); ++i) {
            // j represents the end position of the second number (exclusive)
            for (int j = i + 1; j < min(n, i + 19); ++j) {
                // First number cannot have leading zeros (except single digit 0)
                if (i > 1 && num[0] == '0') break;
                // Second number cannot have leading zeros (except single digit 0)
                if (j - i > 1 && num[i] == '0') continue;
                long long firstNum = stoll(num.substr(0, i));
                long long secondNum = stoll(num.substr(i, j - i));

                // Check if the remaining string forms a valid additive sequence
                string remaining = num.substr(j, n - j);
                if (checkAdditiveSequence(firstNum, secondNum, remaining)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool checkAdditiveSequence(long long prev1, long long prev2, string remaining) {
        // Base case: if no more digits left, the sequence is valid
        if (remaining.empty()) {
            return true;
        }
      
        // The next number cannot have leading zeros (except 0 itself)
        long long expectedSum = prev1 + prev2;
        if (expectedSum > 0 && remaining[0] == '0') {
            return false;
        }
      
        // Try to match the sum with prefixes of the remaining string
        // Limit to 19 digits to avoid overflow (max digits in long long)
        int maxLength = min(static_cast<int>(remaining.size() + 1), 19);
      
        for (int i = 1; i < maxLength; ++i) {
            long long currentNum = stoll(remaining.substr(0, i));
          
            // If current number equals the expected sum
            if (currentNum == expectedSum) {
                // Recursively check the rest of the string
                string nextRemaining = remaining.substr(i, remaining.size() - i);
                if (checkAdditiveSequence(prev2, expectedSum, nextRemaining)) {
                    return true;
                }
            }
        }
      
        return false;
    }
};

// Previous solutions no longer work because of large number overflow. This works.
// Time: O(n^3)
// Space: O(n)
class Solution6 {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i < num.size(); ++ i) 
            for (int j = 1; i + j < num.size(); ++ j) 
                if (ok(num.substr(0, i), num.substr(i, j), num.substr(i+j)))
                    return true;

        return false;
    }
    
    bool ok(string n1, string n2, string n) {
        // E.g., "0000" => n1 = "0", n2 = "0", n = "00". This is valid. Don't check n.
        // if (! valid(n1) || ! valid(n2) || ! valid(n)) return false;
        if (! valid(n1) || ! valid(n2)) return false;

        string sum = stringAdd(n1, n2);
        if (sum == n) return true;

        if (n.find(sum) != 0) return false; // sum should be a prefix of n.

        int len = sum.length();
        return ok(n2, n.substr(0, len), n.substr(len));
    }

    string stringAdd(string& a, string& b) {
        int carry = 0, i = a.length() - 1, j = b.length() - 1;
        string result;
        for (; i >= 0 && j >= 0; -- i, -- j) {
            add(result, a[i] - '0' + b[j] - '0' + carry, carry);
        }
        for (; i >= 0; -- i) {
            add(result, a[i] - '0' + carry, carry);
        }
        for (; j >= 0; -- j) {
            add(result, b[j] - '0' + carry, carry);
        }
        if (carry > 0) {
            add(result, carry, carry);
        }
        return result;
    }

    void add(string& result, int sum, int& carry) {
        if (sum >= 10) {
            sum -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result = (char)(sum + '0') + result;
    }
    
    bool valid(string n) {
        if (n == "") return false;
        if (n.length() > 1 && n[0] == '0') return false;
        return true;
    }
};


// Works too. Short.
class Solution5 {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i < num.size(); ++ i) 
            for (int j = 1; i + j < num.size(); ++ j) 
                if (ok(num.substr(0, i), num.substr(i, j), num.substr(i+j)))
                    return true;

        return false;
    }
    
    bool ok(string n1, string n2, string n) {
        if (! valid(n1) || ! valid(n2) || ! valid(n)) return false;
        
        long long sum = stoll(n1) + stoll(n2);
        int len = log10(sum) + 1;
        if (stoll(n.substr(0, len)) != sum) return false;
        if (len == n.length()) return true;
        
        return ok(n2, n.substr(0, len), n.substr(len));
    }
    
    bool valid(string n) {
        if (n == "") return false;
        if (n.length() > 1 && n[0] == '0') return false;
        return true;
    }
};


// Works. Slightly improved from Solution2.
class Solution4 {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        for (int i = 1; i < n; ++ i) {
            for (int j = 1; j < n - i; ++ j) {
                if (isGood(num.substr(0, i), num.substr(i, j), num.substr(i+j)))
                    return true;
            }
        }
        return false;
    }
    
    bool isGood(string s1, string s2, string s) {
        if (! validNum(s1) || ! validNum(s2) || ! validNum(s)) return false;

        long long sum = stoll(s1) + stoll(s2);
        int len = (int) log10(sum) + 1; // or: log10(sum) + 1 // NOTE: "+1" needed.
        string s3 = s.substr(0, len);
        
        if (stoll(s3) != sum) return false;
        if (len == s.length()) return true;
        
        return isGood(s2, s3, s.substr(len));
    }
    
    bool validNum(string s) {
        if (s.length() > 1 && s[0] == '0') return false;
        return true;
    }
};

// Works. Tested. But Solution2 may be better.
class Solution3 {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        for (int i = 1; i < n; ++ i) {
            for (int j = 1; j < n - i; ++ j) {
                if (isGood(num, i+j, num.substr(0, i), num.substr(i, j)))
                    return true;
            }
        }
        return false;
    }
    
    bool isGood(string num, int pos, string s1, string s2) {
        long long sum = stoll(s1) + stoll(s2);
        int len = (int) log10(sum) + 1;
        string s3 = num.substr(pos, len);
        
        if (! validNum(s1) || ! validNum(s2) || ! validNum(s3)) return false;
        
        if (stoll(s3) != sum) return false;
        if (pos + len == num.length()) return true;
        return isGood(num, pos + len, s2, s3);
    }
    
    bool validNum(string s) {
        if (s.length() > 1 && s[0] == '0') return false;
        return true;
    }
};

// Works. Tested. Modified from Solution.
class Solution2 {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        for (int i = 1; i < n; ++ i) {
            for (int j = 1; j < n-i; ++ j) {
                // be careful of index.
                if (helper(num.substr(0, i), num.substr(i, j), num.substr(i+j)))
                    return true;
            }
        }
        
        return false;
    }
    
    // expect: a + b == c
    bool helper(string a, string b, string c) {
        if (invalid(a) || invalid(b) || invalid(c)) return false;
        
        long long sum = stoll(a) + stoll(b);
        int len = (int)log10(sum) + 1;
        if (sum != stoll(c.substr(0, len))) return false;
        if (len == c.length()) return true;
        
        return helper(b, c.substr(0, len), c.substr(len));
    }
    
    bool invalid(string s) {
        if (s.length() > 1 && s[0] == '0') return true;
        return false;
    }
};

// Works. 
// Modified from: https://leetcode.com/discuss/82185/c-straightforward-solution
class Solution {
public:
    bool isAdditiveNumber(string num, string last1, string last2) {
         if ((num[0] == '0' && num.length() > 1) || 
             (last1[0] == '0' && last1.length() > 1) || 
             (last2[0] == '0' && last2.length() > 1))
        return false;
    
        long long sum = stoll(last1) + stoll(last2);
        int len = (int)log10(sum) + 1;
        if (sum != stoll(num.substr(0, len))) return false;
        //if (num.substr(len).length() == 0) return true;
        if (len == num.length()) return true;
        
        return isAdditiveNumber(num.substr(len), last2, num.substr(0, len));
    }
    
    bool isAdditiveNumber(string num) {
        for (int i = 1; i < num.length(); ++ i) {
            for (int j = 1, lenj = num.length() - i; j < lenj; ++ j) {
                if (isAdditiveNumber(num.substr(i + j), num.substr(0, i), num.substr(i, j)))
                    return true;
            }
        }
    
        return false;
    }
};


/**
Additive Number
Difficulty: Medium

Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. 
Except for the first two numbers, each subsequent number in the 
sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an 
additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.

1 + 99 = 100, 99 + 100 = 199

Note: Numbers in the additive sequence cannot have leading zeros, 
so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function 
to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers? 
 */
