#include <iostream>

using namespace std;

class PQ {
    private:
        int * h; // array for max heap.
        int _size;
        int _count;

        int get_larger_child(int n) {
            int c1 = 2 * n + 1, c2 = c1 + 1;
            if (c1 >= _count) return -1; // no child found.
            if (c1 == _count - 1) return c1; // the only child.
            return (h[c1] > h[c2]) ? c1 : c2;
        }
        
        int swap(int &a, int &b) {
            int tmp = a;
            a = b; 
            b = tmp;    
        }
        
    public:
        PQ() : _size(100), _count(0) {
             h = new int[_size];
        }
        
        ~PQ() { delete[] h; }
        int size() { return _size; }
        int count() { return _count; }
        
        // add to end and sift up.
        int push(int v) {
            if (_count == _size) return 0; // failed.
            h[_count ++] = v;
            int n = _count - 1;
            int p; // parent of n
            while (n > 0) {
                p = (n - 1) / 2;
                if (h[n] <= h[p]) break; 
                swap(h[n], h[p]);
                n = p;
            }
            return 1; // succeeded.
        }
               
        // move last elem to h[0] and sift down.
        int pop() {
            if (_count == 0) return 0; // failed.
            int max = h[0];
            h[0] = h[-- _count];
            int n = 0;
            int c; // child of n.
            while (n < _count) {
                c = get_larger_child(n);
                printf("n=%d, h[n]=%d, c=%d, h[c]=%d\n", n, h[n], c, h[c]);
                if (c == -1 || h[c] <= h[n]) break;
                swap(h[n], h[c]);
                n = c;
            }
            
            return max;
        }
        
        int max() {
            if (_count == 0) return 0;
            return h[0];    
        }
        
        void dump() {
            printf("PQ (count=%d): ", _count);
            for (int i = 0; i < _count; i ++) printf("%d ", h[i]);
            puts("");
        }
};


void testPQ() {
     PQ p;
     int data[]  = {1, 2,3,4,5,6,7,8,9,10};
     int len = sizeof(data) / sizeof(int);
     for (int i = 0; i < len; i ++) { p.push(data[i]); }
     p.dump();
     
     while(p.count() > 0) {
       printf("pop: %d\n", p.pop());
       p.dump();                
     }
}     
     
int main() {
    testPQ();
    return 0;   
}

/*
PQ implemented as a max heap. O(log n) for push() and pop().

If PQ is implemented as a sequential structure, say array,
1) push() - add to end of array, O(1)
   pop()  - sequential search to find max, return, shift array to keep compact: O(n).
2) push() - insertion sort by binary search, ASC, O(n + log n) = O(n)
   pop()  - remove last element, O(1)

 */
