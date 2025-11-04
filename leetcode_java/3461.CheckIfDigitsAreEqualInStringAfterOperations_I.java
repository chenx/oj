
class Solution {
    public boolean hasSameDigits(String s) {
        char[] sArr = s.toCharArray();
        int[] arr = new int[sArr.length];
        for (int i = 0; i < sArr.length; ++ i) {
            arr[i] = sArr[i] - '0';
        }
        
        while (arr.length > 2) {
            int n = arr.length;
            int[] arr2 = new int[n - 1];
            for (int i = 0; i < n - 1; ++ i) {
                arr2[i] = (arr[i] + arr[i+1]) % 10;
            }
            arr = arr2;
        }
        return arr[0] == arr[1];
    }
}

/**
3461. Check If Digits Are Equal in String After Operations I
Easy

You are given a string s consisting of digits. Perform the following operation repeatedly until the string has exactly two digits:

    For each pair of consecutive digits in s, starting from the first digit, calculate a new digit as the sum of the two digits modulo 10.
    Replace s with the sequence of newly calculated digits, maintaining the order in which they are computed.

Return true if the final two digits in s are the same; otherwise, return false.
 */
