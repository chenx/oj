// Also works. Note, must cast to (int), otherwise max() gives warning.
class StringUtils2 {
public:
    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static string leftPad(string& originalStr, int size, char padChar=' ') {
        // Write your code here
        return string(max(0, (int) (size - originalStr.length())), padChar) + originalStr;
    }
};

class StringUtils {
public:
    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static string leftPad(string& originalStr, int size, char padChar=' ') {
        // Write your code here
        int len = size - originalStr.length();
        if (len <= 0) return originalStr;
        else return string(len, padChar) + originalStr;
    }
};

/**
Left Pad

You know what, left pad is javascript package and referenced by React:
Github link

One day his author unpublished it, then a lot of javascript projects in 
the world broken.

You can see from github it's only 11 lines.

You job is to implement the left pad function. If you do not know what 
left pad does, see examples below and guess.
Have you met this question in a real interview?
Example

leftpad("foo", 5)
>> "  foo"

leftpad("foobar", 6)
>> "foobar"

leftpad("1", 2, "0")
>> "01"


 */
