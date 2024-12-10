class Solution {
public:
    int maximumLength(string s) {
        int l = 0, r = 1, n = s.size();
        const int maxLength = 51;
        vector<int> cnt(26 * maxLength, 0);
        int ans = -1;

        while (r <= n) {
            while (r < n && s[r] == s[l]) r++;

            for (int i = r - 1; i >= l; i--) {
                int len = i - l + 1;
                int index = (s[l] - 'a') * maxLength + len;
                cnt[index] += r - i;

                if (cnt[index] > 2 && len > ans)
                    ans = len;
            }
            l = r;
            r++;
        }

        return ans;
    }
};