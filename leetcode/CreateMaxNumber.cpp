// Works. Tested. Not as fast as Solution, but easier to understand.
// Modified From: https://leetcode.com/discuss/75995/easy-to-understand-c-solution-to-create-maximum-number
/*
To get the maximal number out of two vector, we can split the problem into:
1) create the maximal number of length i from one vector
2) merge number1 of length(i) and number2 of length(k-i)
*
* For range of i in maxNumber() below:
* let i and j be the index of nums1 and nums2 respectively,
* 1) i + j = k  => i = k - j >= k - n2, since j <= n2
* 2) 0 <= i <= min(k, A.size())
* 3) 0 <= j <= min(k, B.size())
* 
* from 1) and 2): max(0, k - n2) <= i <= min(k, A.size())
*/
class Solution2 {
public:    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int n1 = nums1.size(), n2 = nums2.size();
        //vector<int>maxNum(k, INT_MIN); // works too.
        vector<int>maxNum;
        for(int i = max(k-n2, 0); i <= min(n1,k); i++){
            maxNum = max(maxNum, Merge(MaxNumLenk(nums1, i), MaxNumLenk(nums2, k-i)));
        }
        /* // Below works too, exchanges nums1 and nums2.
        for (int i = max(k - n1, 0); i <= min(k, n2); ++ i) {
            ans = max(ans, merge( maxN(nums2, i), maxN(nums1, k - i) ));
        }
        */
        return maxNum;
    }
    
private:
    // return the maximal number of len k
    vector<int> MaxNumLenk(vector<int>nums, int k)
    {
        int drop = nums.size() - k;
        vector<int> res;
        for(int n : nums) { //insert smallest nums[i]
            while (drop && res.size() && res.back() < n){
                res.pop_back();
                drop --;
            }
            res.push_back(n);
        }
        res.resize(k); // remove useless tail elements.
        return res;
    }
    
    // merge two vectors to get the maximal number of length k
    vector<int> Merge(vector<int>nums1, vector<int>nums2)
    {
        vector<int> res;
        while(nums1.size() + nums2.size()) { //lexi compare
            vector<int>& temp = nums1 > nums2 ? nums1 : nums2;
            res.push_back(temp[0]);
            temp.erase(temp.begin());
        }
        return res;
    }
};


// Works. Tested. Fast (16ms), But hard to understand. Explained in link.
// From: https://leetcode.com/discuss/85603/c-16ms-beats-100%25
class Solution {
public:
    #define MIN(a,b) (a<b?a:b)
    #define MAX(a,b) (a>b?a:b)
    // create max number of length t from single non-empty vector
    void getMax(int* num, int& len, int* result, int& t, int& sortedLen)
    {
        int n, top = 0;
        result[0] = num[0];
        const int need2drop = len - t;
        for (int i = 1; i < len; ++i){
            n = num[i];
            while (top >= 0 && result[top] < n && (i - top) <= need2drop) --top; // i - top means already dropped i - top numbers
            if (i - top > need2drop){
                sortedLen = MAX(1,top);
                while (++top < t) result[top] = num[i++];
                return;
            }
            if (++top < t) result[top] = n;
            else top = t - 1;
        }
    }
    // create max number of different length from single vector
    void dp(int *num, int len, int&sortedLen, int& minL, int& maxL, int *res, int &k){
        int  j, *head, *prevhead = res;
        const int soi = sizeof(int);
        getMax(num, len, res, maxL,sortedLen);
        for (int l = maxL; l > MAX(minL,1); --l){
            head = prevhead + k;
            memcpy(head, prevhead, l*soi);
            for (j = sortedLen; j < l; ++j){
                if (head[j] > head[j - 1]){
                    sortedLen = MAX(1, j - 1);
                    memcpy(head + j - 1, prevhead + j, soi*(l - j));
                    break;
                }
            }
            if (j == l) sortedLen = l;
            prevhead = head;
        }
    }
    // merge max number created from single vector
    void merge(int* num1,int len1,int* num2,int len2,int* result,int& resSize){
        int i = 0, j = 0, k = 0;
        while (i < resSize){
            if (j < len1 && k < len2){
                if (num1[j] > num2[k])
                    result[i++] = num1[j++];
                else if (num1[j] < num2[k])
                    result[i++] = num2[k++];
                else{
                    int remaining1 = len1 - j, remaining2 = len2 - k, tmp = num1[j];
                    int flag = memcmp(num1 + j, num2 + k, sizeof(int) * MIN(remaining1, remaining2));
                    flag = (flag == 0 ? (remaining1>remaining2 ? 1 : -1) : flag);
                    int * num = flag > 0 ? num1 : num2;
                    int & cnt = flag > 0 ? j : k;
                    int len = flag > 0 ? len1 : len2;
                    while (num[cnt]==tmp && cnt < len && i<resSize) result[i++] = num[cnt++];
                }
            }
            else if (j < len1) result[i++] = num1[j++];
            else result[i++] = num2[k++];
        }
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k){
        int soi = sizeof(int), len1 = nums1.size(), len2 = nums2.size(), step = k*soi;
        int minL1 = MAX(0, k - len2), maxL1 = MIN(k, len1), minL2 = k - maxL1, maxL2 = k - minL1, range = maxL1 - minL1 + 1;
        int * res = new int[range * k * 2 + 2 * k], *dp1 = res + k, *dp2 = res + range*k+k, *tmp=res+range*2*k+k;
        memset(res, 0, step);
        int sortedLen1 = 1, sortedLen2 = 1;
        if (len1 == 0 && len2 > 0) getMax(&nums2[0], len2, res, k, sortedLen2);
        else if (len1 > 0 && len2 == 0) getMax(&nums1[0], len1, res, k, sortedLen2);
        else if (len1 > 0 && len2 > 0){
            dp(&nums1[0], len1, sortedLen1, minL1, maxL1, dp1,k);
            dp(&nums2[0], len2, sortedLen2, minL2, maxL2, dp2,k);
            if (sortedLen1 + sortedLen2 > k){
                merge(dp1 + k*(maxL1 - sortedLen1), sortedLen1, dp2 + k*(maxL2 - sortedLen2), sortedLen2, tmp, k);
                vector<int> resv(tmp, tmp + k);
                delete[] res;
                return resv;
            }
            for (int i = minL1; i <= maxL1; ++i){
                merge(dp1+k*(maxL1-i), i, dp2+k*(maxL2-k+i), (k-i), tmp,k);
                if (memcmp(res, tmp, step) < 0) memcpy(res, tmp, step);
            }
        }
        vector<int> resv(res, res + k);
        delete[] res;
        return resv;
    }
};

/**
Create Maximum Number
Difficulty: Hard

Given two arrays of length m and n with digits 0-9 representing two numbers. 
Create the maximum number of length k <= m + n from digits of the two. The 
relative order of the digits from the same array must be preserved. Return 
an array of the k digits. You should try to optimize your time and space 
complexity.

Example 1:

nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
return [9, 8, 6, 5, 3]

Example 2:

nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
return [6, 7, 6, 0, 4]

Example 3:

nums1 = [3, 9]
nums2 = [8, 9]
k = 3
return [9, 8, 9] 
 */
