// Works. Tested. By: XC.
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> ans;
        if (s.length() == 1) ans.push_back(s); 
        if (s.length() <= 1) return ans;

        const int SIZE = 256;
        int ct[SIZE] = {0}, len = s.length();
        for (int i = 0; i < len; ++ i) ++ ct[s[i]];

        // count number of each char, 
        // and get the index of the char of odd occurrence.
        int odd = 0, odd_index = 0;
        for (int i = 0; i < SIZE; ++ i) {
            if (ct[i] & 1) {
                odd ++;
                odd_index = i;
            }
        }
        
        // iff can have palindromes, get such strings.
        if (((len & 1 == 1) && odd == 1) || (odd == 0)) {
            vector<int> nums = getChars(ct, SIZE); // get half of the chars.
            sort(nums.begin(), nums.end());
            
            do {
                ans.push_back(getPalindrome(nums, len & 1 == 1, odd_index));
            } while (nextPermutation(nums));
        }
        
        return ans;
    }
    
    string getPalindrome(vector<int> &nums, bool odd, char oddChar) {
        string s;
        for (int i = 0; i < nums.size(); ++ i) {
            s += (char) nums[i];
        }

        string s2 = rev(s);
        if (odd) s += oddChar;
        s += s2;
        
        return s;
    }
    
    string rev(string s) {
        string t;
        for (int i = 0; i < s.length(); ++ i) t = s[i] + t;
        return t;
    }
    
    // only use half of the chars. If it's odd, 
    // then divide by 2 will eliminate the extra 1.
    vector<int> getChars(int ct[], int SIZE) {
        vector<int> v;
        for (int i = 0; i < SIZE; ++ i) {
            int j = ct[i] / 2;
            //if (j & 1) j -= 1;
            //j /= 2;
            for (; j > 0; -- j) {
                v.push_back(i);
            }
        }
        return v;
    }
    
    bool nextPermutation(vector<int> &num) {
        int n = num.size();
        
        int i, j;
        for (i = n-2; i >= 0 && num[i] >= num[i+1]; -- i) {} // find first num[i] < num[i+1].
        
        if (i == -1) {
            //reverse(num.begin(), num.end());
            return false;
        }
        
        for (j = n-1; num[j] <= num[i]; -- j) {} // find first elem from right larger than num[i].
        swap(num[i], num[j]);
        
        reverse(num.begin() + i + 1, num.end());
        return true;
    }
};


/**
Palindrome Permutation II
Difficulty: Medium

Given a string s, return all the palindromic permutations 
(without duplicates) of it. Return an empty list if no 
palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].

Hint:

If a palindromic permutation exists, we just need to 
generate the first half of the string.

To generate all distinct permutations of a (half of) string, 
use a similar approach from: Permutations II or Next Permutation.
 */
