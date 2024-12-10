class Solution {
public:
    int maximumLength(string s) {
        int l = 0, r = 1, n = s.size();
        vector<vector<int>> cnt(26, vector<int>(60, 0));
        int ans = -1;
        while(r <= n){
            while(r < n && s[r] == s[l]) r++;
            for(int i = r-1; i>=l;i--){
                int len = i - l + 1;
                cnt[s[l]-'a'][len] += r-i;
                if(cnt[s[l]-'a'][len]>2 && len > ans)
                    ans = len;
            }
            l = r;
            r++;
        }
        return ans;
    }
};