class Solution {
    // Graph represented as adjacency list where each node stores list of [neighbor, time] pairs
    private List<int[]>[] graph;
    // Track visited nodes to avoid counting their values multiple times
    private boolean[] visited;
    // Node values array
    private int[] nodeValues;
    // Maximum time constraint for the path
    private int timeLimit;
    // Store the maximum quality found
    private int maxQuality;

    public int maximalPathQuality(int[] values, int[][] edges, int maxTime) {
        int nodeCount = values.length;
      
        // Initialize the graph as adjacency list
        graph = new List[nodeCount];
        Arrays.setAll(graph, index -> new ArrayList<>());
      
        // Build undirected graph from edges
        for (int[] edge : edges) {
            int nodeU = edge[0];
            int nodeV = edge[1];
            int travelTime = edge[2];
          
            // Add bidirectional edges
            graph[nodeU].add(new int[] {nodeV, travelTime});
            graph[nodeV].add(new int[] {nodeU, travelTime});
        }
     
        // Initialize visited array and mark starting node as visited
        visited = new boolean[nodeCount];
        visited[0] = true;
      
        // Store values and time limit for use in DFS
        this.nodeValues = values;
        this.timeLimit = maxTime;
      
        // Start DFS from node 0 with initial time 0 and initial quality as value of node 0
        dfs(0, 0, values[0]);
      
        return maxQuality;
    }

    /**
     * Performs depth-first search to find the maximum quality path
     * @param currentNode - current node in the path
     * @param currentTime - accumulated time spent so far
     * @param currentQuality - accumulated quality value so far
     */
    private void dfs(int currentNode, int currentTime, int currentQuality) {
        // Update maximum quality when we return to node 0
        if (currentNode == 0) {
            maxQuality = Math.max(maxQuality, currentQuality);
        }
      
        // Explore all neighbors of current node
        for (int[] neighborInfo : graph[currentNode]) {
            int neighborNode = neighborInfo[0];
            int travelTime = neighborInfo[1];
            int newTime = currentTime + travelTime;
          
            // Only continue if we have enough time remaining
            if (newTime <= timeLimit) {
                if (visited[neighborNode]) {
                    // If neighbor is already visited, don't add its value again
                    dfs(neighborNode, newTime, currentQuality);
                } else {
                    // Mark as visited, add its value, explore, then backtrack
                    visited[neighborNode] = true;
                    dfs(neighborNode, newTime, currentQuality + nodeValues[neighborNode]);
                    visited[neighborNode] = false;  // Backtrack
                }
            }
        }
    }
}


// Works, but time out for large input
// bfs; if time exceeds, stop; when crossing 0, record max.
class Solution {
    public int maximalPathQuality(int[] values, int[][] edges, int maxTime) {
        HashMap<Integer, HashSet<int[]>> map = new HashMap(); // node, <edge next node, time>
        for (int i = 0; i < values.length; ++ i) {
            map.put(i, new HashSet<int[]>());
        }

        for (int i = 0; i < edges.length; ++ i) {
            map.get(edges[i][0]).add(new int[]{edges[i][1], edges[i][2]});
            map.get(edges[i][1]).add(new int[]{edges[i][0], edges[i][2]});
        }

        int maxQuality = values[0];

        HashSet<Integer> used0 = new HashSet(); // visited nodes.
        used0.add(0);

        Queue<Pair<int[], HashSet<Integer>>> q = new LinkedList<Pair<int[], HashSet<Integer>>>(); 
        // <node, time, quality>, visited_nodes
        q.add(new Pair<int[], HashSet<Integer>>( new int[]{0, 0, values[0]}, used0 ));

        while(! q.isEmpty()) {
            int node = q.peek().getKey()[0];
            int time = q.peek().getKey()[1];
            int quality = q.peek().getKey()[2];
            HashSet<Integer> used = q.peek().getValue();
            q.remove();

            for (int[] val : map.get(node)) {
                int newTime = time + val[1];
                if (newTime > maxTime) continue;

                int newNode = val[0];
                int newQuality = quality;

                HashSet<Integer> used2 = new HashSet<Integer>();
                used2.addAll(used);

                if (! used2.contains(newNode)) {
                    newQuality += values[newNode];
                    used2.add(newNode);
                }
                if (newNode == 0) maxQuality = Math.max(maxQuality, newQuality);

                q.add(new Pair(new int[]{newNode, newTime, newQuality}, used2));
            }
        }

        return maxQuality;
    }
}


/**
2065. Maximum Path Quality of a Graph

There is an undirected graph with n nodes numbered from 0 to n - 1 (inclusive). You are given a 0-indexed 
integer array values where values[i] is the value of the ith node. You are also given a 0-indexed 2D integer 
array edges, where each edges[j] = [uj, vj, timej] indicates that there is an undirected edge between the 
nodes uj and vj, and it takes timej seconds to travel between the two nodes. Finally, you are given an integer maxTime.

A valid path in the graph is any path that starts at node 0, ends at node 0, and takes at most maxTime seconds 
to complete. You may visit the same node multiple times. The quality of a valid path is the sum of the values 
of the unique nodes visited in the path (each node's value is added at most once to the sum).

Return the maximum quality of a valid path.

Note: There are at most four edges connected to each node.
 */
