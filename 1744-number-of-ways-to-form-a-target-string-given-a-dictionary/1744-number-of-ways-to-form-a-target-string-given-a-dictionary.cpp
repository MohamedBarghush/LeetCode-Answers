class Solution {
public:
    int numWays(const vector<string>& words, const string& target) {
        const int wl = words[0].size();
        const int tl = target.size();
        if (tl > wl) return 0;
        vector<array<int, 26>> char_cnt(wl, array<int, 26>{});
        for (const string& w : words)
            for (int k = 0; k < wl; ++k)
                ++char_cnt[k][w[k] - 'a'];

        constexpr int mod = 1000000007;
        vector<int> dp, new_dp;
        dp.reserve(wl - tl + 1);
        new_dp.reserve(wl - tl + 1);
        dp.emplace_back(char_cnt[0][target[0] - 'a']);
        for (int k = 1; k < wl; ++k) {
            const int start_i = max(0, (k - 1) + tl - wl);
            for (int i = max(0, k + tl - wl); i <= k && i < tl; ++i) {
                uint64_t cnt = (uint64_t) (i > 0 ? dp[(i - 1) - start_i] : 1) * char_cnt[k][target[i] - 'a'];
                if (i < k) cnt += dp[i - start_i];
                new_dp.emplace_back(cnt % mod);
            }
            std::swap(dp, new_dp);
            new_dp.clear();
        }
        return (int) (dp.back() % mod);
    }
};