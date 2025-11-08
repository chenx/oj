class SparseVector {
public:
    map<int, int> map;
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++ i) {
            map[i] = nums[i];
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
