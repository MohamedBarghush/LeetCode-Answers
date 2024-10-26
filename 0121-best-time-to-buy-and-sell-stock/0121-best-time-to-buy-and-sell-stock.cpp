class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;

        int minSoFar = prices[0];
        int maxSoFar = 0;
        int deal = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] > maxSoFar && prices[i] - minSoFar > deal) {
                maxSoFar = prices[i];
                deal = maxSoFar - minSoFar;
            }
            if (prices[i] < minSoFar)
            {
                minSoFar = prices[i];
                maxSoFar = 0;
                continue;
            }
        }

        if (deal > 0) {
            return deal;
        }
        return 0;
    }
};