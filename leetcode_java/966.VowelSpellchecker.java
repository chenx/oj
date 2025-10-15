// Note the use of "putIfAbsent" and getOrDefault.
class Solution {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        int n = queries.length;
        String[] ret = new String[n];

        HashSet<String> set = new HashSet<>();
        for (String word : wordlist) set.add(word);

        HashMap<String, String> map = new HashMap<>();
        for (String word : wordlist) map.putIfAbsent(word.toLowerCase(), word);

        HashMap<String, String> mapNoVowel = new HashMap<>();
        for (String word : wordlist) mapNoVowel.putIfAbsent(removeVowel(word.toLowerCase()), word);

        for (int i = 0; i < n; ++ i) {
            String query = queries[i];

            if (set.contains(query)) {
                ret[i] = query;
            } else if (map.containsKey(query.toLowerCase())) {
                ret[i] = map.get(query.toLowerCase());
            } else {
                query = removeVowel(query.toLowerCase());
                ret[i] = mapNoVowel.getOrDefault(query, "");
            }
        }
        return ret;
    }

    String removeVowel(String s) {
        char[] arr = s.toCharArray();
        for (int i = 0; i < arr.length; ++ i) {
            if (isVowel(arr[i])) arr[i] = '*';
        }
        return new String(arr);
    }

    boolean isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
}

/**
966. Vowel Spellchecker

Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.

For a given query word, the spell checker handles two categories of spelling mistakes:

    Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word 
    is returned with the same case as the case in the wordlist.
        Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
        Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
        Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
    Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel 
    individually, it matches a word in the wordlist (case-insensitive), then the query word is returned 
    with the same case as the match in the wordlist.
        Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
        Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
        Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)

In addition, the spell checker operates under the following precedence rules:

    When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
    When the query matches a word up to capitalization, you should return the first such match in the wordlist.
    When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
    If the query has no matches in the wordlist, you should return the empty string.

Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].
 */
