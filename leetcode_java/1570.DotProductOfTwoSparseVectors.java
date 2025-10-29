class SparseVector {
    public int[] nums;
    
    SparseVector(int[] nums) {
        this.nums = nums;
    }
    
	// Return the dotProduct of two sparse vectors
    public int dotProduct(SparseVector vec) {
        int sum = 0;
        for (int i = 0; i < vec.nums.length; ++ i) {
            sum += this.nums[i] * vec.nums[i];
        }
        return sum;
    }
}

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1 = new SparseVector(nums1);
// SparseVector v2 = new SparseVector(nums2);
// int ans = v1.dotProduct(v2);


/**
1570. Dot Product of Two Sparse Vectors

Given two sparse vectors, compute their dot product.

Implement class SparseVector:

    SparseVector(nums) Initializes the object with the vector nums
    dotProduct(vec) Compute the dot product between the instance of SparseVector and vec

A sparse vector is a vector that has mostly zero values, you should store the sparse vector 
efficiently and compute the dot product between two SparseVector.

Follow up: What if only one of the vectors is sparse?
 */
