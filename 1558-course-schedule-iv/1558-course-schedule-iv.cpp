class Solution {
public:
    vector<bool> checkIfPrerequisite(int numC, vector<vector<int>>& pre, vector<vector<int>>& q) {
        // Reachability Matrix (2d vector)
        vector<vector<bool>> isReachable(numC, vector<bool>(numC, false));
        // Adjacency List (vector)
        vector<vector<int>> adjList(numC);
        for (auto edge : pre)
            adjList[edge[0]].push_back(edge[1]);


        // BFS
        for (int i = 0; i < numC; i++) {
            queue<int> nodes;
            nodes.push(i);

            while (!nodes.empty()) {
                int top = nodes.front();
                nodes.pop();

                for (int j : adjList[top]) {
                    if (!isReachable[i][j]) {
                        isReachable[i][j] = true;
                        nodes.push(j);
                    }
                }
            }
        }

        // Deduce answer
        vector<bool> ans;
        for (int i = 0; i < q.size(); i++)
            ans.push_back(isReachable[q[i][0]][q[i][1]]);

        return ans;
    }
};