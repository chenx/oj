// Works. Further simplified from Solution5.
class Solution5_2 {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> edges;
        for (auto b : buildings) {
            edges.push_back(vector<int>({b[0], - b[2]})); // left,  height
            edges.push_back(vector<int>({b[1],   b[2]})); // right, height
        }
        sort(edges.begin(), edges.end());
        
        vector<pair<int, int>> ans;
        multiset<int> ht;
        ht.insert(0);
        
        int curH = 0, preH = 0;
        for (auto e : edges) {
            if (e[1] < 0) ht.insert(- e[1]); // insert height at left edge
            else ht.erase(ht.find(e[1]));    // remove height at right edge
            
            curH = * ht.rbegin(); // current max height.
            if (curH != preH) {
                ans.push_back(pair<int, int>(e[0], curH)); // left, height
                preH = curH;
            }
        }
        
        return ans;
    }
};

// Works too.
class Solution5 {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> edges; // pair<int,int> or vector<int>, both ok.
        for (auto b : buildings) {
            int L = b[0], R = b[1], H = b[2];
            edges.push_back(vector<int>({L, -H}));
            edges.push_back(vector<int>({R,  H}));
        }
        sort(edges.begin(), edges.end());
        
        vector<pair<int, int>> ans;
        multiset<int> ht;
        ht.insert(0); // must insert ground level 0 first.
        
        int preH = 0, curH = 0; // both are 0.
        for (auto edge : edges) {
            if (edge[1] < 0) ht.insert(- edge[1]);
            else ht.erase(ht.find(edge[1])); // must use ht.find(), cannot be: ht.erase(edge[1])
            
            curH = * ht.rbegin(); // largest in ht.
            if (curH != preH) {   // must compare, so no duplicate.
                ans.push_back(pair<int, int>(edge[0], curH));
                preH = curH;
            }
        }
        
        return ans;
    }
};

// Works. Same as Solution3, rewritten to be more clear.
class Solution4 {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> edges;
        for (auto b : buildings) {
            int L = b[0], R = b[1], H = b[2];
            edges.push_back(pair<int, int>(L, -H));
            edges.push_back(pair<int, int>(R,  H));
        }
        sort(edges.begin(), edges.end());
        
        vector<pair<int, int>> ans;
        multiset<int> ht; // height.
        ht.insert(0); // start height is 0, ground level.
        
        int prevH = 0, curH = 0; // previous and current height.
        for (int i = 0; i < edges.size(); ++ i) {
            pair<int, int> & e = edges[i];
            if (e.second < 0) ht.insert(- e.second); // add edge
            else ht.erase(ht.find(e.second));        // remove edge
            
            // current largest height. This works too: *(-- ht.end()); 
            int curH = * ht.rbegin(); 
            if (curH != prevH) {
                ans.push_back(pair<int, int>(e.first, curH));
                prevH = curH;
            }
        }
        return ans;
    }
};

// Works. Tested. Similar to Solution2, but use more common data structures.
// From: https://leetcode.com/discuss/83498/recommend-beginners-implementation-detailed-explanation
// Also see: https://briangordon.github.io/2014/08/the-skyline-problem.html
class Solution3 {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> edges;
        
        for(int i = 0; i < buildings.size(); ++ i){
            int L = buildings[i][0], R = buildings[i][1], H = buildings[i][2];
            /*** make sure : for the same left point we use the bigger height ***/
            edges.push_back(make_pair(L, - H));
            edges.push_back(make_pair(R, H));
        }
        sort(edges.begin(), edges.end());
        
        vector<pair<int, int>> result;
        
        multiset<int> m; /*** store the max height util current pos ***/
        m.insert(0); /*** left most height ***/
        
        int pre = 0, cur = 0;
        for(int i = 0; i < edges.size(); ++ i){
            pair<int, int> e = edges[i];
            if (e.second < 0) m.insert(- e.second); // left edge
            else m.erase(m.find(e.second)); // right edge
            
            cur = *(m.rbegin()); // current edge with max height
            if (cur != pre){
                result.push_back(make_pair(e.first, cur));
                pre = cur;
            }
        }
        return result;
    }
};

// Works too. Tested.
// General idea:
//  Step 1:
//    Use a multimap to sort all boundary points. For a start point of an interval, 
//    let the height be positive; otherwise, let the height be negative. 
//    Time complexity: O(n log n)
//    
//  Step 2:
//    Use a multiset (rather than a heap/priority_queue) to maintain the 
//    current set of heights to be considered. If a new start point is met, 
//    insert the height into the set, otherwise, delete the height. The 
//    current max height is the back() element of the multiset. For each point, 
//    the time complexity is O(log n). The overall time complexity is *O*(n log n).
//  
//  Step 3:
//    Delete the points with equal heights. Time: O(n)
//
// Time Complexity: O(n log n)
// Space Complexity: O(n)
// From: https://leetcode.com/discuss/61274/17-line-log-time-space-accepted-easy-solution-explanations
class Solution2 {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        // Step 1:
        multimap<int, int> coords;
        for (const vector<int> & building : buildings) {
            coords.emplace(building[0], building[2]);
            coords.emplace(building[1], -building[2]);
        }

        // Step 2:
        multiset<int> heights = { 0 };
        map<int, int> corners;
        for (const pair<int, int> & p : coords) {
            if (p.second > 0) {
                heights.insert(p.second);
            }
            else {
                heights.erase(heights.find(-p.second));
            }
            int cur_y = *heights.rbegin();
            corners[p.first] = cur_y;
        }

        // Step 3:
        function<bool(pair<int, int> l, pair<int, int> r)> eq2nd = [](pair<int, int> l, pair<int, int> r){ return l.second == r.second;  };
        vector<pair<int, int>> results;
        unique_copy(corners.begin(), corners.end(), back_insert_iterator<vector<pair<int, int>>>(results), eq2nd);
        return results;
    }
};

// Works. Tested.
// From: https://leetcode.com/problems/the-skyline-problem/
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> edges;
        int left, right, height;
        for(int i=0; i<buildings.size(); i++){
            left=buildings[i][0];
            right=buildings[i][1];
            height=buildings[i][2];
            /*** make sure : for the same left point we use the bigger height ***/
            edges.push_back(make_pair(left, -height));
            edges.push_back(make_pair(right, height));
        }
        sort(edges.begin(), edges.end());
        vector<pair<int, int>> result;
        /*** use the multiset to store the max height util current pos ***/
        multiset<int> m;
        /*** left most height ***/
        m.insert(0);
        int pre=0, cur=0;
        for(int i=0; i<edges.size(); i++){
            pair<int, int> e=edges[i];
            if(e.second < 0)  m.insert(-e.second);
            else m.erase(m.find(e.second));
            cur=*(m.rbegin());
            if(cur!=pre){
                result.push_back(make_pair(e.first, cur));
                pre=cur;
            }
        }
        return result;
    }
};

