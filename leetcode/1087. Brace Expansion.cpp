// Time: O(n * 3^(n/7))
// Space: O(n)
class Solution {
public:
    vector<string> expand(string s) {
        vector<vector<string>> tokens = split(s);

        vector<string> result;
        dfs(result, tokens, 0, "");
        sort(result.begin(), result.end());

        return result;
    }

    inline vector<vector<string>> split(string& s) {
        vector<vector<string>> tokens;
        string cur;
        for (char ch : s) {
            if (ch == '{') {
                if (cur != "") tokens.push_back(getOptions(cur));
                cur = "";
            } else if (ch == '}') {
                if (cur != "") tokens.push_back(getOptions(cur));
                cur = "";
            } else {
                cur += ch;
            }
        }
        if (cur != "") tokens.push_back(getOptions(cur)); // Don't forget this!
        // print(tokens);
        return tokens;
    }

    void dfs(vector<string>& result, vector<vector<string>> tokens, int pos, string word) {
        if (pos == tokens.size()) {
            result.push_back(word);
            return;
        }

        for (string& token : tokens[pos]) {
            dfs(result, tokens, pos + 1, word + token);
        }
    }

    vector<string> getOptions(string& item) {
        vector<string> v;
        string cur;
        for (char ch : item) {
            if (ch == ',') {
                if (cur != "") v.push_back(cur);
                cur = "";
            } else {
                cur += ch;
            }
        }
        if (cur != "") v.push_back(cur); // Don't forget this!
        // cout << "==> getOptions: " << item << endl;
        // print(v);
        return v;
    }

    vector<string> getOptions2(string& item) {
        vector<string> options;
        stringstream ss(item);
        string out;
        while (getline(ss, out, ',')) {
            options.push_back(out);
        }
        return options;
    }

    void print(vector<vector<string>>& v) {
        for (auto& u : v) print(u);
    }

    void print(vector<string>& v) {
        for (auto& u : v) cout << u << " ";
        cout << endl;
    }
};


/**
1087. Brace Expansion
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given a string s representing a list of words. Each letter in the word has one or more options.

    If there is one option, the letter is represented as is.
    If there is more than one option, then curly braces delimit the options. For example, "{a,b,c}" 
        represents options ["a", "b", "c"].

For example, if s = "a{b,c}", the first character is always 'a', but the second character can be 'b' or 'c'. 
The original list is ["ab", "ac"].

Return all words that can be formed in this manner, sorted in lexicographical order.

 

Example 1:

Input: s = "{a,b}c{d,e}f"
Output: ["acdf","acef","bcdf","bcef"]

Example 2:

Input: s = "abcd"
Output: ["abcd"]
 */
