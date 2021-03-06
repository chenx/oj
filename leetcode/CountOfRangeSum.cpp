// Works. Tested. Modified from Solution2.
// multiset.lower_bound(v): return the iterator of first element >= v.
// multiset.upper_bound(v): return the iterator of the first element > v.
// std::distance(it1, it2): find distance of two iterators. 
//          use "operator-" if it is random access, else use "operator++".
// see: 
// [1] http://www.cplusplus.com/reference/set/multiset/lower_bound/
// [2] http://www.cplusplus.com/reference/iterator/distance/
//
// Note: Solution3 actually implements the multiset.
//
class Solution5 {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> sumset;
        sumset.insert(0); // it's "sum" that's inserted, so start with sum = 0.
        
        long long sum = 0;
        int ct = 0;
        
        for (int i = 0; i < nums.size(); ++ i) {
            sum += nums[i];
            // lower <= sums[i] - sums[j] <= upper ==>
            // sums[i] - upper <= sums[j] <= sums[i] - lower
            ct += distance(sumset.lower_bound(sum - upper), 
                           sumset.upper_bound(sum - lower));
            sumset.insert(sum); // note it's "sum" that's inserted, not nums[i].
        }
        
        return ct;
    }
};


// Works. Tested. 
// From: https://leetcode.com/discuss/79632/multiset-solution-100ms-binary-search-tree-180ms-mergesort
//
// The basic idea is to use a multiset to save sum, where sum at 
// i = nums[0]+...+ nums[i]. At each i, only those sum[j] that 
// satisfies lower=< sum[i]-sum[j] <= upper can generate a valid 
// range[j,i]. so we only need to calculate how many j (0=< j< i) 
// satisfy sum[i]-upper =< sum[j] <= sum[i]-lower. The STL multiset 
// can take care of sort and find upperbound, lowerbound j. Since 
// the multiset is usually implemented with Red-black tree, so 
// those operations should have complexity of O(logN). So in total, 
// the complexity is O(NlogN) (except the distance part). 
// Note: distance is O(N), so it's actually O(N^2logN).
class Solution4 {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> pSum;
        int res = 0,  i; 
        long long left, right, sum=0;
        for(i=0,pSum.insert(0); i<nums.size(); ++i)
        {
            sum += nums[i];
            res += std::distance(pSum.lower_bound(sum-upper), pSum.upper_bound(sum-lower));
            pSum.insert(sum);
        }
        return res;
    }
};

/////////
// Works, tested.
// Solution3 is modified from Solution2. Much more clean and understandable.

class Node {
public:
    long long val;
    int size;  // number of nodes in tree using this node as root.
    Node * left, * right;
    Node(long long v) : val(v), size(1), left(NULL), right(NULL) {}
};

// An augmented BST, with a field "size" for number of nodes in this tree.
// This is Order Statistics Tree: https://en.wikipedia.org/wiki/Order_statistic_tree
class Tree {
public:
    Tree() : root(NULL) {}
    void insert(long long v) { insert(root, v); }
    int queryLE(long long num) { return queryLE(root, num); }
    int lower_bound(long long num) { return queryLE(root, num - 1); }
    int upper_bound(long long num) { return queryLE(root, num); }

private:
    Node *root;

    void insert(Node *& node, long long num) {
        if (! node) {
            node = new Node(num);
            return;
        }

        if (num < node->val) insert(node->left, num);
        else if (num > node->val) insert(node->right, num);

        node->size ++; // number of nodes in left and right subtrees.
    }

    // return number of nodes whose value <= num.
    int queryLE(Node * node, long long num) {
        if (node == NULL) return 0;

        if (num < node->val) {
            return queryLE(node->left, num);
        }
        else if (num > node->val) {
            int temp = node->size - (node->right ? node->right->size : 0);
            return queryLE(node->right, num) + temp;
        }
        else { // number of nodes in left subtree.
            return node->size - (node->right ? node->right->size : 0);
        }
    }    
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        //multiset<long long> t; // multiset.
        Tree t;
        t.insert(0);

        long long sum = 0;
        int ct = 0;

        for(int i = 0;i < nums.size(); ++ i)
        {
            sum += nums[i];
            ct += t.upper_bound(sum - lower) - t.lower_bound(sum - upper);
            t.insert(sum);
        }
        
        return ct;
    }
};


/////////

//
// Solution below works. Tested. 
// From: https://leetcode.com/discuss/82550/bst-solution-in-192ms
//
class Node
{
public:
  long long num;
  int size;
  Node *ls,*rs;
  Node()
  {
      ls=NULL;
      rs=NULL;
      size=1;
  }
};

class Solution2 {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        init();
        int ans=0;
        long long presum=0;

        insert(0,root);
        for(int i=0;i<nums.size();i++)
        {
            presum+=nums[i];
            long long MT=presum-upper;
            long long LT=presum-lower;
            ans+=queryLT(LT,root)-queryLT(MT-1,root);
            insert(presum,root);
        }
        return ans;
    }
private:
    Node *root;
    void init()
    {
        root=NULL;
    }
    void insert(long long num,Node *&cur)
    {
        if(!cur) 
        {
            cur=new Node();
            cur->num=num;
            return;
        }

        if(num==cur->num)
        {
            cur->size++;
            return;
        }
        else if(num>cur->num)
        {
            insert(num,cur->rs);
            cur->size++;
        }
        else
        {
            insert(num,cur->ls);
            cur->size++;
        }

    }

    int queryLT(long long num, Node *cur)
    {
        if(cur==NULL) return 0;

        if(cur->num<num)
        {
            int temp=cur->size-((!cur->rs)?0:cur->rs->size);
            return queryLT(num,cur->rs)+temp;
        }
        else if(cur->num>num)
        {
            return queryLT(num,cur->ls);
        }

        else return cur->size-((!cur->rs)?0:cur->rs->size);
    }

};


// Should work. But times out for large input.
// O(n^2)
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size(), ct = 0;
        
        for (int i = 0; i < n; ++ i) {
            int sum = 0;
            for (int j = i; j < n; ++ j) {
                sum += nums[j];
                if (sum >= lower && sum <= upper) ++ ct;
            }
        }
        
        return ct;
    }
};


/**
Count of Range Sum
Difficulty: Hard

Given an integer array nums, return the number of range sums 
that lie in [lower, upper] inclusive.

Range sum S(i, j) is defined as the sum of the elements in 
nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2. 
 */
 
// Comment: Definition for range sums above is confusing, including the example.
