// Works. O(n) time, O(n) space.
class Solution3 {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (auto num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }

        long long maxDiff = (long long) maxVal - minVal;
        int bucketSize = ceil(maxDiff / (n-1));
        if (bucketSize == 0) bucketSize = 1;

        int numBuckets = maxDiff / bucketSize + 1;
        vector<vector<int>> buckets(numBuckets, vector<int>());

        for (auto num: nums) {
            int i = (num - minVal) / bucketSize;
            if (buckets[i].size() == 0) {
                buckets[i].push_back(num); // min
                buckets[i].push_back(num); // max
            } else {
                buckets[i][0] = min(buckets[i][0], num);
                buckets[i][1] = max(buckets[i][1], num);
            }
        }

        int prevBucket = -1, maxGap = 0;
        for (int i = 0; i < buckets.size(); i ++) {
            if (buckets[i].size() > 0) {
                if (prevBucket == -1) {
                    maxGap = buckets[i][1] - buckets[i][0];
                } else {
                    maxGap = max(maxGap, buckets[i][1] - buckets[i][0]);
                    maxGap = max(maxGap, buckets[i][0] - buckets[prevBucket][1]);
                }
                prevBucket = i;
            }
        }
        return maxGap;
    }

    // This is O(n*log(n)) time.
    int maximumGap2(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());  // n*log(n)

        int maxGap = 0;
        for (int i = 1; i < nums.size(); i ++) {
            maxGap = max(maxGap, nums[i] - nums[i-1]);
        }
        return maxGap;
    }
};

// Works too. O(n). Improved from Solution.
class Solution2 {
public:
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return 0;
        
        // get min and max values in the array.
        int minv = INT_MAX, maxv = INT_MIN;
        for (int i = 0; i < len; ++ i) {
            minv = min(minv, nums[i]);
            maxv = max(maxv, nums[i]);
        }
        if (minv == maxv) return 0;
        
        // put nums elements into bins.
        double binSize = (maxv - minv) * 1.0 / (len - 1); // len-1 !
        vector<int> bin(2 * len, -1);
        
        for (int i = 0; i < len; ++ i) {
            int index = 2 * (nums[i] - minv) / binSize;
            bin[index] = (bin[index] == -1) ? nums[i] : min(nums[i], bin[index]);
            bin[index+1] = (bin[index+1] == -1) ? nums[i] : max(nums[i], bin[index+1]);
        }
        
        // get max gap from the bins.
        int maxGap = 0, i = 0, j, lenBin = 2 * len;
        while (true) {
            for (; i < lenBin && bin[i] == -1; ++ i) {}
            if (i == lenBin) break;

            for (j = i + 1; j < lenBin && bin[j] == -1; ++ j) {}
            if (j == lenBin) break;

            maxGap = max(maxGap, bin[j] - bin[i]);
            i = j;
        }

        return maxGap;        
    }
};

//
// This works. O(n).
// Idea is similar to bucket sort.
// From: https://oj.leetcode.com/discuss/19100/o-n-c-solution-in-20ms-and-explanation
//
class Solution {
public:
    int maximumGap(vector<int> &num) {
        int mi, ma;
        int n = num.size();
        if(n < 2) return 0;
        mi = ma = num[0];
        for(int i = 1; i < n; i++){
            mi = min(mi, num[i]);
            ma = max(ma, num[i]);
        }
        if(mi == ma) return 0;
        vector<int> bs(2*n, -1);  //store mins and maxs for each bucket
        double gap = (ma - mi) * 1.0 / (n - 1);  // compute average length of each bucket
        for(int i = 0; i < n; i++){
            int nom = (int)((num[i] - mi) / gap); // compute the bucket index for a value
            int ind = 2 * nom; //index
            if(bs[ind] == -1) bs[ind] = num[i];
            else bs[ind] = min(bs[ind], num[i]);
            if(bs[ind+1] == -1) bs[ind+1] = num[i];
            else bs[ind+1] = max(bs[ind+1], num[i]); 
        }
        int ans = 0;
        int i = 0;
        int m = bs.size();
        while(i < m) {
            while(i < m && bs[i] == -1) i++;
            int j = 1;
            while((i+j) < m && bs[i+j] == -1) j++;
            if((i+j) < m && bs[i+j] >= 0) ans = max(ans, bs[i+j]-bs[i]);
            i = i+j;
        } // calculate gaps, I believe you can do it more elegantly~
        return ans;        
    }
};

/**
Maximum Gap

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 */

/**

Solution Approach (Bucket Sort / Pigeonhole Principle):
A common and efficient approach to solve this problem within the linear time and space constraints is to
use a variation of bucket sort combined with the pigeonhole principle.

    Handle Edge Cases:
    If the array has less than two elements, return 0. If all elements are the same, return 0.
    
    Find Min and Max:
    Determine the minimum (minVal) and maximum (maxVal) values in the input array.
    
    Calculate Bucket Size:
    Calculate the gap (or bucket size) which is the minimum possible difference between adjacent elements
    if they were evenly distributed. This can be calculated as ceil((maxVal - minVal) / (n - 1)), where n
    is the number of elements.
    
    Create Buckets:
    Create an array of buckets. Each bucket will store the minimum and maximum values that fall within its
    range. The number of buckets can be calculated as (maxVal - minVal) / gap + 1.
    
    Distribute Elements into Buckets:
    Iterate through the input array nums. For each number, determine its corresponding bucket index based
    on (num - minVal) / gap and update the minimum and maximum values within that bucket.
    
    Find Maximum Gap:
    Iterate through the buckets. The maximum gap will occur between the maximum element of a non-empty
    bucket and the minimum element of the next non-empty bucket. This is because, due to the chosen bucket
    size, any elements within the same bucket or adjacent elements in different buckets that are not
    separated by an empty bucket will have a difference less than or equal to the gap. The true maximum gap
    will be found when skipping over empty buckets. Keep track of the prevMax (the maximum value of the
    previously processed non-empty bucket) and update the maxGap by comparing bucket.min - prevMax. 

This method avoids a full sort, allowing for linear time complexity, and uses linear extra space for the buckets.
 */
