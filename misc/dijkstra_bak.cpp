#include <iostream>
#include <set>

using namespace std;

static const int SIZE = 5;
static int cost[][SIZE] = {
        {-1,-1,2,3,1},
        {-1,-2,2,-1,1},
        {-1,-1,-1,4,5},
        {-1,-1,4,-1,4},
        {1, -1, -1, -1, -1}
         };
static int start = 0, end = 1;

int in_cloud(set<int> cloud, int n) {
    set<int>::iterator it = cloud.find(n);
    return it != cloud.end();
}

int getMinNode(int dist[], set<int> nodes) {
    int d = INT_MAX;
    int n = -1;
    int v;
    set<int>::iterator it;
    for (it = nodes.begin(); it != nodes.end(); it ++) {
        v = *it;
        if (dist[v] < d) {
            d = dist[v];
            n = v;  
        }    
    }
    return n;
}

void show_dist(int dist[], int len) {
    for (int i = 0; i < len; i ++) {
        printf("%d ", dist[i]);    
    }     
    puts("");
}

void show_path(int path[], int start, int end) {
     int i;
     for (i = end; i != start; i = path[i]) {
         printf("%d <- ", i);
     }
     printf("%d\n", i);
}

// Dijkstra's algorithm for shortest path:
// start from origin node o, pull next node with min dist to o into cloud,
// until end node is found.
void SP(int cost[][SIZE], int dist[], int len, int start, int end, int path[]) {
    int n;
    set<int> unknown;
    set<int> cloud;
    set<int>::iterator it;
    int i;
    
    for (int i = 0; i < len; i ++) unknown.insert(i);
    unknown.erase(unknown.find(start));
        
    n = start;
    dist[start] = 0;
    cloud.insert(start); // add origin node to cloud.
    while(1) {
        // for each neighbor e of n, if e is not in cloud, update its dist.
        for (it = unknown.begin(); it != unknown.end(); it ++) {
            i = *it;
            if (cost[n][i] == -1) continue; // no path.
            printf("checking to update %d -> %d\n", n, i);
            if (dist[i] > dist[n] + cost[n][i]) {
                dist[i] = dist[n] + cost[n][i];
                path[i] = n; // n -> i
                printf("update: path[%d] = %d .. %d -> %d\n", i, n, n, i);
            }
        }
        
        printf("dist: "); show_dist(dist, len); //exit(0);
        
        // get the next node with min dist to start node.
        n = getMinNode(dist, unknown);
        if (n == -1) {
            puts("a path cannot be found"); 
            return;
        }
        printf("next min dist node: %d (dist: %d)\n", n, dist[n]);
        if (n == end) {
            printf("end node found, distance = %d\n", dist[n]);
            printf("path: "); show_path(path, start, end);
            break;      
        }
        // add n to cloud.
        cloud.insert(n);
        unknown.erase(unknown.find(n));
        
        printf("next n: %d\n", n); //exit(0);
    }
}

void testSP() {
    int dist[SIZE];
    int path[SIZE]; //path to trace back.
    path[0] = -1;
    for (int i = 0; i < SIZE; i ++) { dist[i] = INT_MAX; }
    show_dist(dist, SIZE);  //return;
    SP(cost, dist, SIZE, start, end, path);
}

int main() {
    testSP();
    return 0;   
}
