//
// word ladder.
//
// @Author: Xin Chen
// @Created on: 3/9/2013
// @Last modified: 4/7/2013
//

// Works. Best.
class Solution3 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) return 0;

        set<string> words(wordList.begin(), wordList.end());

        set<string> used;
        queue<pair<string, int>> q; // word, dist
        used.insert(beginWord);
        q.push({beginWord, 1});

        while (!q.empty()) {
            string word = q.front().first;
            int dist = q.front().second;
            q.pop();

            for (int i = 0; i < word.length(); ++ i) {
                char c = word[i];

                for (char d = 'a'; d <= 'z'; ++ d) {
                    if (d == c) continue;
                    word[i] = d;

                    if (words.contains(word) && ! used.contains(word)) {
                        if (word == endWord) return dist + 1;  // return here early insetad of after q.pop().
                        used.insert(word);
                        q.push({word, dist + 1});
                    }
                }
                word[i] = c;
            }
        }

        return 0;
    }
};

class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) return 1;
        unordered_set<string> words;
        for (auto w: wordList) words.insert(w);
        if (!words.contains(endWord)) return 0;
        
        queue<pair<string, int>> q;
        q.push(pair<string, int>(beginWord, 1));
        
        unordered_set<string> used;
        used.insert(beginWord);
        
        while (! q.empty()) {
            string w = q.front().first;
            int dist = q.front().second + 1; // use +1
            q.pop(); // don't forget this.
            
            for (int i = 0; i < w.length(); ++ i) {
                char backup = w[i];
                for (char c = 'a'; c <= 'z'; ++ c) {
                    w[i] = c;
                    
                    if (w == endWord) return dist;
                    else {
                        if (words.count(w) && ! used.count(w)) {
                            q.push(pair<string, int>(w, dist));
                            used.insert(w); // don't forget this.
                        }
                    }
                }
                w[i] = backup;
            }
        }

        return 0;
    }
};

// Works. 2025-09-02
class Solution6 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord.length() != endWord.length()) return 1;
        unordered_set<string> words;
        for (auto w: wordList) words.insert(w);
        if (!words.contains(endWord)) return 0;

        int n = beginWord.length(), len = 0;

        queue<pair<string, int>> q;
        q.push(pair<string, int>(beginWord, 1));

        unordered_set<string> used;
        used.insert(beginWord);

        while (!q.empty()) {
            string s = q.front().first;
            int len = q.front().second;
            q.pop();

            for (int i = 0; i < n; ++ i) {
                char usedChar = s[i];
                for (char c = 'a'; c <= 'z'; ++ c) {
                    if (c == usedChar) continue;
                    s[i] = c;

                    // This is BFS, so first found path is the shortest.
                    if (s == endWord) return len + 1;

                    if (!used.contains(s) && words.contains(s)) {
                        used.insert(s);
                        q.push(pair<string, int>(s, len + 1));
                    }
                }
                s[i] = usedChar;
            }
        }

        return 0;
    }
};

// Works. May be best so far.
class Solution5 {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (beginWord == endWord) return 1;
        if (!wordList.contains(endWord)) return 0;
        
        queue<pair<string, int>> q;
        q.push(pair<string, int>(beginWord, 1));
        
        unordered_set<string> used;
        used.insert(beginWord);
        
        while (! q.empty()) {
            string w = q.front().first;
            int dist = q.front().second + 1; // use +1
            q.pop(); // don't forget this.
            
            for (int i = 0; i < w.length(); ++ i) {
                char backup = w[i];
                for (char c = 'a'; c <= 'z'; ++ c) {
                    w[i] = c;
                    
                    if (w == endWord) return dist;
                    else {
                        if (wordList.count(w) && ! used.count(w)) {
                            q.push(pair<string, int>(w, dist));
                            used.insert(w); // don't forget this.
                        }
                    }
                }
                w[i] = backup;
            }
        }

        return 0;
    }
};

/*
   1164 ms for large test set.
   Note: the part to get length can also be:
                        int len = 1;
                        for (WW * x = z; x->prev; x = x->prev) {
                            ++ len;
                        }
                        ++ len;
                        
                        if (min_len == 0 || min_len > len) {
                            min_len = len;
                        }
 */
