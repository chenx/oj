class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        
        long long a = 0, b = 0, c = 0, n = A.size();
        
        for (int i = 0; i < n; ++ i) {
            a += A[i] * B[i];
            b += A[i] * A[i];
            c += B[i] * B[i];
        }
        
        if (b == 0 || c == 0) return 2.000;
        return 1.0 * a / sqrt(b) / sqrt(c);
    }
};


/**
Cosine Similarity

Cosine similarity is a measure of similarity between two vectors of an 
inner product space that measures the cosine of the angle between them. 
The cosine of 0° is 1, and it is less than 1 for any other angle.

See wiki: Cosine Similarity

Here is the formula:

/media/problem/cosine-similarity.png

Given two vectors A and B with the same size, calculate the cosine similarity.

Return 2.0000 if cosine similarity is invalid (for example A = [0] and B = [0]).
Have you met this question in a real interview?
Example

Given A = [1, 2, 3], B = [2, 3 ,4].

Return 0.9926.

Given A = [0], B = [0].

Return 2.0000

 */
