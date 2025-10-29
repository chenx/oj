class Solution {
    public String toGoatLatin(String sentence) {
        String[] arr = sentence.split(" ");
        for (int i = 0; i < arr.length; ++ i) {
            if (isVowel(arr[i].charAt(0))) {
                arr[i] = arr[i] + "ma";
            } else {
                arr[i] = arr[i].substring(1) + arr[i].charAt(0) + "ma";
            }
            arr[i] += "a".repeat(i + 1);
        }

        return String.join(" ", arr);
    }

    boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
}

/**
824. Goat Latin
Easy

You are given a string sentence that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:

    If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to the end of the word.
        For example, the word "apple" becomes "applema".
    If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add "ma".
        For example, the word "goat" becomes "oatgma".
    Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
        For example, the first word gets "a" added to the end, the second word gets "aa" added to the end, and so on.

Return the final sentence representing the conversion from sentence to Goat Latin.
 */
