class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> words = split(text, ' ');
        set<char> broken;
        for (char ch : brokenLetters) broken.insert(ch);

        int count = 0;
        for (string& word : words) {
            if (canType(word, broken)) ++ count;
        }
        return count;
    }

    bool canType(string& s, set<char>& broken) {
        for (char ch : s) {
            if (broken.contains(ch)) return false;
        }
        return true;
    }

    vector<string> split(string& s, char delimiter) {
        vector<string> result;
        stringstream ss(s);
        string out;
        while (getline(ss, out, delimiter)) {
            result.push_back(out);
        }
        return result;
    }
};


/**
1935. Maximum Number of Words You Can Type
Easy

There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.

Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters 
of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.
 */
