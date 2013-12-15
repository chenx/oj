#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap2(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void dump(int a[], int len) {
    for (int i = 0; i < len; i ++) { printf("%d ", a[i]); } 
    puts("");
}

void selection_sort(int a[], int len) {
    int i, j, min;
    for (i = 0; i < len - 1; i ++) {
        min = i;
        for (j = i + 1; j < len; j ++) {
            if (a[j] < a[min]) min = j;
        }
        //if (min != i) swap(&a[min], &a[i]);
        if (min != i) swap2(a[min], a[i]);
        //dump(a, len);
    }
}

void insertion_sort(int a[], int len) {
    int i, j, tmp;
    for (i = 1; i < len; i ++) {
        tmp = a[i];
        for (j = i; j > 0 && tmp < a[j - 1]; j --) {
            a[j] = a[j - 1];
        }
        a[j] = tmp;
    }     
}

void bubble_sort(int a[], int len) {
    int i, j;
    for (i = 0; i < len - 1; i ++) {
        for (j = i + 1; j < len; j ++) {
            if (a[i] > a[j]) swap(a[i], a[j]);    
        }    
    }    
}

void test() {
    int a[] = {3,2,5,1,2,4,6,8,2,3,2};  
    int len = sizeof(a) / sizeof(int);
    selection_sort(a, len);
//    insertion_sort(a, len);
//    bubble_sort(a, len);
    dump(a, len);
}

int main() {
    test();
    return 0;   
}
