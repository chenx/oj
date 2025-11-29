// 
// Time complexity: O(n) for creating the Hash Map; O(L) for calculating the dot product.
// Space complexity: O(L) for creating the Hash Map, as we only store elements that are non-zero. O(1) for calculating the dot product.
//
class SparseVector2 {
public:
    map<int, int> map;
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] != 0) {
                map[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum = 0;
        for (auto [key, value] : map) {
            if (vec.map.contains(key)) {
                sum += value * vec.map[key];
            }
        }
        return sum;
    }
};


// Naive. But in reality may be more efficient, since map solution is costly in using map.
// Time complexity: O(n) for calculating the dot product.
// Space complexity: O(1)
class SparseVector {
public:
    vector<int> array;
    
    SparseVector(vector<int> &nums) {
        array = nums;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum = 0;
        for (int i = 0; i < array.size(); ++ i) {
            sum += array[i] * vec.array[i];
        }
        return sum;
    }
};


// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);

/**
1570. Dot Product of Two Sparse Vectors

Given two sparse vectors, compute their dot product.

Implement class SparseVector:

    SparseVector(nums) Initializes the object with the vector nums
    dotProduct(vec) Compute the dot product between the instance of SparseVector and vec

A sparse vector is a vector that has mostly zero values, you should store the sparse vector efficiently and compute the dot product between two SparseVector.

Follow up: What if only one of the vectors is sparse?
 */
