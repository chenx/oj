class Solution {
    public int compress(char[] chars) {
        if (chars.length == 0) return 0;

        String s = "";
        char cur = chars[0];
        int count = 1;
        for (int i = 1; i < chars.length; ++ i) {
            if (cur == chars[i]) {
                ++ count;
            } else {
                s += cur + (count > 1 ? String.valueOf(count) : "");
                cur = chars[i];
                count = 1;
            }
        }
        s += cur + (count > 1 ? String.valueOf(count) : "");

        int n = s.length();
        // chars = new char[n]; // This causes error. Shouldn't be used.
        for (int i = 0; i < n; ++ i) {
            chars[i] = s.charAt(i);
        }

        return n;
    }
}

/**
443. String Compression

Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

    If the group's length is 1, append the character to s.
    Otherwise, append the character followed by the group's length.

The compressed string s should not be returned separately, but instead, be stored in the input character 
array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

Note: The characters in the array beyond the returned length do not matter and should be ignored.
 */
