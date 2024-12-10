class Solution {
public:
    int maximumLength(string s) {
        int l = 0, r = 1, n = s.size();
        int cnt[26*51] = {};
        int ans = -1;
        while(r <= n) {
            while(r < n && s[r] == s[l]) r++;
            for(int i = r-1; i>=l;i--) {
                cnt[(s[l]-'a')+(26*(i - l + 1))] += r-i;
                if(cnt[(s[l]-'a')+(26*(i - l + 1))]>2 && (i - l + 1) > ans)
                    ans = (i - l + 1);
            }
            l = r;
            r++;
        }
        return ans;
    }
};