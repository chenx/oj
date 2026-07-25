class UnionFind {
public:
  void add(string x) {
    if (parent.contains(x)) return;

    parent[x] = x;
    rank[x] = 0;
  }

  // Iterative version.
  string find2(string x) {  // Path compression.
    while (parent[x] != x) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return parent[x];
  }

  // Standard recursive version.
  string find(string x) {  // Path compression.
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  // string find(string x) {  // Path compression.
  //   while (parent[x] != parent[parent[x]]) {
  //     parent[x] = parent[parent[x]];
  //   }
  //   return parent[x];
  // }

  void get_union(string x, string y) {
    x = find(x), y = find(y);
    if (x == y) return;

    int rx = rank[x], ry = rank[y];
    if (rx > ry) {
      parent[y] = x;
    } else if (ry > rx) {
      parent[x] = y;
    } else {
      parent[y] = x;
      rank[x] += 1;
    }
  }

  unordered_map<string, string>& get_parent_map() {
    return parent;
  }

private:
  unordered_map<string, string> parent;
  unordered_map<string, int> rank;
};

class Solution {
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        UnionFind uf;
        for (auto& s : synonyms) {
            uf.add(s[0]);
            uf.add(s[1]);
            uf.get_union(s[0], s[1]);
        }
        unordered_map<string, set<string>> smap;
        for (auto& [s, _] : uf.get_parent_map()) {
            smap[uf.find(s)].insert(s);
        }
        // for (auto& [key, values] : smap) {
        //     cout << key << ": ";
        //     for (string val : values) cout << val << " ";
        //     cout << endl;
        // }

        vector<string> tokens = split(text);
        vector<string> result;
        dfs(result, uf, tokens, smap, "", 0);

        return result;
    }

    void dfs(vector<string>& result, UnionFind& uf, vector<string>& tokens, unordered_map<string, set<string>>& smap, string s, int pos) {
        if (pos == tokens.size()) {
            result.push_back(s);
            return;
        }

        string root = uf.find(tokens[pos]);
        if (smap.contains(root)) {
            for (string token : smap[root]) {
               dfs(result, uf, tokens, smap, append(s, token), pos + 1);
            }
        } else {
            dfs(result, uf, tokens, smap, append(s, tokens[pos]), pos + 1);
        }
    }

    string append(string& a, string& b) {
        if (a == "") return b;
        return a + " " + b;
    }

    vector<string> split(string& s) {
        vector<string> tokens;
        string token;
        stringstream ss(s);
        while (getline(ss, token, ' ')) {
            tokens.push_back(token);
        }
        return tokens;
    }
};

/**
1258. Synonymous Sentences
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given a list of equivalent string pairs synonyms where synonyms[i] = [si, ti] indicates that 
si and ti are equivalent strings. You are also given a sentence text.

Return all possible synonymous sentences sorted lexicographically.

 

Example 1:

Input: synonyms = [["happy","joy"],["sad","sorrow"],["joy","cheerful"]], text = "I am happy today but was sad yesterday"
Output: ["I am cheerful today but was sad yesterday","I am cheerful today but was sorrow yesterday",
"I am happy today but was sad yesterday","I am happy today but was sorrow yesterday",
"I am joy today but was sad yesterday","I am joy today but was sorrow yesterday"]

Example 2:

Input: synonyms = [["happy","joy"],["cheerful","glad"]], text = "I am happy today but was sad yesterday"
Output: ["I am happy today but was sad yesterday","I am joy today but was sad yesterday"]
 */
