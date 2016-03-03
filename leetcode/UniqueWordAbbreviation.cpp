// Should work. Not tested.
class ValidWordAbbr2 {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string s : dictionary) 
            m[getAbbr(s)].push_back(s);
    }

    // Unique iff: the word's abbreviation is not found in dic, 
    // or: the word itself is in dic, and is the only one with that abbreviation.
    bool isUnique(string word) {
        string abbr = getAbbr(word);
        if (m.find(abbr) == m.end()) return true;
        if (m[abbr].size() == 1 && m[abbr][0] == word) return true;
        return false;
    }
    
private:
    unordered_map<string, vector<string>> m;
    
    string getAbbr(string s) {
        int len = s.length();
        if (len <= 2) return s;
        return s[0] + to_string(len - 2) + s[len - 1];
    }
};

// Works. Tested. By: XC
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto s : dictionary) {
            dic[getAbbreviation(s)].insert(s);
        }
    }

    // Unique iff: the word's abbreviation is not found in dic, 
    // or: the word itself is in dic, and is the only one with that abbreviation.
    bool isUnique(string word) {
        string abbr = getAbbreviation(word);
        if (dic.find(abbr) == dic.end()) return true;
        if (dic[abbr].size() == 1 && dic[abbr].find(word) != dic[abbr].end()) return true;
        return false;
    }
private:
    string getAbbreviation(string s) {
        int len = s.length();
        if (len <= 2) return s;
        return s[0] + to_string(len - 2) + s[len - 1];
    }
    
    unordered_map<string, unordered_set<string>> dic;
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");


/**
Unique Word Abbreviation
Difficulty: Easy

An abbreviation of a word follows the form <first letter><number><last letter>. 
Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n

Assume you have a dictionary and given a word, find whether its abbreviation is 
unique in the dictionary. A word's abbreviation is unique if no other word from 
the dictionary has the same abbreviation.

Example: 
Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
 */
