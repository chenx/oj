class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        // write your code here
        const char * p = str.c_str();
        while (isspace(*p)) ++ p;
        
        bool neg = false;
        if (*p == '-') ++ p, neg = true;
        else if (*p == '+') ++ p; 
        
        int v = 0, v0;
        while (isdigit(*p)) {
            v0 = v;
            v = v * 10 + *p - '0';
            if (v / 10 != v0) return neg ? INT_MIN : INT_MAX;
            ++ p;
        }
        
        if (neg) v = -v;
        return v;
    }
};


/**
String to Integer II

Implement function atoi to convert a string to an integer.

If no valid conversion could be performed, a zero value is returned.

If the correct value is out of the range of representable values, 
INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

Example

"10" => 10
"-1" => -1
"123123123123123" => 2147483647
"1.0" => 1


 */
