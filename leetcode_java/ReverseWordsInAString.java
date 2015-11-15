// This works. 
// Modified from: https://leetcode.com/discuss/66229/java-solution-time-o-n-space-o-1
// Things to note: 1) trim, and replace multiple spaces to one space. 2) double reverse.
public class Solution {
    public String reverseWords(String s) {
        s = s.trim().replaceAll("\\s+", " ");
        if(s.length() == 0) return "";
        
        char[] arr = s.toCharArray();
        reverse(arr, 0, arr.length - 1);
        
        int start = 0;
        for (int i = 0; i < arr.length; ++ i){
            if(arr[i] == ' '){
                reverse(arr, start, i-1);
                start = i+1;
            }
        }
        reverse(arr, start, arr.length - 1);
        
        return new String(arr);
    }
    
    private static void reverse(char[] arr, int i, int j){
        for (; i < j; ++ i, -- j){
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

/**
Reverse Words in a String
Difficulty: Medium

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.
Clarification:

    What constitutes a word?
    A sequence of non-space characters constitutes a word.
    Could the input string contain leading or trailing spaces?
    Yes. However, your reversed string should not contain leading or trailing spaces.
    How about multiple spaces between two words?
    Reduce them to a single space in the reversed string.

 */
