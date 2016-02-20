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
