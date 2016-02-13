
// Forward declaration of the read4 API.
int read4(char *buf);

// Works too. Tested. From: https://leetcode.com/discuss/21219/a-simple-java-code
class Solution4 {
public:
    Solution() : buffCnt(0), buffPtr(0) {}

    int read(char *buf, int n) {
        int cnt = 0;
        while(cnt < n){
            if (buffPtr == 0)
                buffCnt = read4(buff);
            if (buffCnt == 0)  break;
            while (cnt < n && buffPtr < buffCnt)
                buf[cnt ++] = buff[buffPtr ++];
            if (buffPtr == buffCnt) buffPtr=0;
        }
        return cnt;
    }

private:
    int buffCnt;
    int buffPtr;
    char buff[4];
};

// Works. Tested. From: 
// https://leetcode.com/discuss/80360/c-solution-by-keeping-start-end-positions-in-the-buffer
class Solution3 {
public:
    char buffer[4];
    int start;
    int end;

public:
    Solution() {
        start=0;
        end=-1;
    }
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        if (n==0) return 0;

        int i=0;
        for(int j=start; i<n && start<=end; ++j) {
            buf[i++] = buffer[j];
            start++;
        }

        if (i==n) return i;

        int k =read4(buffer);
        start = 0;
        end = k-1;

        while(i<n && start<=end) {
            buf[i++] = buffer[start++];

            if (start>end) {
                k=read4(buffer);
                start = 0;
                end = k-1;
            }
        }

        return i;
    }
};


// Works too. Tested. Modified from Solution. 
class Solution2 {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int N=n;
        while (n > 0) 
        {
            if (mBufLeft > 0) {
                *(buf++) = mBuf[mBufStart++];
                mBufLeft--;
                n--;
            }
            else {
                mBufStart = 0;
                if ((mBufLeft=read4(mBuf)) == 0) break;
            }
        }
        return N-n;
    }

private:
    char mBuf[4];
    int mBufLeft = 0, mBufStart = 0;
};

// Works. Tested. From: https://leetcode.com/discuss/74150/8-line-fast-c-solution
class Solution {
public:
    char mBuf[4];
    int mBufLeft, mBufStart;

    Solution() { mBufLeft=0; }

    int read(char *buf, int n) {
        int N=n;
        while (n > 0) 
        {
            if (mBufLeft > 0)
                *(buf++) = mBuf[mBufStart++], mBufLeft--, n--;
            else if ((mBufStart=0, mBufLeft=read4(mBuf)) == 0)
                break;
        }
        return N-n;
    }
};

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
 * --
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