class WW {
public:
    string w;
    WW * prev;
    WW(string _w, WW * p) : w(_w), prev(p) { }
};

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<WW *> words;
        set<string> words_used;
        int min_len = 0;
        
        words.push(new WW(start, NULL));
        words_used.insert(start);
        
        while (words.size() > 0) {
            WW * z = words.front();
            words.pop();
            string w = z->w;
            
            int len = w.length();
            for (int i = 0; i < len; ++ i) {
                char c = w[i];
                for (int j = 0; j < 26; ++ j) {
                    if (c == 'a' + j) continue;
                    
                    w[i] = 'a' + j;
                    if (w == end) {
                        vector<string> a;
                        a.insert(a.begin(), end);

                        for (WW * x = z; x->prev; x = x->prev) {
                            a.insert(a.begin(), x->w);
                        }
                        a.insert(a.begin(), start);
                        
                        if (min_len == 0 || min_len > a.size()) {
                            min_len = a.size();
                        }
                        // break; // if only need to find one path, can just stop here.
                    }
                    else {
                        if (dict.find(w) != dict.end() 
                            && words_used.find(w) == words_used.end() ) {
                            words.push(new WW(w, z));
                            words_used.insert(w);
                        }
                    }
                    
                } // end of for
                w[i] = c;
            } // end of for
        }
        
        return min_len;
    }
};


//
// This works too. For this case, only need to keep length, not need to keep pointer.
//
class Solution2 {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> used; // store words used.
        queue<pair<string, int> > q;
        
        q.push(pair<string, int>(start, 1));
        used.insert(start);
        
        int minlen = 0;
        while (! q.empty()) {
            string t = q.front().first;
            int n = q.front().second;
            q.pop();
                        
            int L = t.length();
            for (int i = 0; i < L; ++ i) {
                char c = t[i];
                for (int j = 0; j < 26; ++ j) {
                    if (c == j + 'a') continue;
                    t[i] = j + 'a';
                    
                    if (t == end) {
                        if (minlen == 0 || minlen > n+1) { minlen = n + 1; } // directly return n+1 seems to work too! BFS, first found is min.
                    }
                    else if (used.find(t) == used.end() && dict.find(t) != dict.end()) {
                        q.push(pair<string, int>(t, n+1));
                        used.insert(t);                        
                    }
                } // end for
                t[i] = c; // recover t. Don't forget this!
            } // end for
        } // end while
        
        return minlen; // not found
    }
};


// This works too. Use a map to store (word, dist). Seems best. 11/4/2014
class Solution3 {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end) return 1;
        
        unordered_map<string, int> used; // record: 1) used words, 2) distance from start.
        used[start] = 1;
        
        queue<string> q; // For BFS.
        q.push(start);
        
        while (! q.empty()) {
            string s = q.front();
            int dist = used[s];
            q.pop();

            for (int i = 0; i < s.length(); ++ i) {
                char c = s[i];
                for (int j = 0; j < 26; ++ j) {
                    char c1 = 'a' + j;
                    if (c1 == c) { continue; }
                    
                    s[i] = c1;
                    if (s == end) { return dist + 1; }
                    if (dict.find(s) != dict.end() && used.find(s) == used.end()) {
                        q.push(s);
                        used[s] = dist + 1;
                    }
                }
                s[i] = c;
            }
        }
        
        return 0;
    }
};

// This works too.
class Solution4 {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (beginWord == endWord) return 1;
        queue<pair<string, int>> q; // <string, distance>
        unordered_set<string> used;
        int dist = 0;
        
        q.push(pair<string, int>(beginWord, 1));
        used.insert(beginWord);
        
        while (! q.empty()) {
            string s = q.front().first;
            int d = q.front().second;
            q.pop();
            
            for (int i = 0, len = s.length(); i < len; ++ i) {
                char c = s[i];
                for (int j = 0; j < 26; ++ j) {
                    if (c == 'a' + j) continue;

                    s[i] = 'a' + j;
                    
                    if (s == endWord) {
                        if (dist == 0 || dist > 1 + d) dist = 1 + d; // return 1 + d also works.
                    }
                    else {
                        if (wordList.find(s) != wordList.end() 
                            && used.find(s) == used.end()) {
                            q.push(pair<string, int>(s, 1 + d));
                            used.insert(s);
                        }
                    }
                } // end of for 
                s[i] = c; // recover s[i].
            } // end of for
        } // end of while
        
        return dist;
    }
};

/*
Problem:
        
 Given two words (start and end), and a dictionary, find the length of shortest 
 transformation sequence from start to end, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence. 
 */



