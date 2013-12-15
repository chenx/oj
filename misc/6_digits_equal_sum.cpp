/*
 * Give all 6-digit integers, the sum of its first 3 digits equals the sum
 * of the second 3 digits.
 * 
 * Total: 50412 / (999999 - 100000 + 1) = 50412 / 900000 = 0.056013333..
 */
#include <iostream>
using namespace std;

// This works. Optimized from getsum(). O(9^2).
int getsum2(int a0, int b0, int c0) {
    static int ct = 0;
    int a, b, c, sum = a0 + b0 + c0;
    int len = (sum >= 9) ? 9 : sum; // optimization 1.
    
     for (a = 0; a <= len; a ++) {
        for (b = 0; b <= len; b ++) {
            c = sum - a - b; // optimization 2.
            if (c >= 0 && c <= 9) {
                printf("%d:   %d %d %d - %d %d %d\n", ++ ct, a0, b0, c0, a, b, c);
            }
        }
    }   
    return 0;
}

// This works. O(9^3).
int getsum(int a0, int b0, int c0) {
    static int ct = 0;
    int a, b, c, sum = a0 + b0 + c0;
     for (a = 0; a <= 9; a ++) {
        for (b = 0; b <= 9; b ++) {
            for (c = 0; c <= 9; c ++) {
                if (a + b + c == sum) {
                    printf("%d:   %d %d %d - %d %d %d\n", ++ ct, a0, b0, c0, a, b, c);
                }
            }
        }
    }   
    return 0;
}

// This works too.
// Given a sum, produce the 3 digits that add up to it.
void get_comb3(int sum, int a[], int pos) {
    int i, j, k;
    static int ct = 0;
    if (pos == 2) {
        a[2] = sum - a[0] - a[1];
        if (a[2] >= 0 && a[2] <= 9)
            printf("%d:  %d %d %d\n", ++ ct, a[0], a[1], a[2]);
        return;
    }
    for (i = 0; i <= 9; i ++) {
        a[pos] = i;
        get_comb3(sum, a, pos + 1);
    }
}

int main() {
    int a, b, c, sum;
    int x[3];
    for (a = 1; a <= 9; a ++) {
        for (b = 0; b <= 9; b ++) {
            for (c = 0; c <= 9; c ++) {
                sum = a + b + c;
                printf("-- %d %d %d --\n", a, b, c);
                getsum2(a,b,c);
                //get_comb3(a+b+c, x, 0);
            }
        }
    }
    return 0;
}
