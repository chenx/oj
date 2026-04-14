#include <cctype>
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> result;
        set<string> wordSet = set(wordlist.begin(), wordlist.end());

        map<string, string> lcaseWordMap;
        for (const string& word : wordlist) {
            string word_lower = tolower(word);
            if (! lcaseWordMap.contains(word_lower)) {
                lcaseWordMap[word_lower] = word;
            }
        }
        // cout << "\n==> lcaseWordMap:" << endl;
        // for (const auto& [k, v] : lcaseWordMap) cout << k << ":" << v << endl;

        map<string, string> noVowelMap;
        for (const string& word : wordlist) {
            string word_no_vowel = removeVowel(word);
            if (! noVowelMap.contains(word_no_vowel)) {
                noVowelMap[word_no_vowel] = word;
            }
        }
        // cout << "\n==> noVowelMap:" << endl;
        // for (const auto& [k, v] : noVowelMap) cout << k << ":" << v << endl;

        for (const auto& query : queries) {
            if (wordSet.contains(query)) {
                result.push_back(query);
                continue;
            }

            string query_lower = tolower(query);
            if (lcaseWordMap.contains(query_lower)) {
                result.push_back(lcaseWordMap[query_lower]);
                continue;
            }

            string query_no_vowel = removeVowel(query);
            if (noVowelMap.contains(query_no_vowel)) {
                result.push_back(noVowelMap[query_no_vowel]);
                continue;
            }

            result.push_back("");
        }

        return result;
    }

    string removeVowel(string data) {
        string result;
        string vowels = "aeiou";
        for (char ch : data) {
            // ch = (ch >= 'A' && ch <= 'Z') ? (ch - 'A' + 'a') : ch;
            ch = std::tolower(ch);
            if (vowels.find(ch) == string::npos) result += ch;
            else result += 'a'; // replace all vowels by 'a'.
        }
        return result;
    }

    string tolower(string data) {
        string result;
        for (char ch : data) {
            // result += (ch >= 'A' && ch <= 'Z') ? (ch - 'A' + 'a') : ch;
            result += std::tolower(ch);
        }
        return result;
    }
};


/**
966. Vowel Spellchecker
Solved
Medium
Topics
conpanies iconCompanies

Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.

For a given query word, the spell checker handles two categories of spelling mistakes:

    Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word 
    is returned with the same case as the case in the wordlist.
        Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
        Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
        Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
    Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel 
    individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with 
    the same case as the match in the wordlist.
        Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
        Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
        Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)

In addition, the spell checker operates under the following precedence rules:

    When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
    When the query matches a word up to capitalization, you should return the first such match in the wordlist.
    When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
    If the query has no matches in the wordlist, you should return the empty string.

Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].

 

Example 1:

Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]

Example 2:

Input: wordlist = ["yellow"], queries = ["YellOw"]
Output: ["yellow"]
 */
