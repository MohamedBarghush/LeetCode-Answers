class Solution {
public:
    int maximumLength(string s) {
        int l = 0, r = 1, n = s.size();
        int cnt[26*51] = {}; // combined into 1 array
        int ans = -1, len = 0;
        while(r <= n) {
            while(r < n && s[r] == s[l]) r++;
            for(int i = r-1; i>=l;i--) {
                len = i - l + 1;
                cnt[(s[l]-'a')+(26*len)] += r-i;
                if(cnt[(s[l]-'a')+(26*len)]>2 && len > ans)
                    ans = len;
            }
            l = r;
            r++;
        }
        return ans;
    }
};
