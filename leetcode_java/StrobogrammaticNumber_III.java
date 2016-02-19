// Works. Tested.
// From: https://leetcode.com/discuss/54562/clean-and-easy-java-recursive-solution
public class Solution {
    String map1 = "01689";
    String map2 = "01986";
    String map3 = "018";
    public int strobogrammaticInRange(String low, String high) {
        int[] count = new int[1];
        for(int i=low.length();i<=high.length();i++){
            if(i%2 == 0) helper(low,high,"",i,count);
            else {
                for(int j=0;j<map3.length();j++){
                    helper(low,high,""+map3.charAt(j),i,count);
                }
            }
        }
        return count[0];
    }
    public void helper(String low,String high,String cur,int n,int[] count){
        if(cur.length() == n && compare(cur,low)>=0 && compare(cur,high)<=0){
            count[0]++;
        }else if(cur.length() < n){
            for(int i= (cur.length() == n-2)?1:0;i<map1.length();i++){
                helper(low,high,map1.charAt(i)+cur+map2.charAt(i),n,count);
            }
        }
    }
    public int compare(String a,String b){
        if(a.length()< b.length()) return -1;
        if(a.length()> b.length()) return 1;
        return a.compareTo(b);
    }
}



/**
Strobogrammatic Number III
Difficulty: Hard

A strobogrammatic number is a number that looks the same when 
rotated 180 degrees (looked at upside down).

Write a function to count the total strobogrammatic numbers 
that exist in the range of low <= num <= high.

For example,
Given low = "50", high = "100", return 3. Because 69, 88, and 
96 are three strobogrammatic numbers.

Note:
Because the range might be a large number, the low and high 
numbers are represented as string.
 */
