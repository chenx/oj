class Solution {
    public String customSortString(String order, String s) {
        HashMap<Character, Integer> map = new HashMap();
        for (char ch : s.toCharArray()) map.put(ch, map.getOrDefault(ch, 0) + 1);

        char[] orderArray = order.toCharArray();
        StringBuilder sb = new StringBuilder();
        for (char ch : orderArray) {
            if (map.containsKey(ch)) {
                sb.append(("" + ch).repeat(map.get(ch)));
                map.put(ch, 0);
                // map.remove(ch); // This works too.
            }
        }
        for (char ch : map.keySet()) {
            if (map.get(ch) > 0) {
                sb.append(("" + ch).repeat(map.get(ch)));
            }
        }

        return sb.toString();
    }
}

class Solution2 {
    public String customSortString2(String order, String s) {
        // char[] chars = s.toCharArray();
        Character[] arr = new Character[s.length()];
        for (int i = 0; i < s.length(); ++ i) arr[i] = s.charAt(i);
        // Arrays.sort(chars, (a, b) -> { 
        //     Character x = a;
        //     Character y = b;
        //     return order.indexOf(x) - order.indexOf(y); 
        // } );
        // Arrays.sort(chars, (a, b) ->  order.indexOf(Character.valueOf(a)) - order.indexOf(Character.valueOf(b)) );
        // Arrays.sort(chars, (a, b) -> { return order.indexOf(a) - order.indexOf(b) ; } ); 
        Arrays.sort(arr, (c1, c2) -> order.indexOf(c1) - order.indexOf(c2) );

        StringBuilder sb = new StringBuilder();
        for (Character c : arr) sb.append(c);
        return sb.toString();

        //return new String(arr);
    }
}


/**
791. Custom Sort String
Medium

You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs 
before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.
 */
