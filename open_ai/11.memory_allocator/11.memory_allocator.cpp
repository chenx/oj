// 11:15 - 1:17

#include <iostream>
#include <list>

using namespace std;

class MemoryAllocator {
    struct Node {
        int start;
        int size;
        Node(int start, int size) : start(start), size(size) {}
    };

    int memory_size;
    vector<int> memory;
    list<Node> dll;  // list of free slots.

public:
    MemoryAllocator(int size) : memory_size(size) {
        memory.resize(size, 0);
        dll.push_back(Node(0, size));
    }

    void * my_malloc(int size) {
        return (void *) (long long) malloc(size);
    }

    // return address.
    int malloc(int size) { // First fit.
        for (auto it = dll.begin(); it != dll.end(); ++ it) {
            if (it->size >= size) {
                int start = it->start;
                if (it->size > size) {
                    it->start += size;
                    it->size -= size;
                } else { // it->size == size
                    dll.erase(it);
                }
                memory[start] = size; // keeps track of the size of the block.
                return start;
            }
        }
        cout << "==> malloc fails" << endl;
        return -1;
    }

    bool my_free(void* pointer) {
        return free((long long) pointer);
    }

    bool free(int pointer) {
        int size = memory[pointer];
        for (auto it = dll.begin(); it != dll.end(); ++ it) {
            if (pointer <= it->start) { // insert before it->start.
                if (pointer + size > it->start) {
                    // something is wrong
                    return false;
                }
                
                // cout << "to free memory [start=" << pointer << ", size=" << size << "] before " << it->start << endl;

                if (it != dll.begin() && prev(it)->start + prev(it)->size + size == it->start) {
                    // merge with both previous and next nodes.
                    prev(it)->size += size + it->size;
                    dll.erase(it);
                } else if (it != dll.begin() && prev(it)->start + prev(it)->size == pointer) {
                    // merge with the previous node.
                    prev(it)->size += size;
                } else if (pointer + size == it->start) {
                    // merge with the next node.
                    it->start -= size;
                    it->size += size;
                } else {
                    // insert a new node.
                    dll.insert(it, Node(pointer, size));
                }

                memory[pointer] = 0;
                return true;
            }
        }
        // insert at the end.
        dll.push_back(Node(pointer, size));
        memory[pointer] = 0;
        return true;
    }

    void dump() {
        cout << "dump memory:" << endl;
        for (auto it = dll.begin(); it != dll.end(); ++ it) {
            cout << "start: " << it->start << ", size = " << it->size << endl;
        }
    }
};

class MemoryAllocatorTest {
    void test1() {
        cout << "\n== test1" << endl;
        MemoryAllocator allocator(1000);
        allocator.dump();

        int m1 = allocator.malloc(20);
        allocator.dump();

        int m2 = allocator.malloc(80);
        allocator.dump();

        allocator.free(m1);
        allocator.dump();
    }
    
    void test2_merge_with_prev_next() {
        cout << "\n== test2_merge_with_prev_next" << endl;
        MemoryAllocator allocator(1000);
        allocator.dump();

        int m1 = allocator.malloc(20);
        allocator.dump();

        int m2 = allocator.malloc(80);
        allocator.dump();

        allocator.free(m1);
        allocator.dump();

        cout << "merge with previous and next node" << endl;
        allocator.free(m2);
        allocator.dump();
    }

    void test3_merge_with_prev() {
        cout << "\n== test3_merge_with_prev" << endl;
        MemoryAllocator allocator(1000);
        allocator.dump();

        int m1 = allocator.malloc(20);
        allocator.dump();

        int m2 = allocator.malloc(80);
        allocator.dump();

        int m3 = allocator.malloc(100);
        allocator.dump();

        allocator.free(m1);
        allocator.dump();

        cout << "merge with previous node" << endl;
        allocator.free(m2);
        allocator.dump();
    }

    void test4_merge_with_next() {
        cout << "\n== test4_merge_with_next" << endl;
        MemoryAllocator allocator(1000);
        allocator.dump();

        int m1 = allocator.malloc(20);
        allocator.dump();

        int m2 = allocator.malloc(80);
        allocator.dump();

        allocator.free(m2);
        allocator.dump();
    }

    void test5_insert() {
        cout << "\n== test5_insert" << endl;
        MemoryAllocator allocator(1000);
        allocator.dump();

        int m1 = allocator.malloc(20);
        allocator.dump();

        int m2 = allocator.malloc(80);
        allocator.dump();

        int m3 = allocator.malloc(100);
        allocator.dump();

        cout << "insert new node" << endl;
        allocator.free(m2);
        allocator.dump();
    }

    void test6_insert_at_end() {
        cout << "\n== test6_insert_at_end" << endl;
        MemoryAllocator allocator(1000);
        allocator.dump();

        int m1 = allocator.malloc(20);
        allocator.dump();

        int m2 = allocator.malloc(80);
        allocator.dump();

        int m3 = allocator.malloc(100);
        allocator.dump();

        int m4 = allocator.malloc(800);
        allocator.dump();

        allocator.free(m2);
        allocator.dump();

        cout << "insert at the end" << endl;
        allocator.free(m4);
        allocator.dump();
    }

    void test7_malloc_fails() {
        cout << "\n== test7_malloc_fails" << endl;
        MemoryAllocator allocator(1000);
        allocator.dump();

        int m1 = allocator.malloc(20);
        allocator.dump();

        int m2 = allocator.malloc(80);
        allocator.dump();

        int m3 = allocator.malloc(200);
        allocator.dump();

        cout << "malloc fails" << endl;
        int m4 = allocator.malloc(800);
        allocator.dump();
    }

    void test8_malloc_returns_pointer() {
        cout << "\n== test8_malloc_returns_pointer" << endl;
        MemoryAllocator allocator(1000);
        allocator.dump();

        int m1 = allocator.malloc(20);
        allocator.dump();

        int m2 = allocator.malloc(80);
        allocator.dump();
        cout << "m2 = " << m2 << endl;

        void *ptr = (void *) (long long) m2;
        cout << "ptr = " << ptr << endl;
        // cout << "*ptr = " << *ptr << endl;
        long long v = (long long) ptr;
        cout << "v = " << v << endl;
    }

    void test9_malloc_returns_pointer() {
        cout << "\n== test9_malloc_returns_pointer" << endl;
        MemoryAllocator allocator(1000);
        allocator.dump();

        void* m1 = allocator.my_malloc(100);
        allocator.dump();

        void* m2 = allocator.my_malloc(200);
        allocator.dump();
        cout << "m2 = " << m2 << endl;

        allocator.my_free(m1);
        allocator.dump();

        allocator.my_free(m2);
        allocator.dump();
    }

public:
    void run_tests() {
        test1();
        test2_merge_with_prev_next();
        test3_merge_with_prev();
        test4_merge_with_next();
        test5_insert();
        test6_insert_at_end();
        test7_malloc_fails();
        test8_malloc_returns_pointer();
        test9_malloc_returns_pointer();
    }
};

int main() {
    MemoryAllocatorTest test;
    test.run_tests();
    return 0;
}
