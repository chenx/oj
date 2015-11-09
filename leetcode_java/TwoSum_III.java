import java.util.*;

// This works.
public class TwoSum3 {
        public void add(int number) {
            nums.add(number);
        }

        public boolean find(int value) {
            if (sumFound.contains(value)) return true;

            HashSet<Integer> s = new HashSet<Integer>();
            for (int i = 0; i < nums.size(); ++ i) {
                if (s.contains(nums.get(i))) {
                        sumFound.add(value);
                        break;
                } else {
                        s.add(value - nums.get(i));
                }
            }

            return sumFound.contains(value);
        }

        private HashSet<Integer> sumFound = new HashSet<Integer>();
        private ArrayList<Integer> nums = new ArrayList<Integer>();

        private static void ok(boolean isOk, String s) {
                if (isOk) System.out.println("ok: " + s);
                else System.out.println("Not ok: " + s);
        }

        private static void test() {
                TwoSum3 ts = new TwoSum3();
                ok(ts.find(2) == false, "2 not exist");
                ts.add(0); ts.add(1); ts.add(2);
                ok(ts.find(2) == true, "2 exists");
        }

        public static void main(String[] args) {
                test();
                System.out.println("hi");
        }
}

/**
Two Sum III - Data structure design
Difficulty: Easy

Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,

add(1); add(3); add(5);
find(4) -> true
find(7) -> false
 */
