#include <iostream>
using namespace std;

void output(int a[], int len) {
    static int ct = 0;
    printf("%d: ", ++ ct);
    for (int i = 0; i < len; i ++) { printf("%d ", a[i]); }
    puts("--");
    //return;
         
    for (int i = 0; i < len; i ++) {
      for (int j = 0; j < a[i]; j ++) printf("0 ");    
      printf("1 ");
      for (int j = a[i]+1; j < len; j ++) printf("0 ");
      puts("");
    }     
    puts("\n");
}

int conflict(int a[], int len) {
    int i, j;
    // row: no need. col and diagonal.
    for (i = 0; i <= len - 1; i ++) {
      for (j = i + 1; j <= len; j ++) { 
        if (a[i] == a[j]) return 1;
        if (a[i] - a[j] == i - j || a[i] - a[j] == j - i) return 1;
      }
    }
    return 0;
}
     
void queens(int a[], int len, int p) {
    if (p == len)  {
        output(a, len);      
        return;
    }
    
    for (int i = 0; i < len; i ++) {
        a[p] = i;
        if (! conflict(a, p)) queens(a, len, p + 1);
        //a[p] = 0;    
    }
}

// http://www.durangobill.com/N_Queens.html
// complexity: ~ n! * n^3
int x(int n) {
    int s = 1;
    for (int i = 1; i <= n; i ++) s *= i;
    return s * n*n*n;
}

int main() {
    printf("Enter number of queens: ");
    int len;
    scanf("%d", &len);
    //const int len = 7;
    int a[100] = {0};
//    queens(a, len, 0);
    
    for (int i = 1; i < 20; i ++) printf("x(%d) = %d\n", i, x(i));
    return 1;   
}
