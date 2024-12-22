
constexpr int MAX_SZ = 5e4 + 10;
constexpr int INF = 1e5;
int tree[MAX_SZ*4];

void build_tree(int v, int tl, int tr, vector<int>& heights) {
    if (tl == tr) {
        tree[v] = heights[tl];
        return;
    }

    int tm = (tl+tr)/2;

    build_tree(v*2+1, tl, tm, heights);
    build_tree(v*2+2, tm+1, tr, heights);
    tree[v] = max(tree[v*2+1], tree[v*2+2]);
}

int leftmost_greater_idx(int v, int tl, int tr, int l, int r, int min_val) {
    if (tl > r || tr < l) {
        return INF;
    }

    if (tree[v] < min_val) {
        return INF;
    }

    if (tl == tr) {
        return tl;
    }

    int tm = (tl+tr)/2;

    int ltree_ans = leftmost_greater_idx(v*2+1, tl, tm, l, r, min_val);
    if (ltree_ans != INF) return ltree_ans; 

    return leftmost_greater_idx(v*2+2, tm+1, tr, l, r, min_val);
}

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> answers;
        answers.reserve(queries.size());
        
        int n = heights.size();
        build_tree(0, 0, n-1, heights);

        // auto mapped_heigts = map_heights(heights);
        for (auto& query : queries) {
            int a = query[0], b = query[1];
            if (a > b) {
                swap(a, b);
            }

            if (a == b) {
                answers.push_back(a);
                continue;
            }

            int min_height = max(heights[a], heights[b]);
            if (heights[a] >= heights[b]) {
                ++min_height;
            }

            int answer = leftmost_greater_idx(
                0, 
                0, n-1, 
                b, n-1, 
                min_height
            );

            if (answer == INF) {
                answer = -1;
            }

            answers.push_back(answer);
        }


        return answers;
    }
};