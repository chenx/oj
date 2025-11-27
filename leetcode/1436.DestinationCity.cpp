class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, set<string>> graph;
        set<string> cities;
        for (auto path : paths) {
            graph[path[0]].insert(path[1]);
            cities.insert(path[0]);
            cities.insert(path[1]);
        }

        for (string city : cities) {
            if (graph[city].empty()) return city;
        }
        return "";
    }
};


/**
1436. Destination City
Easy

You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from 
cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one 
destination city.

 

Example 1:

Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo" 
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. 
Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
 */
