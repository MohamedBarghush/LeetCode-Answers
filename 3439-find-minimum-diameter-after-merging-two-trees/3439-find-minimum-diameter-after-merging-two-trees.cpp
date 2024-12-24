class Solution {
public:
    int diameter(int root, int parent, vector<vector<int>> &graph, int &ans){
        int mx1 = -1, mx2 = -1;
        for(auto &child: graph[root]){
            if(child != parent){
                int m = diameter(child, root, graph, ans);
                if(m >= mx1){
                    mx2 = mx1;
                    mx1 = m;
                }
                else if(m > mx2) mx2 = m;
            }
        }

        if(mx2 != -1) ans = max(ans, 2 + mx1 + mx2);
        if(mx1 != -1) ans = max(ans, 1 + mx1);

        if(mx1 != -1){
            return 1 + mx1;
        }
        return 0;

    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        
        int m = edges1.size() + 1;
        int n  = edges2.size() + 1;

        vector<vector<int>> graph1(m), graph2(n);

        for(auto &edge: edges1){
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }
        for(auto &edge: edges2){
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }

        int dia1 = 0, dia2 = 0;
        diameter(0, -1, graph1, dia1);
        diameter(0, -1, graph2, dia2);

        int ans = max({dia1, dia2, (dia1 / 2) + (dia1 % 2) + (dia2 / 2) + (dia2 % 2) + 1});

        return ans;

    }
};