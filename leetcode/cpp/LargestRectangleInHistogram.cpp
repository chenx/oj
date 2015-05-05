//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/26/2012
// @Last modified: 12/26/2012
//
//
// http://homeofcox-cs.blogspot.com/2010/04/max-rectangle-in-histogram-problem.html
//
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
      stack<int> s;
      int i, max, top_v;
      int start = -1; // the position before the last 0, used by left.
    
      max = 0;
      for (i = 0; i < height.size(); i ++) {
        if (s.size() == 0) {
          s.push(i);
          continue;
        }
    
        top_v = height[s.top()];
        if (height[i] >= top_v) {
          s.push(i);
        } else if (height[i] < top_v) {
          getMax(height, s, height[i], i - 1, max, start);
          s.push(i); 
          if (height[i] == 0) start = i - 1;
        }
      }
    
      getMax(height, s, 0, i - 1 , max, start);
      return max;
    }
        
    void getMax(vector<int> hist, stack<int> &s, 
                int newHeight, int right, int & max, int & start) {
      int height, left = 0, area;
      while (s.size() > 0 && hist[s.top()] > newHeight) {
        height = hist[s.top()];
        s.pop();
        left = (s.size() > 0) ? s.top() : start; 
        while (s.size() > 0 && hist[s.top()] == height) {
          s.pop();
          left = (s.size() > 0) ? s.top() : start; 
        }
    
        area = height * (right - left);
        if (area > max) max = area;
      }
    }
    
};

// This works too! O(n). Better.
// http://www.mitbbs.com/article_t/JobHunting/32268417.html
// Method: 
//   while current bar height >= top bar in stack, push current bar to stack.
//   else, pop bars larger than curren bar from stack 
//         and calc the rectangle area, replace max area if applicable.
class Solution2 {
public:
 
    int largestRectangleArea(vector<int> &h) {
        stack<int> p;
        int i = 0, m = 0;
        h.push_back(0);
        while(i < h.size()) {
            if(p.empty() || h[p.top()] <= h[i])
                p.push(i++);
            else {
                int t = p.top();
                p.pop();
                m = max(m, h[t] * (p.empty() ? i : i - p.top() - 1 ));
            }
        }
        return m;
    }
};

// Same as Solution2, but don't use height.push_back(0).
// Useful for the case of int h[], where you can't conveniently push back.
class Solution3 {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        int m = 0, i = 0;
        
        vector<int> &h = height;
        //h.push_back(0);
        
        while (i < h.size()) {
            if (s.size() == 0 || h[i] >= h[s.top()]) {
                s.push(i ++);
            }
            else {
                int t = s.top();
                s.pop();
                m = max(m, h[t] * (s.empty() ? i : i - s.top() - 1));
            }
        }
        
        while(!s.empty()) {
            int t = s.top();
            s.pop();
            m = max(m,h[t]* (s.empty() ? i : i - s.top() - 1));
        }
        
        return m;
    }
};



// binary search. O(nlogn). Easier to think of.
class Solution4 {
public:
    int largestRectangleArea(vector<int> &height) {
        return GetBiggestRectBin(height, 0, height.size()-1);
    }

    int getArea(vector<int> &h, int L, int R)
    {
        if (L > R) return 0;
    
        int minIndex = L;
        for (int i = L+1; i <= R; ++ i) {
            if (h[minIndex] > h[i]) minIndex = i;
        }
       
        int width = R - L + 1;
        int areaT = width * h[minIndex];
        int areaL = getArea(h, L, minIndex - 1);
        int areaR = getArea(h, minIndex + 1, R);
    
        return max(areaT, max(areaL, areaR));
    } 
};
