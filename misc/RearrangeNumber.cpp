/*
Google interview. 2013-03-06.

Lets consider x, y, natural integers (from 1 to +infinity), represented by the arrays of their digits
Ex:
x = 123 = [1, 2, 3]
y = 234 = [2, 3, 4]

1) Reorder the digits of x to make it >= to y
You cannot reorder the digits of y
Ex:
One solution is [3, 1, 2]
312 >= 234

Find the minimal of such number.

 * @Author: Xin Chen
 * @Created on: 3/6/2013
 * @Last modified: 3/6/2013
 */
#include <iostream>
using namespace std;

//
// Both arrange() and arrange2() seem to work for the current small test case.
// But arrange2() seems 'more' correct.
//
class Solution {
public:
    bool rearrange(int x[], int n, int y[], int m) {
        if (n > m) return true;
        if (n < m) return false;
        return arrange2(x, y, n, 0);
    }	

    void dumpArray(int x[], int len) {
        for (int i = 0; i < len; ++ i) {
            cout << x[i] << " ";
        }
        cout << endl;
    }

private:
    bool arrange(int x[], int y[], int n, int pos) {
        if (pos == n-1) {
            return x[pos] >= y[pos];
        }
        
        if (x[pos] == y[pos]) return arrange(x, y, n, pos + 1);
        
        int i = findEqual(x, y[pos], n, pos+1);
        if (i != -1) {
            swap(x[pos], x[i]);
            return arrange(x, y, n, pos + 1);
        }
        else {
             int i = findMinGreater(x, y[pos], n, pos+1);
             if (i != -1) {
                 swap(x[pos], x[i]);
                 sort(x, pos+1, n-1);
                 return true;
             }
             else {
                 return false;
             }
        }
    }
    
    bool arrange2(int x[], int y[], int n, int pos) {
        if (pos == n-1) {
            return x[pos] >= y[pos];
        }
        
        if (x[pos] == y[pos]) return arrange2(x, y, n, pos + 1);
        
        int i = findEqual(x, y[pos], n, pos+1);
        if (i != -1) {
            swap(x[pos], x[i]);
            if ( arrange2(x, y, n, pos + 1) ) return true;
        }

        i = findMinGreater(x, y[pos], n, pos+1);
        if (i != -1) {
            swap(x[pos], x[i]);
            sort(x, pos+1, n-1);
            return true;
        }
        else {
            return false;
        }
    }
    
    void sort(int x[], int L, int R) {
        for (int i = L; i < R; ++ i) {
            for (int j = i+1; j <= R; ++ j) {
                if (x[i] > x[j]) {
                    swap(x[i], x[j]);
                }
            }
        }
    }
    
    int findEqual(int x[], int yi, int len, int pos) {
        for (int i = pos; i < len; ++ i) {
            if (x[i] == yi) return i;
        }
        return -1;
    }

    int findMinGreater(int x[], int yi, int len, int pos) {
        int i_min = -1;
        for (int i = pos; i < len; ++ i) {
            if (x[i] > yi) {
                if (i_min == -1) i_min = i;
                else if (x[i] < x[i_min]) i_min = i;
            } 
        }
        return i_min;
    }	
};


int main() {
    Solution s;
    int x[] = {4,5,2,3,2};
    int y[] = {2,2,3,4,2};
    int lenx = sizeof(x)/sizeof(int);
    int leny = sizeof(y)/sizeof(int);
    
    cout << "before arrangement: " << endl;
    cout << "y: "; s.dumpArray(y, leny); 
    cout << "x: "; s.dumpArray(x, lenx);
        
    bool ok = s.rearrange(x, lenx, y, leny);

    cout << "rearrangement " << (ok ? "succeeded" : "failed") << endl;
    cout << "after arrangement: " << endl;
    cout << "x: "; s.dumpArray(x, lenx);
    
    return 0;
}
