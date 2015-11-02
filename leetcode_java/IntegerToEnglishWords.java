public class Solution {
    public String numberToWords(int num) {
        if (num == 0) return "Zero";
        if (num < 0) return "Negative " + numberToWords(- num);
        
        String s = "";
        int pos = 0;
        while (num > 0) {
            int v = num % 1000;
            s = append(convert(v, pos ++), s);
            num /= 1000; 
        }
        
        return s;
    }
    
    // v is 3 digits.
    String convert(int v, int pos) {
        if (v == 0) return "";
        
        String s = "";
        
        if (v <= 20) s = convertD(v, 0);
        else {
            if (v >= 100) {
                int d = (v / 100);
                s = convertD(d, 2);
                v -= d * 100;
            }
            
            if (v <= 20) s = append(s, convertD(v, 0));
            else {
                s = append(s, convertD(v / 10, 1));
                s = append(s, convertD(v % 10, 0));
            }
            
        }
        
        switch (pos) {
            case 0: break;
            case 1: s += " Thousand"; break;
            case 2: s += " Million"; break;
            case 3: s += " Billion"; break;
        }
        
        return s.trim();
    }
    
    String append(String a, String b) {
        return (a.trim() + " " + b).trim();
    }
    
    String convertD(int d, int p) {
        String s = "";
        if (p == 0) {
            switch (d) {
                case 0: s = ""; break;
                case 1: s = "One"; break;
                case 2: s = "Two"; break;
                case 3: s = "Three"; break;
                case 4: s = "Four"; break;
                case 5: s = "Five"; break;
                case 6: s = "Six"; break;
                case 7: s = "Seven"; break;
                case 8: s = "Eight"; break;
                case 9: s = "Nine"; break;
                case 10: s = "Ten"; break;
                case 11: s = "Eleven"; break;
                case 12: s = "Twelve"; break;
                case 13: s = "Thirteen"; break;
                case 14: s = "Fourteen"; break;
                case 15: s = "Fifteen"; break;
                case 16: s = "Sixteen"; break;
                case 17: s = "Seventeen"; break;
                case 18: s = "Eighteen"; break;
                case 19: s = "Nineteen"; break;
                case 20: s = "Twenty"; break;
                default: s = "?"; break;
            }
        }
        else if (p == 1) {
            switch (d) {
                //case 0: s = ""; break;
                //case 1: s = "Ten"; break;
                case 2: s = "Twenty"; break;
                case 3: s = "Thirty"; break;
                case 4: s = "Forty"; break;
                case 5: s = "Fifty"; break;
                case 6: s = "Sixty"; break;
                case 7: s = "Seventy"; break;
                case 8: s = "Eighty"; break;
                case 9: s = "Ninety"; break;
                default: s = "?"; break;
            }
        }
        else if (p == 2) {
            switch (d) {
                case 0: s = ""; break;
                case 1: s = "One"; break;
                case 2: s = "Two"; break;
                case 3: s = "Three"; break;
                case 4: s = "Four"; break;
                case 5: s = "Five"; break;
                case 6: s = "Six"; break;
                case 7: s = "Seven"; break;
                case 8: s = "Eight"; break;
                case 9: s = "Nine"; break;
                default: s = "?"; break;
            }
            s += " Hundred";
        }
        
        return s;
    }
}


/**
Integer to English Words
Difficulty: Medium

Convert a non-negative integer to its english words representation. 
Given input is guaranteed to be less than 231 - 1.

For example,

123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

Hint:

    Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
    Group the number by thousands (3 digits). You can write a helper function 
        that takes a number less than 1000 and convert just that chunk to words.
    There are many edge cases. What are some good test cases? Does your code 
        work with input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)

 */
