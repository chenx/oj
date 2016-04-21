class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        priority_queue<int, vector<int>, std::less<int>> maxQ;
        priority_queue<int, vector<int>, std::greater<int>> minQ;
        
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); ++ i) {
            int n = nums[i];
            
            int minv = minQ.empty() ? INT_MAX : minQ.top(),
                maxv = maxQ.empty() ? INT_MIN : maxQ.top();
                
            if (n >= minv) minQ.push(n);
            else maxQ.push(n);
            
            if (minQ.size() == maxQ.size() + 2) {
                maxQ.push(minQ.top());
                minQ.pop();
            }
            else if (maxQ.size() == minQ.size() + 2) {
                minQ.push(maxQ.top());
                maxQ.pop();
            }
            
            if (minQ.size() == maxQ.size() + 1) ans.push_back(minQ.top());
            else if (minQ.size() == maxQ.size() - 1) ans.push_back(maxQ.top());
            else ans.push_back( min(minQ.top(), maxQ.top()) );
            //else ans.push_back( (minQ.top() + maxQ.top())/2 ); // maybe should use this..
        }
        
        return ans;
    }
};


/**
Median of two Sorted Arrays

There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays.

Example

Given A=[1,2,3,4,5,6] and B=[2,3,4,5], the median is 3.5.

Given A=[1,2,3] and B=[4,5], the median is 3.
Challenge

The overall run time complexity should be O(log (m+n)).

 */
