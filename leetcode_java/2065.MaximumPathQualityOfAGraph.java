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
