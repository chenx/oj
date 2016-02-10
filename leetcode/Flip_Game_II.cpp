// see: 
// - https://leetcode.com/discuss/64344/theory-matters-from-backtracking-128ms-to-dp-0ms
// - https://leetcode.com/discuss/oj/flip-game-ii

// DFS, Recursive. This works too. Tested.
class Solution3 {
public:
    bool canWin(string s) {
        for (int i = 0, len = s.length() - 1; i < len; ++ i) {
            if (s[i] == '+' && s[i+1] == '+') {
                s[i] = s[i+1] = '-';
                if (! canWin(s)) return true; // works too if move this 1 line below.
                s[i] = s[i+1] = '+';
            }
        }
        return false;
    }
};

// DFS. Works. Tested.
class Solution2 {
public:
    int len;
    string ss;
    bool canWin(string s) {
        len = s.size();
        ss = s;
        return canWin();
    }
    bool canWin() {
        for (int is = 0; is <= len-2; ++is) {
            if (ss[is] == '+' && ss[is+1] == '+') {
                ss[is] = '-'; ss[is+1] = '-';
                bool wins = !canWin(); 
                ss[is] = '+'; ss[is+1] = '+';
                if (wins) return true; // note: if move this one line above, it won't work. Why?
            }
        }
        return false;
    } 
};

// DP. Works.
class Solution {
public:
    int firstMissingNumber(unordered_set<int> lut) {
        int m = lut.size();
        for (int i = 0; i < m; ++i) {
            if (lut.count(i) == 0) return i;
        }
        return m;
    }
    
    bool canWin(string s) {
        int curlen = 0, maxlen = 0;
        vector<int> board_init_state;
        for (int i = 0; i < s.size(); ++i) {    
            if (s[i] == '+') curlen++;              // Find the length of all continuous '+' signs
            if (i+1 == s.size() || s[i] == '-') {
                if (curlen >= 2) board_init_state.push_back(curlen);    // only length >= 2 counts
                maxlen = max(maxlen, curlen);       // Also get the maximum continuous length
                curlen = 0;
            }
        }          // For instance ++--+--++++-+ will be represented as (2, 4)
        vector<int> g(maxlen+1, 0);    // Sprague-Grundy function of 0 ~ maxlen
        for (int len = 2; len <= maxlen; ++len) {
            unordered_set<int> gsub;    // the S-G value of all subgame states
            for (int len_first_game = 0; len_first_game < len/2; ++len_first_game) {
                int len_second_game = len - len_first_game - 2;
                // Theorem 2: g[game] = g[subgame1]^g[subgame2]^g[subgame3]...;
                gsub.insert(g[len_first_game] ^ g[len_second_game]);
            }
            g[len] = firstMissingNumber(gsub);
        }
    
        int g_final = 0;
        for (auto& s: board_init_state) g_final ^= g[s];
        return g_final != 0;    // Theorem 1: First player must win iff g(current_state) != 0
     }
 };
 
 /**
 Flip Game II
Difficulty: Easy

Given a string that contains only + or - characters, 
each player takes turn to flip two consecutive "++" to "--".

The player who could not make a move loses.

Write a function that determines if the starting player can guarantee a win.

An example of a valid input string is "---++----++-+"
  */
