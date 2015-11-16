// This works, but tims out for large tests.
public class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        List<String> list = new ArrayList<String>();
        if (board.length == 0 || board[0].length == 0) return list;
        
        for (int i = 0; i < words.length; ++ i) {
            if (find(board, words[i])) list.add(words[i]);
        }
        
        return list;
    }
    
    private boolean find(char[][] board, String word) {
        if (word.length() == 0) return true;
        int rows = board.length, cols = board[0].length;
        
        for (int i = 0; i < rows; ++ i) {
            for (int j = 0; j < cols; ++ j) {
                if (board[i][j] == word.charAt(0)) {
                    if (search(board, i, j, word, 0)) return true;
                }
            }
        }
        
        return false;
    }
    
    // Be careful of boundary.
    boolean search(char[][] board, int i, int j, String word, int pos) {
        if (pos == word.length() - 1) return true;

        int rows = board.length, cols = board[0].length;

        ++ pos;
        char c = word.charAt(pos);
        if (i > 0 && c == board[i-1][j]) {
            if (search(board, i-1, j, word, pos)) return true;
        }
        if (i < rows - 1 && c == board[i+1][j]) {
            if (search(board, i+1, j, word, pos)) return true;
        }
        if (j > 0 && c == board[i][j-1]) {
            if (search(board, i, j-1, word, pos)) return true;
        }
        if (j < cols - 1 && c == board[i][j+1]) {
            if (search(board, i, j+1, word, pos)) return true;
        }
        
        return false;       
    }
}

/**
Word Search II
Difficulty: Hard

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

Return ["eat","oath"].

Note:
You may assume that all inputs are consist of lowercase letters a-z.

click to show hint.

You would need to optimize your backtracking to pass the larger test. 
Could you stop backtracking earlier?

If the current candidate does not exist in all words' prefix, you could 
stop backtracking immediately. What kind of data structure could answer 
such query efficiently? Does a hash table work? Why or why not? 
How about a Trie? If you would like to learn how to implement a basic trie, 
please work on this problem: Implement Trie (Prefix Tree) first.

 */
