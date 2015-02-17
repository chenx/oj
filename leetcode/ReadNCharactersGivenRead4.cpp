/**
 * Read N Characters Given Read4.
 * 
 * Ref:
 * [1] http://www.mitbbs.com/article_t/JobHunting/32836155.html
 * [2] http://blog.csdn.net/a83610312/article/details/12872437
 * [3] http://www.mitbbs.com/article_t/JobHunting/32810997.html
 */

// Should work. Although not tested.
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
