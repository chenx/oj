/**
 * Read N Characters Given Read4 II - Call multiple times
 * 
 * The API: int read4(char *buf) reads 4 characters at a time from a file.
 * 
 * The return value is the actual number of characters read. For example, it 
 * returns 3 if there is only 3 characters left in the file.
 * 
 * By using the read4 API, implement the function int read(char *buf, int n) 
 * that reads n characters from the file.
 * 
 * Note:
 * The read function may be called multiple times.
 * e.g.:
 * Input:    "ab", [read(1),read(2)]
 * Output:    ["a",""]
 * Expected:    ["a","b"]
 * 
 * Ref:
 * [1] http://www.mitbbs.com/article_t/JobHunting/32836155.html
 * [2] http://blog.csdn.net/a83610312/article/details/12872437
 */