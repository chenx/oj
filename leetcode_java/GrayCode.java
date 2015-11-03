// This works.
// Note: if use "List<Integer> codes = new ArrayList<Integer>(len);",
// then still have to use "add", not set(i, elem), since it does not 
// initialize the array, just set a initial capacity.
public class Solution {
    public List<Integer> grayCode(int n) {
        int len = 1 << n;
        List<Integer> codes = new ArrayList<Integer>(); 
        for (int i = 0; i < len; ++ i) {
            codes.add(i ^ (i >> 1));
        }
        return codes;
    }
}

/**
Gray Code
Difficulty: Medium

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, 
print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 */
