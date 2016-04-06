// Should work. Tested at hc, not lc.
// Compared to Solution and Solution2, this has less corner cases to consider.
// From: fb intv
class Solution3 {
public:
    int readn(int n, char *buffer) { // max n bytes, or when read4() comes to end.
        const int SIZE = 4;
        int a = n / SIZE, b = n % SIZE, read_ct = 0;
        char * buf4 = new char[SIZE];

        for (int i = 0; i < a; ++ i) {
            int ct = read4(buf4);
            memcpy(buffer + read_ct, buf4, ct);
            read_ct += ct;
            if (ct < SIZE) return read_ct;
        }
        
        if (b > 0) {
            int ct = read4(buf4);
            ct = min(ct, n - read_ct); // don't forget this !!
            memcpy(buffer + read_ct, buf4, ct);
            read_ct += ct;
        }
        
        return read_ct;
    }
};

// Should work. Tested at hc, not lc. Basically same as Solution.
// From: fb intv
class Solution2 {
public:
    int readn(int n, char *buffer) { // max n bytes?
        int read_ct = 0;
        char * buf4 = new char[4];
         
        while (read_ct < n) {
            int ct = read4(buf4);
            if (ct == 0) break; // or: return read_ct; 
           
            ct = min(ct, n - read_ct);
            if (ct > 0) { // not really need to check this, if ct is 0, nothing happens below.
                memcpy(buf + read_ct, buf4, ct);
                read_ct += ct;
            }
          }
         
          return read_ct;
    }
};

/**
 * Read N Characters Given Read4.
 * 
 * Ref:
 * [1] http://www.mitbbs.com/article_t/JobHunting/32836155.html
 * [2] http://blog.csdn.net/a83610312/article/details/12872437
 * [3] http://www.mitbbs.com/article_t/JobHunting/32810997.html
 */

// Work. Tested.
class Solution {
public:
    int read(char * buf, int n) {
        int read_ct = 0;
        char * buf4 = new char[4]; // or (char *) malloc(sizeof(char) * 4
        bool eof = false;
        while (! eof && read_ct < n) {
            int ct = read4(buf4);
            if (ct < 4) eof = true;
            
            ct = min(ct, n - read_ct);
            if (ct > 0) {
                memcpy(buf + read_ct, buf4, ct);
                read_ct += ct;
            }
        }
        return read_ct;
    }
};

/**
Read N Characters Given Read4 My Submissions Question
Difficulty: Easy

The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, 
it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) 
that reads n characters from the file.
 */
