#include <iostream>
using namespace std;

// A hash table to store non-neg numbers.
class HT {
    private:
        int debug;
        int count; // number of elements in HT.
        int size;  // max capacity of HT.
        static const int EMPTY = -1;
        int * t;
        
        int getKey(int n) {
            int hashVal = n % size;
            //if (hashVal < 0) hashVal += size;
            return hashVal;
        }
    public:
        HT() : debug(1), count(0) {
            size = 256;
            t = new int[size];
            for (int i = 0; i < size; i ++) t[i] = EMPTY;     
        }
               
        ~HT() {
            delete[] t;
            //puts("HT destroyed");
        }
        
        int get_count() { return count; }
        int get_size() { return size; }        
        
        // use linear probing for conflict.
        void insert(int n) {
            if (n < 0 || count == size) return; // not allow neg number.
            int k = getKey(n);
            if (t[k] == -1) {
                t[k] = n;
                count ++;
                if (debug) printf("%d inserted at bucket %d\n", n, k);
            }
            // below not needed if no need to handle conflict.
            else if (t[k] == n) { 
                 return; // same value, don't insert twice.
            }
            else {
              int e = k; // end of linear probing.
              int i;
              for (i = k + 1; i != e; i ++) {
                  if (i == size) {
                      i = 0; // wrap around.
                      if (i == e) break;
                  }
                  if (t[i] == -1) {
                      t[i] = n;
                      count ++;
                      if (debug) printf("%d inserted at bucket %d\n", n, k);
                      break;
                  }
              }
              if (i == e) {
                 printf("Hash table is full. %d is not inserted\n", n);      
              }
            }
        }
               
        // if found, return the bucket position; return -1 otherwise.
        int find(int n) {
            if (n < 0 || count == 0) return -1;
            int k = getKey(n);
            //printf("find1: k = %d\n", k);
            if (t[k] == n) return k;
            // below not needed if no need to handle conflict.
            else {
              int i, e = k;
              for (i = k + 1; i != e; i ++) {
                  if (i == size) {
                      i = 0; // wrap around.
                      if (i == e) break;
                  }
                  if (t[i] == -1) break; // not found
                  if (t[i] == n) return i; // found at bucket i.
              }
            }  
            return -1;
        }
               
        void test_find(int n) {
             int k = find(n);
             if (k == -1) { printf("%d is not found\n", n); }
             else printf("%d is found at bucket %d\n", n, k);
        }
        
        void dump() {
            for (int i = 0; i < size; i ++) {
                printf("%d ", t[i]);
            }
            puts("");
        }
};


void testHT() {
    HT h;
    // h.dump(); 
    printf("h.size = %d\n", h.get_size());
    return;
    h.insert(1);
    h.insert(257);
    //for (int i = 0; i <= 256; i ++) h.insert(i);
    h.dump();
    //for (int i = 0; i < 256; i ++) h.test_find1(i);
    h.test_find(1);
    h.test_find(257 );
    h.test_find(433);
    h.test_find(466);
    h.test_find(436);
}

void find2sum() {
    int a[] = {1,3,5,7,2,6,9,7};
    int sum = 9;
    // find pair of numbers in a that add up to sum.
    int i, len = sizeof(a)/sizeof(int);
    HT h;
    for (i = 0; i < len; i ++) {
        if (h.find(a[i]) != -1) {
            printf("i=%d. pair found: %d + %d = %d\n", i, a[i], (sum - a[i]), sum);                
        }
        h.insert(sum - a[i]);
    }
}

int main() {
//    testHT();
    find2sum();
    return 0;
}


/*

No, you can't call one constructor from another in C++03 (called a delegating constructor).

This changed in C++11 (aka C++0x), which added support for the following syntax:
(example taken from Wikipedia)

class SomeType
{
  int number;

public:
  SomeType(int newNumber) : number(newNumber) {}
  SomeType() : SomeType(42) {}
};

*/

/*
-- initialize const class variable in C++:
-- http://stackoverflow.com/questions/1114501/can-i-declare-member-variable-as-const-in-class-of-cif-yes-how

Sure, the simplest way is like this if the value will be the same 
across all instances of your class:

class X
{
public:
    static const int i = 1;
};

Or if you don't want it static:

class X
{
public:
    const int i;
    X(int the_i) : i(the_i)
    {     
    }
};

*/
