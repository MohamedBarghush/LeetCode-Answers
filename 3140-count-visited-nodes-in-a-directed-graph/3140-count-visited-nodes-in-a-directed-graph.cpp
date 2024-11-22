class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> memo(n, -1);
        vector<int> result(n, 0);

        auto calculateVisits = [&](int start) {
            vector<int> path;
            unordered_map<int, int> indexMap;
            int node = start;

            while (memo[node] == -1 && indexMap.find(node) == indexMap.end()) {
                indexMap[node] = path.size();
                path.push_back(node);
                node = edges[node];
            }

            int cycleSize = 0;
            if (memo[node] == -1) {
                int cycleStartIndex = indexMap[node];
                cycleSize = path.size() - cycleStartIndex;
                for (int i = cycleStartIndex; i < path.size(); i++) {
                    memo[path[i]] = cycleSize;
                }
            }

            for (int i = path.size() - 1; i >= 0; i--) {
                if (memo[path[i]] == -1) {
                    memo[path[i]] = 1 + memo[edges[path[i]]];
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (memo[i] == -1) {
                calculateVisits(i);
            }
            result[i] = memo[i];
        }

        return result;
    }
};