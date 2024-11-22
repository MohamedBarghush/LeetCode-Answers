class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> memo(n, -1); // Stores the count for each node
        vector<int> result(n, 0); // Result for each node

        // Helper to process a node and calculate visits
        auto calculateVisits = [&](int start) {
            vector<int> path;
            unordered_map<int, int> indexMap;
            int node = start;

            // Traverse the path
            while (memo[node] == -1 && indexMap.find(node) == indexMap.end()) {
                indexMap[node] = path.size();
                path.push_back(node);
                node = edges[node];
            }

            // If node is part of a cycle
            int cycleSize = 0;
            if (memo[node] == -1) {
                int cycleStartIndex = indexMap[node];
                cycleSize = path.size() - cycleStartIndex;
                for (int i = cycleStartIndex; i < path.size(); i++) {
                    memo[path[i]] = cycleSize;
                }
            }

            // Propagate memoization for nodes before the cycle
            for (int i = path.size() - 1; i >= 0; i--) {
                if (memo[path[i]] == -1) {
                    memo[path[i]] = 1 + memo[edges[path[i]]];
                }
            }
        };

        // Compute visits for each node
        for (int i = 0; i < n; i++) {
            if (memo[i] == -1) {
                calculateVisits(i);
            }
            result[i] = memo[i];
        }

        return result;
    }
};