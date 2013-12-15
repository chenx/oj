#include <iostream>
#include <set>

using namespace std;

static const int SIZE = 5;
static int cost[][SIZE] = {
        {-1,-1,2,3,1},
        {-1,-2,2,-1,1},
        {-1,2,-1,4,5},
        {-1,-1,4,-1,4},
        {1, -1, -1, -1, -1}
         };
static int start = 0, end = 1; 
// end node found, distance = 4. path: 1 <- 2 <- 0


int getMinNode(int dist[], set<int> nodes) {
    int d = INT_MAX;
    int n = -1;
    int v;
    for (set<int>::iterator it = nodes.begin(); it != nodes.end(); it ++) {
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
     printf("path: "); 
     for (i = end; i != start; i = path[i]) {
         printf("%d <- ", i);
     }
     printf("%d\n", i);
}

// Dijkstra's algorithm for shortest path:
// start from origin node o, pull next node with min dist to o into cloud,
// until end node is found.
// Is BFS, is greedy. Similar to MST.
void SP(int cost[][SIZE], int dist[], int len, int start, int end, int path[]) {
    set<int> unknown;
    set<int> cloud;
    
    for (int i = 0; i < len; i ++) unknown.insert(i);
        
    int n;
    dist[start] = 0;
    while(1) {
        // get the next node with min dist to start node.
        n = getMinNode(dist, unknown);
        if (n == -1) {
            puts("a path cannot be found"); 
            return;
        }
        if (n == end) {
            printf("end node found, distance = %d\n", dist[n]);
            show_path(path, start, end);
            return;      
        }
        // move n from unknown to cloud.
        unknown.erase(unknown.find(n));
        cloud.insert(n);
        
        // for each neighbor e of n, if e is not in cloud, update its dist.
        for (set<int>::iterator it = unknown.begin(); it != unknown.end(); it ++) {
            int i = *it;
            if (cost[n][i] == -1) continue; // not neighbor.
            if (dist[i] > dist[n] + cost[n][i]) {
                dist[i] = dist[n] + cost[n][i];
                path[i] = n; // n -> i
            }
        }
    }
}

void testSP() {
    int dist[SIZE];
    int path[SIZE]; //path to trace back.
    for (int i = 0; i < SIZE; i ++) { dist[i] = INT_MAX; }
    
    SP(cost, dist, SIZE, start, end, path);
}

int main() {
    testSP();
    return 0;   
}


/*
void SP(int cost[][SIZE], int dist[], int len, int start, int end, int path[]) {
    set<int> unknown;
    set<int> cloud;
    
    for (int i = 0; i < len; i ++) {
        if (i == start) continue;
        unknown.insert(i);
    }
        
    int n = start;
    dist[start] = 0;
    cloud.insert(start); // add origin node to cloud.
    while(1) {
        // for each neighbor e of n, if e is not in cloud, update its dist.
        for (set<int>::iterator it = unknown.begin(); it != unknown.end(); it ++) {
            int i = *it;
            if (cost[n][i] == -1) continue; // no path.
            if (dist[i] > dist[n] + cost[n][i]) {
                dist[i] = dist[n] + cost[n][i];
                path[i] = n; // n -> i
            }
        }
               
        // get the next node with min dist to start node.
        n = getMinNode(dist, unknown);
        if (n == -1) {
            puts("a path cannot be found"); 
            return;
        }
        if (n == end) {
            printf("end node found, distance = %d\n", dist[n]);
            show_path(path, start, end);
            return;      
        }
        // add n to cloud, and remove n from unknown.
        cloud.insert(n);
        unknown.erase(unknown.find(n));
    }
}
*/
