class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> f(26, -1); // first indices
        vector<int> l(26, -1); // last indices

        for (int i = 0; i < s.length(); i++) {
            int curr = s[i] - 'a';
            if (f[curr] == -1)
                f[curr] = i;

            l[curr] = i;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (f[i] == -1) continue;

            unordered_set<char> between;
            for (int j = f[i] + 1; j < l[i]; j++)
                between.insert(s[j]);

            ans += between.size();
        }

        return ans;
    }
};