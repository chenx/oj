/*
Method:
Get all the unique elements, get the subsets VS.
Get all the duplicated elements and their count.

Now, for each duplicated element, e.g., 
    3 duplicated twice, then {3} and {3,3} are the ones to add:
        for each element of VS, add {3}, add the obtained elements to VS;
        for each element of VS, add {3,3}, add the obtained elements to VS;

http://csjobinterview.wordpress.com/2012/10/04/distinct-subsets-for-an-array-with-duplicated-elements/
Solution:

1) The most intuitive way is to find out all possible subsets and put them 
   into hashtable, and then display only keys. It is easy to implement, however, 
   takes lot of additional memory, assume that when we have an array with 10000 
   elements while all elememnt is ��1��, in this way one needs to have 2^1000 
   space to store all possible subsets, however, we both know that there are 
   only 1001 distinct subsets as {}, {1},{1,1},��,{1,1��.1}.

2) To solve this issue, we need a better approach. This blog suggests an 
   efficient approach that decompose the problem into either generate the 
   subsets from all distinct elements, or generate subsets from all duplicate 
   elements.

The algorithm goes as following:
1) For a given array Arr, find out its elements which only appear once, 
   put them into Arr_distinct. For elements which appear multiple times, 
   put them into hashtable where the key is this element, and the value 
   is the times it appears.

2) Find out all subsets from Arr_distinct, denoted as SubSets

3) For the elements which appear multiple times, create their subsets 
   SubSets_for_num. For example, if ��2�� appear 3 time, 
   SubSets_for_2 ={2}, {2,2} and {2,2,2}

4) For each element subset in the SubSets, create new datasets which 
   is combined by subset and all the SubSets_for_num created in step 
   3) and one element at a time. That is, supposse in step 3) we have 
   numbers ��2�� and ��3��, both appear 3 times, then in this iteration 
   all ELEs are only concatenated with SubSets_for_2, the SubSets_for_3 
   will be added in next iteration. After that, the new geneated dataset 
   are included into SubSets to make it larger.

5) Repeat step 4) untill all the duplicated numbers are merged.

Examples: Arr = {1,2,2,3,3}
Arr_distinct = {1}, we have two groups of subsets for duplicated 
elements, those are: {2},{2,2} and {3}, {3,3}

First of all, we find out all possible subsets (including empty subset) 
from Arr_distinct. It has 8 subsets as Subset = {{},{1}}.

Next, add {2} and {2,2} to all the elements in Subset, now we have the following 16 new subset
newCreatedSubset = {
{2},{1,2} //add {2}
{2,2},{1,2,2}  // add {2,2}}

After we put the newCreatedSubset back into Subset, the size of Subset becomes 6 as:
Subset = {{},{1},{2},{1,2},{2,2},{1,2,2}}

Now, we add {3} and {3,3} to each element in Subset to get 12 new subsets:
newCreatedSubset = {{3},{1,3},{2,3},{1,2,3},{2,2,3},{1,2,2,3} // add{3}
{3,3},{1,3,3},{2,3,3},{1,2,3,3},{2,2,3,3},{1,2,2,3,3} //add {3,3}}

Now the size of Subsets becomes 18 as:
Subset = {{},{1},{2},{1,2},{2,2},{1,2,2},
{3},{1,3},{2,3},{1,2,3},{2,2,3},{1,2,2,3}, 
{3,3},{1,3,3},{2,3,3},{1,2,3,3},{2,2,3,3},{1,2,2,3,3}}
 */
 
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > vs;
        if (S.size() == 0) return vs;
        
        vector<int> S_uniq; // store unique elements.
        vector<int> S_dupl; // store (elem, count) pairs.
        
        sort(S.begin(), S.end());
        int val = S[0];
        int ct = 1;
        for (int i = 1; i < S.size(); ++ i) {
            if (S[i] == val) {
                ++ ct;
            }
            else {
                if (ct == 1) {
                    S_uniq.push_back(val);
                }
                else {
                    S_dupl.push_back(val);
                    S_dupl.push_back(ct);
                }
                
                val = S[i];
                ct = 1;
            }
        }
        // The last element. Don't forget this!
        if (ct == 1) {
            S_uniq.push_back(val);
        }
        else {
            S_dupl.push_back(val);
            S_dupl.push_back(ct);
        }
        
        vs = subsets(S_uniq);
        
        int len;
        for (int i = 0; i < S_dupl.size(); i += 2) {
            val = S_dupl[i];
            ct  = S_dupl[i+1];
            len = vs.size(); // len is fixed for each duplicated element.
            
            for (int j = 1; j <= ct; ++ j) { // Note: j is 1-based, and <= ct.
                vector<vector<int> > v = addS(vs, len, val, j);
                // combine v into vs.
                for (int k = 0; k < v.size(); ++ k) {
                    vs.push_back(v[k]);
                }
            }
        }
        
        return vs;
    }
    
    // create a vector v, whose elements are elments of vs,
    // each with additional ct number of val.
    vector<vector<int> > addS(vector<vector<int> > &vs, int len, 
                     int val, int ct) {
        vector<vector<int> > v;
        for (int i = 0; i < len; ++ i) {
            vector<int> tmp = vs[i];
            for (int j = 0; j < ct; ++ j) {
                tmp.push_back(val);
            }
            // This sort is not absolutely necessary. 
            // Just to guarantee leetcode handles it right.
            sort(tmp.begin(), tmp.end()); 
            v.push_back(tmp);
        }
        return v;
    }
    
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result;
        
        sort(S.begin(), S.end());
        
        int n = S.size();
        int np = (int) pow((double)2, (double)n);
        
        for (int i = 0; i < np; i ++) {
            vector<int> v;
            for (int j = 0, shift = 1; j <= i; j ++) {
                if (i & shift) { 
                    v.push_back(S[j]); // output S[i];
                }
                shift <<= 1;
            }
            result.push_back(v);
        }
        
        return result;
    }    
};

/*
Problem:

 Given a collection of integers that might contain duplicates, S, 
 return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

 */
