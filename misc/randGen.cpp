//
// Given a function rand01(), which can generate 0 or 1 randomly,
// write a function to generate a random number in [0, n-1].
//
// From: http://www.mitbbs.com/article_t/JobHunting/32370913.html
//
// Idea: generate a bit string of length log(n), each bit is from rand01().
// If the final number is less than n, return; otherwise repeat 
// (rejection sampling).
//
// C/C++ rand() function:
//   rand(), generate number in [0, RAND_MAX]. 
//   RAND_MAX is defined in cstdlib.
// To initialize with a seed:
//   #include <time.h>
//   srand(time(NULL));
// To generate a random number in [1, n]:
//    rand() % n + 1
// 
// See: http://www.cplusplus.com/reference/cstdlib/rand/
//

#include <time.h>
#include <iostream>
using namespace std;

int rand01() {
    int r = rand();
    r = (2*r < RAND_MAX) ? 0 : 1;
    printf("rand01: %d\n", r);
    return r;
}

// return a random number in [0, n-1].
int random0n(int n) {
    srand(time(NULL));
    while (1) {
        int r = 0, x = n;
        while (x > 0) {
            r = (r << 1) + rand01();
            x = x >> 1;
        }
        if (r < n) return r;
    }
}

int main() {
    // (1<<1) + 2 = 4, 1 << (1+2) = 8. output is: 8. So + has higher precedence.
    //printf("1 << 1 + 2 = %d\n", 1 << 1 + 2); 
    cout << random0n(10) << endl;
    return 0;
}
