#include <bitset>
#include <iostream>

using namespace std;

// phones: 111-1111 - 999-9999, so 888-8888 entries.
// can be covered by 1000-0000 or 10 million bitset, about 1MB.
void sort_phone(int phones[], int len) {
    const int SIZE = 10000000;
    bitset<SIZE> b;
    for (int i = 0; i < len; i ++) { b.set(phones[i]); }
    
    // output sorting result.
    for (int i = 0; i < SIZE; i ++) {
        if (b[i]) printf("%d \n", i);
    }
}

void test_sort_phone() {
     int phones[] = {8829832, 9518532, 2263584, 2222222,3333333,1111111};
     int len = sizeof(phones) / sizeof(int);
     sort_phone(phones, len);
}

int main() {
    test_sort_phone();
    return 0;    
}
