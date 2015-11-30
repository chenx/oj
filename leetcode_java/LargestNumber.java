public class Solution {
    public String largestNumber(int[] nums) {
        int len = nums.length;
        String[] v = new String[len];
        
        for (int i = 0; i < len; ++ i) { 
            v[i] = "" + nums[i];
        }
        Arrays.sort(v, new Comp());
        
        StringBuilder s = new StringBuilder();
        int i = 0;
        for (; i < len && v[i].equals("0"); ++ i) {}
        for (; i < len; ++ i) s.append(v[i]);
        
        String ans = s.toString();
        if (ans.equals("")) ans = "0";
        return ans;
    }
    
    class Comp implements Comparator<String> {
        @Override
        public int compare(String a, String b) {
            return - (a + b).compareTo(b + a);
        }
    }
}

/**
Largest Number
Difficulty: Medium

Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
 */
