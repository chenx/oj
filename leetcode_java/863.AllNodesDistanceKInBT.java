// From: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/editorial/
// Time complexity: O(n), Space complexity: O(n)
class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        dfsBuild(root, /*parent=*/ null, graph);

        List<Integer> answer = new ArrayList<>();
        Set<Integer> visited = new HashSet<>();
        Queue<int[]> queue = new LinkedList<>();

        // Add the target node to the queue with a distance of 0
        queue.add(new int[] { target.val, 0 });
        visited.add(target.val);

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int node = cur[0], distance = cur[1];

            // If the current node is at distance k from target,
            // add it to the answer list and continue to the next node.
            if (distance == k) {
                answer.add(node);
                continue;
            }

            // Add all unvisited neighbors of the current node to the queue.
            for (int neighbor : graph.getOrDefault(node, new ArrayList<>())) {
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    queue.add(new int[] { neighbor, distance + 1 });
                }
            }
        }

        return answer;
    }

    // Recursively build the undirected graph from the given binary tree.
    private void dfsBuild(TreeNode root, TreeNode parent, Map<Integer, List<Integer>> graph) {
        if (root == null) return;

        if (parent != null) {
            int rootVal = root.val, parentVal = parent.val;
            // graph.putIfAbsent(rootVal, new ArrayList<>());
            // graph.putIfAbsent(parentVal, new ArrayList<>());
            if (! graph.containsKey(rootVal)) graph.put(rootVal, new ArrayList());
            if (! graph.containsKey(parentVal)) graph.put(parentVal, new ArrayList());

            graph.get(rootVal).add(parentVal);
            graph.get(parentVal).add(rootVal);
        }

        if (root.left != null) {
            dfsBuild(root.left, root, graph);
        }

        if (root.right != null) {
            dfsBuild(root.right, root, graph);
        }
    }
}

/**
863. All Nodes Distance K in Binary Tree
Medium

Given the root of a binary tree, the value of a target node target, and an integer k, return an array 
of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.
 */
