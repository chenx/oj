public class Solution {
    public String convert(String s, int numRows) {
        String[] v = new String[numRows];
        Arrays.fill(v, "");  // pay attention of this.
        int k = 0, len = s.length();
        
        while (k < len) {
            for (int i = 0; i < numRows && k < len; ++ i) {
                v[i] += s.charAt(k); ++ k;
            }
            for (int i = numRows - 2; i > 0 && k < len; -- i) {
                v[i] += s.charAt(k); ++ k; 
            }
        }
        
        String ans = "";
        for (int i = 0; i < numRows; ++ i) {
            ans += v[i];
        }
        
        return ans;        
    }
}


/**
ZigZag Conversion
Difficulty: Easy

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number 
of rows like this: (you may want to display this pattern in a fixed font for 
better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
 */
