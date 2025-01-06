class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);

        int balls_L = 0, moves_L = 0;
        int balls_R = 0, moves_R = 0;

        for (int i = 0; i < n; i++) {
            ans[i] += moves_L;
            balls_L += boxes[i] - '0';
            moves_L += balls_L;

            int j = n - 1 - i;
            ans[j] += moves_R;
            balls_R += boxes[j] - '0';
            moves_R += balls_R;
        }

        return ans;
    }
};