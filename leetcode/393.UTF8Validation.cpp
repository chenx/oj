class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        for (int i = 0; i < n; ++ i) {
            int byte = data[i] & 0xFF;
            if (byte >> 7 == 0) {
                continue;
            } else if (byte >> 5 == 6 && i < n-1) {
                int byte2 = data[++ i] & 0xFF;
                if (byte2 >> 6 == 2) {
                    continue;
                }
            } else if (byte >> 4 == 14 && i < n-2) {
                int byte2 = data[++ i] & 0xFF;
                int byte3 = data[++ i] & 0xFF;
                if (byte2 >> 6 == 2 && byte3 >> 6 == 2) {
                    continue;
                }
            } else if (byte >> 3 == 30 && i < n-3) {
                int byte2 = data[++ i] & 0xFF;
                int byte3 = data[++ i] & 0xFF;
                int byte4 = data[++ i] & 0xFF;
                if (byte2 >> 6 == 2 && byte3 >> 6 == 2 && byte4 >> 6 == 2) {
                    continue;
                }
            }
            return false;
        }
        return true;
    }
};


/**
393. UTF-8 Validation
Medium

Given an integer array data representing the data, return whether it is a valid UTF-8 encoding (i.e. it translates 
to a sequence of valid UTF-8 encoded characters).

A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

    For a 1-byte character, the first bit is a 0, followed by its Unicode code.
    For an n-bytes character, the first n bits are all one's, the n + 1 bit is 0, followed by n - 1 bytes with the 
most significant 2 bits being 10.

This is how the UTF-8 encoding would work:

     Number of Bytes   |        UTF-8 Octet Sequence
                       |              (binary)
   --------------------+-----------------------------------------
            1          |   0xxxxxxx
            2          |   110xxxxx 10xxxxxx
            3          |   1110xxxx 10xxxxxx 10xxxxxx
            4          |   11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

x denotes a bit in the binary form of a byte that may be either 0 or 1.

Note: The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. 
This means each integer represents only 1 byte of data.
 */
