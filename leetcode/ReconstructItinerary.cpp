// Works.
class Solution5 {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> ans;
        map<string, multiset<string>> m; // use multiset! may contain duplicate values.
        for (auto t : tickets) m[t.first].insert(t.second);

        find(ans, m, "JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void find(vector<string> & ans, map<string, multiset<string>> &m, string airport) {
        //for (string next : m[airport]) { // cannot use this, since will modify list in loop.
        while (m[airport].size() > 0) {
            string next = *m[airport].begin();
            m[airport].erase(m[airport].begin()); // cannot use m[airport].erase(next), since all "next" will be gone.
            find(ans, m, next);
        }
        ans.push_back(airport);
    }
};

// Works too. Slighly modified from Solution3.
class Solution4 {
    unordered_map<string, multiset<string>> m;
    vector<string> route;
    
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (auto t : tickets) m[t.first].insert(t.second);
        visit("JFK");
        return route;
    }
    
    void visit(string airport) {
        while (m[airport].size() > 0) {
            string next = *m[airport].begin();
            m[airport].erase(m[airport].begin());
            visit(next);
        }
        route.insert(route.begin(), airport);
    }
};

// Works too! Tested. Use recursion.
// From: https://leetcode.com/discuss/84659/short-ruby-python-java-c
class Solution3 {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (auto ticket : tickets)
            targets[ticket.first].insert(ticket.second);
        visit("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }
    
    void visit(string airport) {
        while (targets[airport].size()) {
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(next);
        }
        route.push_back(airport);
    }
private:
    map<string, multiset<string>> targets;
    vector<string> route;
};

// Works too! Tested. Modified from Solution. By: XC.
// Use vector<string> instead of multiset<string> for graph.
// Added a sort procedure for vector<string> to guarantee the lexicographical order.
class Solution2 {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        // Each node (airport) contains a set of outgoing edges (destination).
        unordered_map<string, vector<string>> graph;
        // We are always appending the deepest node to the itinerary, 
        // so will need to reverse the itinerary in the end.
        vector<string> itinerary;
        if (tickets.size() == 0){
            return itinerary;
        }
        // Construct the node and assign outgoing edges
        for (pair<string, string> ticket : tickets){
            graph[ticket.first].push_back(ticket.second);
        }
        for (unordered_map<string, vector<string>>::iterator it = graph.begin(); 
             it != graph.end(); ++ it) {  // sort needed to guarantee order!
            vector<string> &v = (*it).second;
            sort(v.begin(), v.end());
        }
        
        stack<string> dfs;
        dfs.push("JFK");
        while (!dfs.empty()){
            string topAirport = dfs.top();
            if (graph[topAirport].empty()){
                itinerary.push_back(topAirport);
                dfs.pop();
            }
            else {
                dfs.push(*(graph[topAirport].begin()));
                graph[topAirport].erase(graph[topAirport].begin());
            }
        }
        // Reverse the itinerary.
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};


// Works. Tested. Use stack to avoid recursion.
// Multiset is used to guarantee lexicographical order! 
// Multiset is a BST, stores elements that could duplicate. Element's value is also key.
// From: https://leetcode.com/discuss/85439/short-iterative-solution-explanation-recursive-backtracking
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        // Each node (airport) contains a set of outgoing edges (destination).
        unordered_map<string, multiset<string>> graph;
        // We are always appending the deepest node to the itinerary, 
        // so will need to reverse the itinerary in the end.
        vector<string> itinerary;
        if (tickets.size() == 0){
            return itinerary;
        }
        // Construct the node and assign outgoing edges
        for (pair<string, string> ticket : tickets){
            graph[ticket.first].insert(ticket.second);
        }
        stack<string> dfs;
        dfs.push("JFK");
        while (!dfs.empty()){
            string topAirport = dfs.top();
            if (graph[topAirport].empty()){
                // If there is no more outgoing edges, append to itinerary
                // Two cases: 
                // 1. If it searchs the terminal end first, it will simply get
                //    added to the itinerary first as it should, and the proper route
                //    will still be traversed since its entry is still on the stack.
                // 2. If it search the proper route first, the dead end route will also
                //    get added to the itinerary first.
                itinerary.push_back(topAirport);
                dfs.pop();
            }
            else {
                // Otherwise push the outgoing edge to the dfs stack and 
                // remove it from the node.
                dfs.push(*(graph[topAirport].begin()));
                graph[topAirport].erase(graph[topAirport].begin());
            }
        }
        // Reverse the itinerary.
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};

/**
Reconstruct Itinerary
Difficulty: Medium

Given a list of airline tickets represented by pairs of departure 
and arrival airports [from, to], reconstruct the itinerary in order. 
All of the tickets belong to a man who departs from JFK. Thus, the 
itinerary must begin with JFK.

Note:

    1. If there are multiple valid itineraries, you should return the 
       itinerary that has the smallest lexical order when read as a 
       single string. For example, the itinerary ["JFK", "LGA"] has a 
       smaller lexical order than ["JFK", "LGB"].
    2. All airports are represented by three capital letters (IATA code).
    3. You may assume all tickets form at least one valid itinerary.

Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].

Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. 
But it is larger in lexical order. 
 */
