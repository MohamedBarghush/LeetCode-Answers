class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> ban(1e4+1, 0); // following constraints
        for(int i : banned) ban[i] = 1;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (ban[i]) continue;
            if (maxSum >= i) {
                count++;
                maxSum -= i;
            }
        }

        return count;
    }
};