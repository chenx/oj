class NumArray8 {
    vector<int> base, sum;
public:
    NumArray(vector<int>& nums) {
        base = nums;

        sum.resize(nums.size() + 1);
        sum[0] = 0;
        for (int i = 1; i < nums.size() + 1; ++ i) sum[i] = sum[i-1] + nums[i - 1];
    }
    
    void update(int index, int val) {
        int diff = val - base[index];
        for (int i = index+1; i < sum.size(); ++ i) sum[i] += diff;
        base[index] = val;
    }
    
    int sumRange(int left, int right) {
        return sum[right + 1] - sum[left];
    }
};


// Works too.
class NumArray7 {
    vector<int> base, sum;
public:
    NumArray(vector<int>& nums) {
        base = nums;

        sum.resize(base.size());
        sum[0] = base[0];
        for (int i = 1; i < nums.size(); ++ i) sum[i] = sum[i-1] + base[i];
    }
    
    void update(int index, int val) {
        int diff = val - base[index];
        for (int i = index; i < sum.size(); ++ i) sum[i] += diff;
        base[index] = val;
    }
    
    int sumRange(int left, int right) {
        // This works too:
        // if (left == 0) return sum[right];
        // else return sum[right] - sum[left - 1];
        return sum[right] - sum[left] + base[left];
    }
};

// Works too. 1) omit parent()/lowbit() function. 2) use i+1 in add().
class NumArray6 {
public:
    NumArray(vector<int> &nums) {
        base = nums;
        BIT.resize(base.size() + 1, 0);
        
        for (int i = 0; i < base.size(); ++ i)
            add(i + 1, nums[i]);
    }
    
    void update(int i, int val) {
        add(i + 1, val - base[i]);
        base[i] = val;
    }
    
    int sumRange(int i, int j) {
        return sum(j + 1) - sum(i);
    }

private:
    vector<int> base, BIT;
    
    void add(int i, int v) {
        for (i; i <= base.size(); i += (i & -i)) {
            BIT[i] += v;
        }
    }
    
    int sum(int i) {
        int v = 0;
        for (; i > 0; i -= (i & -i)) {
            v += BIT[i];
        }
        return v;
    }
};


// Works. Modified from NumArray4. Hard to say which is better.
// Now use a separate add() function.
class NumArray5 {
public:
    NumArray(vector<int> &nums) {
        int len = nums.size();
        base = nums;
        BIT.resize(len + 1, 0);
        
        for (int i = 0; i < len; ++ i) 
            add(i, nums[i]);
    }
    
    void update(int i, int val) {
        add(i, val - base[i]);
        base[i] = val;
    }
    
    int sumRange(int i, int j) {
        return sum(j+1) - sum(i);
    }

private:
    vector<int> BIT; // Binary Indexed Tree, or Fenwick Tree.
    vector<int> base;   // keep the value of the array
    
    int parent(int i){  // return index of parent of x (before 0).
        return i & -i;  // this works too: x & (~x + 1);
    }
    
    void add(int i, int diff) { // update from i to leaf.
        for(++ i; i <= base.size(); i += parent(i))
            BIT[i] += diff;
    }
    
    int sum(int i) {    // get sum, from i to root (exclusive).
        int s = 0;
        for(; i > 0; i -= parent(i))
            s += BIT[i];
        return s;
    }
};

// Works. Modified from NumArray2.
// Use Binary Indexed Tree, of Fenwick tree. Log(n) in update/sum.
// See: 
// [1] https://en.wikipedia.org/wiki/Fenwick_tree
// [2] http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
// [3] https://leetcode.com/discuss/80849/recommend-beginners-implementation-detailed-explaination
class NumArray4 {
public:
    NumArray(vector<int> &nums) {
        int len = nums.size();
        base.resize(len, 0);
        BITree.resize(len + 1, 0);
        
        for (int i = 0;i < len; ++ i) 
            update(i, nums[i]);
    }
    
    void update(int i, int val) { // update from i to leaf.
        int diff = val - base[i];
        base[i] = val;
        for(++ i; i <= base.size(); i += parent(i))
            BITree[i] += diff;
    }
    
    int sumRange(int i, int j) {
        return sum(j+1) - sum(i);
    }

private:
    vector<int> BITree; // Binary Indexed Tree, or Fenwick Tree.
    vector<int> base;   // keep the value of the array
    
    int parent(int i){  // return index of parent of x (before 0).
        return i & -i;  // this works too: x & (~x + 1);
    }
    
    int sum(int i) {    // get sum, from i to root (exclusive).
        int s = 0;
        for(; i > 0; i -= parent(i))
            s += BITree[i];
        return s;
    }
};

// Works. From: https://leetcode.com/discuss/80849/recommend-beginners-implementation-detailed-explaination
// Why?
class NumArray3 {
    private:
        vector<int> _nums;
        vector<int> bit;

        int lower_bit(int i){
            return i&-i;
        }

        int query(int i){
            i++;
            int sum=0;
            while(i>0){
                sum+=bit[i];
                i-=lower_bit(i);
            }
            return sum;
        }

        void add(int i, int val){
            i++;
            while(i<bit.size()){
                bit[i]+=val;
                i+=lower_bit(i);
            }
        }

    public:
        NumArray(vector<int> &nums) : _nums(nums) {
            bit.resize(nums.size()+1);
            for(int i=0; i<nums.size(); i++){
                add(i, nums[i]);
            }
        }

        void update(int i, int val) {
            if(val!=_nums[i]){
                add(i, val-_nums[i]);
                _nums[i]=val;
            }
        }

        int sumRange(int i, int j) {
            return query(j)-query(i-1);
        }
};
    
    
// Works. From: https://leetcode.com/discuss/78240/sharing-my-c-code-using-the-treelike-array-clean-and-fast
// Why?
class NumArray2 {
public:
    int t[100000]={0};
    int len;
    vector<int> tmp;        //remain the value of the array
    NumArray(vector<int> &nums) {
        len = nums.size();
        for(int i = 0;i<len;i++)
            tmp.push_back(0);
        for(int i = 0;i<len;i++)
            update(i,nums[i]);
    }
    int lowbit(int x){
        return x&(-x);
    }
    void update(int i, int val) {
        int x = val-tmp[i];
        tmp[i] = val;
        i++;
        for(;i<=len;i+=lowbit(i))
            t[i] += x;
    }
    int sum(int i){         //get the sum
        int res = 0;
        for(;i>0;i-=lowbit(i))
            res += t[i];
        return res;
    }
    int sumRange(int i, int j) {
        return sum(j+1)-sum(i);
    }
};


// Should work. But times out for large input.
class NumArray {
public:
    NumArray(vector<int> &nums) {
        if (nums.size() == 0) return;
        base = nums;
        
        int sum = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            sum += base[i];
            sums.push_back(sum);
        }
    }

    void update(int i, int val) {
        int diff = val - base[i];
        for (int j = i; j < sums.size(); ++ j) {
            sums[j] += diff;
        }
        base[i] = val;
    }

    int sumRange(int i, int j) {
        return sums[j] - sums[i] + base[i];
    }
private:
    vector<int> base;
    vector<int> sums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

/**
Range Sum Query - Mutable
Difficulty: Medium

Given an integer array nums, find the sum of the elements between 
indices i and j (i ≤ j), inclusive.
The update(i, val) function modifies nums by updating the element 
at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8

Note:

    The array is only modifiable by the update function.
    You may assume the number of calls to update and sumRange 
      function is distributed evenly.

 */
