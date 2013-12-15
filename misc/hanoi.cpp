#include <iostream>
#include <deque>
#include <stack> 
using namespace std;

/*
void output(deque<int> a, deque<int> b, deque<int> c) {
    int i; 
    printf("a: "); for (i = 0; i < a.size(); i ++) printf("%d ", a[i]); puts("");     
    printf("b: "); for (i = 0; i < b.size(); i ++) printf("%d ", b[i]); puts("");
    printf("c: "); for (i = 0; i < c.size(); i ++) printf("%d ", c[i]); puts("");
    puts("");
}

void hanoi(deque<int> &a, deque<int> &b, deque<int> &c, int n, char *x, char *y, char *z) {
    if (n == 1) {
      printf("move %d from %s to %s\n", a.back(), x, z);
      c.push_back(a.back());
      a.erase(a.end());
      return;      
    }
    
    hanoi(a, c, b, n - 1, x, z, y);
    hanoi(a, b, c, 1, x, y, z);
    hanoi(b, a, c, n - 1, y, x, z );
}

void testHanoi() {
   const int n = 3;
   deque<int> a, b, c;

   for (int i = 1; i <= n; i ++) a.push_front(i);
   output(a, b, c); ;
   hanoi(a, b, c, n, "a", "b", "c");
   output(a, b, c);
}
*/

// passed by value(copy).
void output(stack<int> a, stack<int> b, stack<int> c) {
    printf("a: "); while(a.size() > 0) { printf("%d ", a.top()); a.pop(); } puts("");    
    printf("b: "); while(b.size() > 0) { printf("%d ", b.top()); b.pop(); } puts("");     
    printf("c: "); while(c.size() > 0) { printf("%d ", c.top()); c.pop(); } puts("");
}

void hanoi(stack<int> &a, stack<int> &b, stack<int> &c, int n,
           char * an, char * bn, char * cn) {
    if (n == 1) {
      printf("move %d from %s to %s\n", a.top(), an, cn);
      c.push(a.top());
      a.pop();
      return;      
    }
    
    hanoi(a, c, b, n - 1, an, cn, bn);
    hanoi(a, b, c, 1, an, bn, cn);
    hanoi(b, a, c, n - 1, bn, an, cn);
}

void testHanoi() {
   const int n = 3;
   stack<int> a, b, c;

   for (int i = n; i >= 1; i --) a.push(i);
   output(a,b,c); 
   hanoi(a, b, c, n, "a", "b", "c");
   output(a,b,c);
}


int main() {
    testHanoi();
    return 0;
}
