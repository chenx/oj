class Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        unordered_map<char, int> toFind, found;
        for (auto c : target) toFind[c] ++;
        
        int total = 0, minLen = -1, minStart = -1;
        for (int end = 0, begin = 0; end < source.size(); ++ end) {
            char e = source[end];
            if (toFind[e] == 0) continue;
            found[e] ++;
            if (found[e] <= toFind[e]) ++ total;
            
            if (total == target.length()) {
                char b = source[begin];
                while (toFind[b] == 0 || found[b] > toFind[b]) { // note this!
                    if (found[b] > toFind[b]) -- found[b];
                    b = source[++ begin];
                }
                
                if (minLen == -1 || minLen > end - begin + 1) {
                    minLen = end - begin + 1;
                    minStart = begin;
                }
            }
        }
        
        return minLen == -1 ? "" : source.substr(minStart, minLen);
    }
};


/**
Minimum Window Substring

Given a string source and a string target, find the minimum window in source 
which will contain all the characters in target.

Notice

If there is no such window in source that covers all characters in target, 
return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will 
always be only one unique minimum window in source.
Clarification

Should the characters in minimum window has the same order in target?

    Not necessary.

Example

For source = "ADOBECODEBANC", target = "ABC", the minimum window is "BANC"
Challenge

Can you do it in time complexity O(n) ?

 */
