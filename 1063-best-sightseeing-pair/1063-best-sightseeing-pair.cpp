class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi = values[0];
        int maxi_right = values[0];
        for (int i = 1; i < values.size(); i++) {
            maxi = max(maxi, maxi_right + values[i] - i);
            maxi_right = max(maxi_right, values[i] + i);
        }

        return maxi;
    }
};