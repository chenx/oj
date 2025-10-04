class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> ans = new ArrayList<>();
        
        for (int i = 1; i <= n; ++ i) {
            int a = i % 3, b = i % 5;
            if (a == 0 && b == 0) ans.add("FizzBuzz");
            else if (a == 0) ans.add("Fizz");
            else if (b == 0) ans.add("Buzz");
            else ans.add("" + i);            
        }
        return ans;
    }
}

/**
412. Fizz Buzz

Given an integer n, return a string array answer (1-indexed) where:

    answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
    answer[i] == "Fizz" if i is divisible by 3.
    answer[i] == "Buzz" if i is divisible by 5.
    answer[i] == i (as a string) if none of the above conditions are true.
 */
