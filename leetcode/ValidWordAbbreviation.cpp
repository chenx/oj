class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < abbr.length() && j < word.length()) {
            if (isdigit(abbr[i])) {
                // Note this. word: abbde, abbr: "a1b01e" -> returns false.
                if (abbr[i] == '0') return false;
                int v = abbr[i] - '0';
                while (isdigit(abbr[++i])) {
                    v = v*10 + abbr[i] - '0';
                }
                j += v;
            } else {
                if (abbr[i] != word[j]) return false;
                ++ i; ++ j;
            }
        }

        return i == abbr.length() && j == word.length();
    }
};

/**
408. Valid Word Abbreviation

A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings with their lengths.
The lengths should not have leading zeros.

For example, a string such as "substitution" could be abbreviated as (but not limited to):

    "s10n" ("s ubstitutio n")
    "sub4u4" ("sub stit u tion")
    "12" ("substitution")
    "su3i1u2on" ("su bst i t u ti on")
    "substitution" (no substrings replaced)

The following are not valid abbreviations:

    "s55n" ("s ubsti tutio n", the replaced substrings are adjacent)
    "s010n" (has leading zeros)
    "s0ubstitution" (replaces an empty substring)

Given a string word and an abbreviation abbr, return whether the string matches the given abbreviation.

A substring is a contiguous non-empty sequence of characters within a string.
 */
