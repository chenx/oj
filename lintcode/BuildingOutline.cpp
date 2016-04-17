// Works.
// This is the same as the Skyline problem, just output format is different.
// Instead of output (start, height), now output (start, end, height).
// Here use start/height to keep track of the current block.
class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        vector<vector<int> > edges;
        for (auto b : buildings) {
            edges.push_back({b[0], - b[2]});
            edges.push_back({b[1],   b[2]});
        }
        sort(edges.begin(), edges.end());
        
        vector<vector<int> > out;
        multiset<int> ht;
        ht.insert(0);
        
        int curH = 0, preH = 0, start = -1, height;
        for (auto e : edges) {
            if (e[1] < 0) ht.insert(- e[1]);
            else ht.erase(ht.find(e[1]));
            
            curH = * ht.rbegin();
            if (curH != preH) {
                if (start != -1 && height != 0) {
                    out.push_back({start, e[0], height});
                }
                start = e[0];
                height = curH;
                    
                preH = curH;
            }
        }
        
        return out;
    }
};


/**
Building Outline

Given N buildings in a x-axis，each building is a rectangle and can be 
represented by a triple (start, end, height)，where start is the start 
position on x-axis, end is the end position on x-axis and height is the 
height of the building. Buildings may overlap if you see them from far 
away，find the outline of them。

An outline can be represented by a triple, (start, end, height), where 
start is the start position on x-axis of the outline, end is the end 
position on x-axis and height is the height of the outline.

Building Outline

Notice

Please merge the adjacent outlines if they have the same height and 
make sure different outlines cant overlap on x-axis.

Example

Given 3 buildings：

[
  [1, 3, 3],
  [2, 4, 4],
  [5, 6, 1]
]

The outlines are：

[
  [1, 2, 3],
  [2, 4, 4],
  [5, 6, 1]
]
 */
