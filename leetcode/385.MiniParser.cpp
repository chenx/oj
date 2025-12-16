// Time: O(n^2)
// Space: O(n)
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty() || s == "[]") {
            return NestedInteger();  // Returns an empty nested list
        }
      
        if (s[0] != '[') {  // Handle single integer case (no brackets)
            return NestedInteger(stoi(s));  // Convert string to integer and return
        }
      
        // Handle nested list case
        NestedInteger result;  // Create empty nested list to hold elements
        int bracketDepth = 0;  // Track nesting level of brackets
      
        // Iterate through the string, skipping the first '[' and last ']'
        // startPos marks the beginning of current element
        for (int i = 1, startPos = 1; i < s.size(); ++i) {
            // When at the same nesting level (depth == 0) and found a delimiter
            if (bracketDepth == 0 && (s[i] == ',' || i == s.size() - 1)) {
                // Extract the substring representing current element
                string element = s.substr(startPos, i - startPos);
                // Recursively deserialize the element and add to result
                result.add(deserialize(element));
                // Move start position to next element (skip comma)
                startPos = i + 1;
            } 
            // Track bracket depth to identify elements at the same level
            else if (s[i] == '[') {
                ++bracketDepth;  // Entering a nested list
            } 
            else if (s[i] == ']') {
               --bracketDepth;  // Exiting a nested list
            }
        }
      
        return result;
    }
};


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/**
385. Mini Parser
Medium

Given a string s represents the serialization of a nested list, implement a parser to deserialize it and 
return the deserialized NestedInteger.

Each element is either an integer or a list whose elements may also be integers or other lists.

 

Example 1:

Input: s = "324"
Output: 324
Explanation: You should return a NestedInteger object which contains a single integer 324.

Example 2:

Input: s = "[123,[456,[789]]]"
Output: [123,[456,[789]]]
 */
