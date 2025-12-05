// 1 iteration.
// Time: O(n)
// Space: O(3) =~ O(1)
class Solution {
public:
    string largestGoodInteger(string num) {
        string result;

        char cur = num[0];
        int count = 1;
        for (int i = 1; i < num.length(); ++ i) {
            if (cur == num[i]) {
                ++ count;
                if (count == 3) {
                    if (result == "" || cur > result[0]) {
                        result = string(3, cur);
                    }
                }
            } else {
                cur = num[i];
                count = 1;
            }
        }
        return result;
    }
};


/**
2264. Largest 3-Same-Digit Number in String
Easy


You are given a string num representing a large integer. An integer is good if it meets the following conditions:

    It is a substring of num with length 3.
    It consists of only one unique digit.

Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

    A substring is a contiguous sequence of characters within a string.
    There may be leading zeroes in num or a good integer.

 

Example 1:

Input: num = "6777133339"
Output: "777"
Explanation: There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".

Example 2:

Input: num = "2300019"
Output: "000"
Explanation: "000" is the only good integer.

Example 3:

Input: num = "42352338"
Output: ""
Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.
 */
