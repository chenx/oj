// From: https://leetcode.com/problems/product-of-the-last-k-numbers/editorial/
// Time Complexity: O(n)
//  - the add method runs in O(1) time per operation, and the getProduct method also runs in O(1) time per operation. 
//  - For n operations, the total time complexity is O(n)
// Space Complexity: O(n)
//
class ProductOfNumbers {
private:
    vector<int> prefixProduct; // Stores cumulative product of the stream
    int size = 0;

public:
    ProductOfNumbers() {
        // Initialize the product list with 1 to handle multiplication logic
        prefixProduct.push_back(1);
        size = 0;
    }

    void add(int num) {
        if (num == 0) { // If num is 0, reset the cumulative products.
            prefixProduct = {1};
            size = 0;
        } else {
            prefixProduct.push_back(prefixProduct[size] * num);
            size++;
        }
    }

    int getProduct(int k) {
        if (k > size) return 0;
        return prefixProduct[size] / prefixProduct[size - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

/**
1352. Product of the Last K Numbers
Medium

Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

Implement the ProductOfNumbers class:

    ProductOfNumbers() Initializes the object with an empty stream.
    void add(int num) Appends the integer num to the stream.
    int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always 
        the current list has at least k numbers.

The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a 
single 32-bit integer without overflowing.
 */
