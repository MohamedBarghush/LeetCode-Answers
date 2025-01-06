class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        
        int balls = (boxes[0] == '1' ? 1 : 0);

        for (int i = 1; i < n; i++) {
            ans[i] = ans[i-1] + balls;
            balls += boxes[i] - '0';
        }

        balls = 0;
        int moves = 0;

        for (int i = n-1; i >= 0; i--) {
            ans[i] += moves;
            balls += boxes[i] - '0';
            moves += balls;
        }

        return ans;
    }
};