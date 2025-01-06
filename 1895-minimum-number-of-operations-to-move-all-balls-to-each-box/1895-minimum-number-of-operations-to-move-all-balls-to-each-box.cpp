class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);

        for (int i = 1, balls = (boxes[0] == '1' ? 1 : 0); i < n; i++) {
            ans[i] = ans[i-1] + balls;
            balls += boxes[i] - '0';
        }
        for (int i = n-1, balls = 0, moves = 0; i >= 0; i--) {
            ans[i] += moves;
            balls += boxes[i] - '0';
            moves += balls;
        }

        return ans;
    }
};