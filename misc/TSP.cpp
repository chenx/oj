#include <iostream>
#include <vector>
using namespace std;

static int min_cost = INT_MAX;
static vector<int> path;

void output(int a[], int len) {
    static int w[][4] = {
        {1,-1,2,4},
        {3,4,2,1},
        {1,2,3,4},
        {5,2,2,1}
        };
        
     static int count = 0;
     printf("%d: ", ++ (count));
     for (int j = 0; j < len; j ++) printf("%d ", a[j]); 
     
     int cost = 0, src, dst;
     for (int j = 0; j < len; j ++) {
         src = j;
         dst = (len == j + 1) ? 0 : j + 1;

         if (-1 == w[a[src]-1][a[dst]-1]) {
             printf("no path\n");
             return; // no path
         }
         cost += w[a[src]-1][a[dst]-1];
         //printf("cost[%d->%d] = %d, ", a[src], a[dst], w[a[src]-1][a[dst]-1]);
     }
     printf(". cost = %d", cost);
     if (min_cost > cost) {
         min_cost = cost;
         path.clear();
         for (int i = 0; i < len; i ++) path.push_back(a[i]);
     }
     
     puts("");  
}

void perm(int in[], int out[], int used[], int len, int level) {
     if (level == len) {
        output(out, len);
        return;
     }
     
     for (int i = 0; i < len; i ++) {
         if (used[i]) continue;
         out[level] = in[i];
         used[i] = 1;
         perm(in, out, used, len, level + 1);
         used[i] = 0;
     }
}

void testTSP() {       
    int a[] = {1,2,3,4};
    int len = sizeof(a) / sizeof(int);
    int b[len];
    int used[len];
    for (int i = 0; i < len; i ++) used[i] = 0;
    perm(a, b, used, 4, 0);   
    
    printf("min_cost = %d\n", min_cost); 
    printf("path: ");
    for (vector<int>::iterator it = path.begin(); it < path.end(); it ++) {
        printf("%d ", *it);
    }
    puts("");
}

int main() {
    testTSP();
    return 0;   
}


/*
   - The method here is exhaustive search. 
   - Greedy method is not optimal.
   - Metric TSP is an approximate algorithm, bounded by 2 * Cost_max, 
     but requires metric property on the distance matrix.
 */
