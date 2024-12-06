class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> ban(banned.begin(), banned.end());
        int sum = 0;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (ban.count(i)) continue;
            if (sum+i > maxSum) break;
            sum += i;
            count++;
        }

        return count;
    }
};