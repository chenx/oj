class AutocompleteSystem2 {
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        unordered_map<string, int> sentenceCount; // <sentence, count>

        TrieNode* insert(char ch) {
            if (! children.contains(ch)) {
                children[ch] = new TrieNode();
            }
            return children[ch];
        }

        TrieNode* find(char ch) {
            return children.contains(ch) ? children[ch] : nullptr;
        }
    };

    TrieNode root;
    TrieNode* curNode;
    TrieNode* deadNode;
    string curSentence;

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        int n = sentences.size();
        for (int i = 0; i < n; ++ i) {
            insert(sentences[i], times[i]);
        }
        curNode = &root;
        deadNode = new TrieNode();
    }
    
    vector<string> input(char c) {
        vector<string> result;

        if (c == '#') {
            insert(curSentence, 1);
            curSentence.clear();
            curNode = &root;
            return result;
        }

        curSentence.push_back(c);
        if (! curNode->children.contains(c)) {
            curNode = deadNode;
            return result;
        }

        // get top 3 sentences.
        curNode = curNode->children[c];

        auto comp = [&](const string& a, const string& b) {
            int ct1 = curNode->sentenceCount[a], ct2 = curNode->sentenceCount[b];
            if (ct1 == ct2) return a < b; // larger ascii order first.
            return ct1 > ct2; // smaller count first.
        };
        priority_queue<string, vector<string>, decltype(comp)> minHeap(comp);

        for (auto& [sentence, _] : curNode->sentenceCount) {
            minHeap.push(sentence);
            if (minHeap.size() > 3) minHeap.pop(); // optimization if count is large.
        }

        // int ct = 0;
        // while (! minHeap.empty() && ++ ct <= 3) {
        while (! minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }

private:
    void insert(string& sentence, int time) {
        TrieNode* node = &root;
        for (char ch : sentence) {
            TrieNode* child = node->find(ch);
            if (! child) {
                child = node->insert(ch);
            }
            child->sentenceCount[sentence] += time;
            node = child;
        }
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */



// See: https://leetcode.com/problems/design-search-autocomplete-system/editorial/
// Time complexity: O(n⋅k+m⋅(n+(m/k)​))
// Space complexity: O(k⋅(n⋅k+m))
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    unordered_map<string, int> sentences;
};

class AutocompleteSystem {
private:
    TrieNode* root;
    TrieNode* curNode;
    TrieNode* dead;
    string curSentence;

    void addToTrie(const string& sentence, int count) {
        TrieNode* node = root;

        for (char c : sentence) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }

            node = node->children[c];
            node->sentences[sentence] += count;
        }
    }

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();

        for (int i = 0; i < sentences.size(); i++) {
            addToTrie(sentences[i], times[i]);
        }

        curSentence = "";
        curNode = root;
        dead = new TrieNode();
    }

    vector<string> input(char c) {
        if (c == '#') {
            addToTrie(curSentence, 1);

            curSentence = "";
            curNode = root;

            return {};
        }

        curSentence += c;

        if (!curNode->children.count(c)) {
            curNode = dead;
            return {};
        }

        curNode = curNode->children[c];

        vector<pair<string, int>> candidates(
            curNode->sentences.begin(),
            curNode->sentences.end()
        );

        sort(candidates.begin(), candidates.end(),
             [](const pair<string, int>& a,
                const pair<string, int>& b) {
                 if (a.second == b.second) {
                     return a.first < b.first;
                 }
                 return a.second > b.second;
             });

        vector<string> result;

        for (int i = 0; i < min(3, (int)candidates.size()); i++) {
            result.push_back(candidates[i].first);
        }

        return result;
    }
};


/**
642. Design Search Autocomplete System
Solved
Hard
Topics
conpanies iconCompanies

Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and 
end with a special character '#').

You are given a string array sentences and an integer array times both of length n where sentences[i] is a 
previously typed sentence and times[i] is the corresponding number of times the sentence was typed. For each 
input character except '#', return the top 3 historical hot sentences that have the same prefix as the part 
of the sentence already typed.

Here are the specific rules:

    The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
    The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If 
        several sentences have the same hot degree, use ASCII-code order (smaller one appears first).
    If less than 3 hot sentences exist, return as many as you can.
    When the input is a special character, it means the sentence ends, and in this case, you need to return 
        an empty list.

Implement the AutocompleteSystem class:

    AutocompleteSystem(String[] sentences, int[] times) Initializes the object with the sentences and times arrays.
    List<String> input(char c) This indicates that the user typed the character c.
        Returns an empty array [] if c == '#' and stores the inputted sentence in the system.
        Returns the top 3 historical hot sentences that have the same prefix as the part of the sentence already 
            typed. If there are fewer than 3 matches, return them all.

 

Example 1:

Input
["AutocompleteSystem", "input", "input", "input", "input"]
[[["i love you", "island", "iroman", "i love leetcode"], [5, 3, 2, 2]], ["i"], [" "], ["a"], ["#"]]
Output
[null, ["i love you", "island", "i love leetcode"], ["i love you", "i love leetcode"], [], []]
 */
