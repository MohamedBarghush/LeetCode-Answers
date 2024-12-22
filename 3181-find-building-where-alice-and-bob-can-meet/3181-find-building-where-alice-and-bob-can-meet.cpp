
constexpr int MAX_SZ = 5e4 + 10;
constexpr int INF = 1e5;
int tree[MAX_SZ*4];

void build_segs_tree(int val, int max_left, int max_right, vector<int>& heights) {
    if (max_right == max_left) {
        tree[val] = heights[max_left];
        return;
    }

    int max_mid = (max_right+max_left)/2;

    build_segs_tree(val*2+1, max_left, max_mid, heights);
    build_segs_tree(val*2+2, max_mid+1, max_right, heights);
    tree[val] = max(tree[val*2+1], tree[val*2+2]);
}

int greater_idx(int val, int max_left, int max_right, int left, int right, int min_val) {
    if (max_left > right || max_right < left)
        return INF;

    if (tree[val] < min_val)
        return INF;

    if (max_left == max_right)
        return max_left;

    int max_mid = max_left + (max_right-max_left)/2;

    int ltree_ans = greater_idx(val*2+1, max_left, max_mid, left, right, min_val);
    if (ltree_ans != INF) return ltree_ans; 

    return greater_idx(val*2+2, max_mid+1, max_right, left, right, min_val);
}

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> answers;
        answers.reserve(queries.size());
        
        int n = heights.size();
        build_segs_tree(0, 0, n-1, heights);

        for (auto& query : queries) {
            int a = query[0], b = query[1];
            if (a > b)
                swap(a, b);

            if (a == b) {
                answers.push_back(a);
                continue;
            }

            int min_height = max(heights[a], heights[b]);
            if (heights[a] >= heights[b]) {
                ++min_height;
            }

            int answer = greater_idx(0, 0, n-1, b, n-1, min_height);

            if (answer == INF)
                answer = -1;

            answers.push_back(answer);
        }


        return answers;
    }
};