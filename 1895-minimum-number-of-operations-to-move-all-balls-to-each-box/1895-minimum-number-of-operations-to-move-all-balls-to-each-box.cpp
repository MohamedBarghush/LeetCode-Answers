class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        
        for (int i = 1, balls = (boxes[0] - '0'); i < n; i++) {
            ans[i] = ans[i - 1] + balls;
            balls += (boxes[i] - '0');
        }

        for (int i = n - 2, balls = (boxes[n - 1] - '0'), moves = 0; i >= 0; i--) {
            moves += balls;
            ans[i] += moves;
            balls += (boxes[i] - '0');
        }

        return ans;
    }
};