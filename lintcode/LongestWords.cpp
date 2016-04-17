class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> ans;
        int maxLen = 0;
        for (auto w : dictionary) {
            if (w.length() >= maxLen) {
                if (w.length() > maxLen) {
                    ans.clear();
                    maxLen = w.length();
                }
                ans.push_back(w);
            }
        }
        return ans;
    }
};


/**
Longest Words

Given a dictionary, find all of the longest words in the dictionary.
Have you met this question in a real interview?
Example

Given

{
  "dog",
  "google",
  "facebook",
  "internationalization",
  "blabla"
}

the longest words are(is) ["internationalization"].

Given

{
  "like",
  "love",
  "hate",
  "yes"
}

the longest words are ["like", "love", "hate"].
Challenge

It's easy to solve it in two passes, can you do it in one pass?

 */
