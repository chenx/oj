public class Solution {
    public String simplifyPath(String path) {
        Stack<String> s = new Stack<String>();
        
        String dir = "";
        for (int i = 0, len = path.length(); i < len; ++ i) {
            char c = path.charAt(i);
            if (c == '/') {
                addDir(s, dir);
                dir = "";
            }
            else {
                dir += c;
            }
        }
        addDir(s, dir);
        
        dir = "";
        if (! s.empty()) {
            dir = s.peek();
            s.pop();
            while (! s.empty()) {
                dir = s.peek() + "/" + dir;
                s.pop();
            }
        }
        dir = "/" + dir;
        
        return dir;
    }
    
    private void addDir(Stack<String> s, String dir) {
        if (dir.equals(".") || dir.equals("")) {
            // do nothing
        }
        else if (dir.equals("..")) {
            if (! s.empty()) s.pop();
        }
        else {
            s.push(dir);
        }
    }
}

/**
Simplify Path
Difficulty: Medium

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

click to show corner cases.
Corner Cases:

    Did you consider the case where path = "/../"?
    In this case, you should return "/".
    Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
    In this case, you should ignore redundant slashes and return "/home/foo".
 */
