class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& state, int currentIdx) {
        if (state[currentIdx] == 1) return false;
        else if (state[currentIdx] == 2) return true;

        state[currentIdx] = 1; // not safe yet

        for (int i : graph[currentIdx])
            if (!dfs(graph, state, i)) return false;

        state[currentIdx] = 2; // safe

        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);
        vector<int> ans;
        
        for (int i = 0; i < n; i++)
            if (dfs(graph, state, i)) ans.push_back(i);

        return ans;
    }
};