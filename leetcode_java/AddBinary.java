/**
 * Given two binary strings, return their sum (also a binary string).
 * For example,
 * a = "11"
 * b = "1"
 * Return "100". 
 */
 
// This works too. Is better.
public class Solution {
    private int carry;

    public String addBinary(String a, String b) {
        StringBuffer s = new StringBuffer("");
        
        int ia = a.length() - 1, ib = b.length() - 1;
        carry = 0;
        
        for (; ia >= 0 && ib >= 0; -- ia, -- ib) {
            s.append("" + add(a.charAt(ia) - '0' + b.charAt(ib) - '0' + carry));
        }
        for (; ia >= 0; -- ia) {
            s.append("" + add(a.charAt(ia) - '0' + carry));
        }
        for (; ib >= 0; -- ib) {
            s.append("" + add(b.charAt(ib) - '0' + carry));
        }
        
        if (carry > 0) {
            s.append("" + carry);
        }
        
        s.reverse();
        return s.toString();
    }
    
    private int add(int sum) {
        if (sum > 1) {
            sum -= 2;
            carry = 1;
        }
        else {
            carry = 0;
        }

        return sum;
    }
}

// This works.
public class Solution {
    private int sum;
    private int carry;
    private StringBuffer s;
    
    public String addBinary(String a, String b) {
        s = new StringBuffer("");
        
        int ia = a.length() - 1, ib = b.length() - 1;
        
        for (; ia >= 0 && ib >= 0; -- ia, -- ib) {
            add(a.charAt(ia) - '0' + b.charAt(ib) - '0' + carry);
        }
        for (; ia >= 0; -- ia) {
            add(a.charAt(ia) - '0' + carry);
        }
        for (; ib >= 0; -- ib) {
            add(b.charAt(ib) - '0' + carry);
        }
        
        if (carry > 0) {
            s.append("" + carry);
        }
        
        s.reverse();
        return s.toString();
    }
    
    private void add(int thesum) {
        if (thesum > 1) { // note by change value "1" here, you can adapt this to base-n addition.
            sum = thesum - 2;
            carry = 1;
        }
        else {
            sum = thesum;
            carry = 0;
        }

        s.append(Integer.toString(sum));
        s.append("" + sum);
    }
}
