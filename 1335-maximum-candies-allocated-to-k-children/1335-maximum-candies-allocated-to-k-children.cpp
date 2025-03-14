class Solution {
    bool canAllocate (vector<int>& candies, int& n, long long& k, int numOfCandies) {
        long long maxChildren = 0;

        for (int i = 0; i < n; i++)
            maxChildren += candies[i] / numOfCandies;

        return maxChildren >= k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int maxCandies = 0, n = candies.size();
        for (int i = 0; i < n; i++)
            maxCandies = max(maxCandies, candies[i]);

        int l = 0, r = maxCandies;
        while (l < r) {
            int mid = (l + r + 1) / 2;

            if (canAllocate(candies, n, k, mid)) l = mid;
            else r = mid-1;

        }
        return l;
    }
};