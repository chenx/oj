// Works. Tested. Slightly modified from Solution2.
class Solution3 {
public:
    string readPart(int input) {
        vector<string> digits = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"};
        vector<string> teens = {" Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
        vector<string> tens = {"", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
        string res;

        string s;
        int hundred = input / 100; // digit on hundreds.
        if (hundred != 0) s = digits[hundred] + " Hundred";
        
        input %= 100;
        int ten = input / 10;   // digit on tens.
        int digit = input % 10; // digit on ones.

        if (ten >= 2) s += tens[ten] + digits[digit];
        else if (ten == 1) s += teens[digit];
        else s += digits[digit];

        return s;
    }
    
    string numberToWords(int num) {
        vector<string> units = {"", " Thousand", " Million", " Billion"};

        string ans;
        for (int i = 0; i < 4; ++ i) {
            int part = num % 1000;
            if (part != 0) { // note this!
                ans = readPart(part) + units[i] + ans;
            }
            num /= 1000;
            if (num == 0) break;
        }
        
        if (ans == "") ans = "Zero";
        else ans = ans.substr(1); // remove starting space.
        
        return ans;
    }
};

// Works. Tested.
// From: https://leetcode.com/discuss/76029/c-solution-easy-understanding
class Solution2 {
public:
    string readThousand(int input) {
        assert(input < 1000);
        string res;
        vector<string> digitToStr = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"};
        vector<string> teensToStr = {" Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
        vector<string> tysToStr = {"", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
        int hun = input / 100;
        if (hun >= 1) res += digitToStr[hun] + " Hundred";
        input %= 100;
        int tens = input / 10;
        input %= 10;
    //    cout << "input here is " << input << endl;
        if (tens == 1) {res += teensToStr[input]; return res; }
        if (tens > 1) res += tysToStr[tens];
        res += digitToStr[input];
        return res;
    }
    
    string numberToWords(int num) {
        vector<int> parts(4, 0);
        string res;
        vector<string> thous = {"", " Thousand", " Million", " Billion"};
        for (int i = 0; i < 4; i++) {
            parts[i] = num % 1000;
            if (parts[i] > 0) res = readThousand(parts[i]) + thous[i] + res;
            num /= 1000;
            if (num == 0) break;
        }
        if (res.empty()) return "Zero";
        return res.substr(1);
    }

};

// Works. Just too long.
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        if (num < 0) return "Negative " + numberToWords(- num);
        
        string s = "";
        int pos = 0;
        while (num > 0) {
            int v = num % 1000;
            s = append(convert(v, pos ++), s);
            num /= 1000; 
        }
        
        return s;
    }
    
    // v is 3 digits.
    string convert(int v, int pos) {
        if (v == 0) return "";
        
        string s = "";
        
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
        
        return trim(s);
    }
    
    string append(string a, string b) {
        string x = trim(a) + " " + b;
        return trim(x);
    }
    
    string convertD(int d, int p) {
        string s = "";
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
    
    //
    // For trim functions, see:
    // http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
    // 
    static inline std::string &ltrim(std::string &s) {
            s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
            return s;
    }
    
    // trim from end
    static inline std::string &rtrim(std::string &s) {
            s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
            return s;
    }
    
    // trim from both ends
    static inline std::string &trim(std::string &s) {
            return ltrim(rtrim(s));
    }    
};

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
