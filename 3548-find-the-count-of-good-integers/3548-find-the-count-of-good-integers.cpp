class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        static long long C[11][11];
        for (int i = 0; i <= 10; i++) C[i][0] = C[i][i] = 1;
        for (int i = 2; i <= 10; i++) for (int j = 1; j < i; j++) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        int M = 1;
        for (int i = 0; i < (n + 1) / 2; i++) M *= 10;
        vector<long long> w;
        for (int i = M / 10; i < M; i++) {
            long long v = i;
            for (int j = 0, t = ((n & 1) ? i / 10 : i); j < n / 2; j++)
                v = v * 10 + (t % 10), t /= 10;
            if (v % k == 0) {
                int d[10] = {0,0,0,0,0,0,0,0,0,0};
                for (int t = 0; t < n; t++) d[v % 10]++, v /= 10;
                v = 0;
                for (int t = 0; t < 10; t++) v = v * 11 + d[t];
                w.push_back(v);
            }
        }
        sort(w.begin(), w.end());
        w.erase(unique(w.begin(), w.end()), w.end());
        long long ans = 0;
        for (long long v : w) {
            int d[10] = {0,0,0,0,0,0,0,0,0,0};
            for (int t = 9; t >= 0; t--) d[t] = v % 11, v /= 11;
            long long c = 1;
            for (int i = 0, r = n; i < 10; i++) c *= C[i ? r : r - 1][d[i]], r -= d[i];
            ans += c;
        }
        return ans;
    }
};