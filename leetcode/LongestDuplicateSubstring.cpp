// Version 3. Works.
typedef unsigned long long ull;

class Solution {
    ull prefixHash[30010], powers[30010];
    int BASE = 113;
public:
    string longestDupSubstring(string s) {
        int n = s.length();
        powers[0] = 1;
        prefixHash[0] = 0;
        for (int i = 0; i < n; ++ i) { // rolling hash.
            powers[i+1] = powers[i] * BASE;
            prefixHash[i+1] = prefixHash[i] * BASE + s[i];
        }

        string ans;
        int L = 0, R = n - 1;
        while (L < R) {
            int M = 1 + L + (R-L)/2;
            string dup = findDup(s, M);
            if (dup.empty()) {
                R = M - 1;
            } else {
                L = M;
                ans = dup;
            }
        }
        return ans;
    }

    string findDup(string& s, int len) {
        set<ull> foundHashes;

        for (int i = 0; i + len <= s.length(); ++ i) {
            int j = i + len;
            ull hash = prefixHash[j] - prefixHash[i] * powers[j-i];
            if (foundHashes.contains(hash)) {
                return s.substr(i, len); // found
            }
            foundHashes.insert(hash);
        }
        return ""; // not found
    }
};

// Version 2. Works.
typedef unsigned long long ULL;

class Solution {
public:
    // Arrays for polynomial hash computation
    ULL powers[30010];      // powers[i] stores base^i
    ULL prefixHash[30010];  // prefixHash[i] stores hash of s[0...i-1]
  
    string longestDupSubstring(string s) {
        // Initialize hash parameters
        const int BASE = 131;  // Prime base for polynomial rolling hash
        int n = s.size();
      
        // Precompute powers of base
        powers[0] = 1;
        prefixHash[0] = 0;
        for (int i = 0; i < n; ++i) {
            powers[i + 1] = powers[i] * BASE;
            prefixHash[i + 1] = prefixHash[i] * BASE + s[i];
        }
      
        // Binary search on the length of duplicate substring
        int left = 0, right = n - 1;
        string result = "";
      
        while (left < right) {
            int mid = 1 + left + (right - left) / 2;
            string dup = findDupOfLength(s, mid);
          
            if (dup.empty()) { // No duplicate of this length, try smaller lengths
                right = mid - 1;
            } else { // Found duplicate, try larger lengths
                left = mid;
                result = dup;
            }
        }
      
        return result;
    }
  
private:
    // Check if there exists a duplicate substring of given length
    string findDupOfLength(string& s, int len) {
        int n = s.size();
        set<ULL> seenHashes;
      
        // Slide window of size len through the string
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len; // end index
            ULL currentHash = prefixHash[j] - prefixHash[i] * powers[j - i];
            if (seenHashes.contains(currentHash)) {
                return s.substr(i, len);
            }
            seenHashes.insert(currentHash);
        }
      
        return "";  // No duplicate of this length found
    }
};

// Works.
// From https://leetcode.com/problems/longest-duplicate-substring/editorial/
typedef unsigned long long ULL;

class Solution {
public:
    // Arrays for polynomial hash computation
    ULL powers[30010];      // powers[i] stores base^i
    ULL prefixHash[30010];  // prefixHash[i] stores hash of s[0...i-1]
  
    string longestDupSubstring(string s) {
        // Initialize hash parameters
        const int BASE = 131;  // Prime base for polynomial rolling hash
        int n = s.size();
      
        // Precompute powers of base
        powers[0] = 1;
        prefixHash[0] = 0;
        for (int i = 0; i < n; ++i) {
            powers[i + 1] = powers[i] * BASE;
            prefixHash[i + 1] = prefixHash[i] * BASE + s[i];
        }
      
        // Binary search on the length of duplicate substring
        int left = 0, right = n - 0;
        string result = "";
      
        while (left < right) {
            // Try middle length (bias towards larger when even)
            int mid = 1 + left + (right - left) / 2;
            string dup = findDupOfLength(s, mid);
          
            if (dup.empty()) { // No duplicate of this length, try smaller lengths
                right = mid - 1;
            } else { // Found duplicate, try larger lengths
                left = mid;
                result = dup;
            }
        }
      
        return result;
    }
  
private:
    // Check if there exists a duplicate substring of given length
    // Returns the duplicate substring if found, empty string otherwise
    string findDupOfLength(string& s, int len) {
        int n = s.size();
        set<ULL> seenHashes;
      
        // Slide window of size targetLength through the string
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1; // end index
          
            // Calculate hash of substring s[i-1...endIdx-1]
            // Using formula: hash(s[i...j]) = prefixHash[j+1] - prefixHash[i] * base^(j-i+1)
            ULL currentHash = prefixHash[j] - prefixHash[i - 1] * powers[j - i + 1];
          
            // Check if we've seen this hash before (duplicate found)
            if (seenHashes.count(currentHash)) {
                return s.substr(i - 1, len);
            }
          
            seenHashes.insert(currentHash);
        }
      
        return "";  // No duplicate of this length found
    }
};

/**
1044. Longest Duplicate Substring

Given a string s, consider all duplicated substrings: (contiguous) substrings of s that 
occur 2 or more times. The occurrences may overlap.

Return any duplicated substring that has the longest possible length. If s does not have 
a duplicated substring, the answer is "".
 */
