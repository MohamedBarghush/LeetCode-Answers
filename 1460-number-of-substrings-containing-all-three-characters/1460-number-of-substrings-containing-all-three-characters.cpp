class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int p1 = 0, p2 = 0;
        vector<int> chars(3,0);
        int ans = 0;

        while (p2 < n) {
            char curr = s[p2];
            chars[curr - 'a']++;

            while (chars[0] > 0 && chars[1] > 0 && chars[2] > 0) {
                ans += n - p2;

                // char leftChar = s[p1];
                chars[s[p1] - 'a']--;
                p1++;
            }

            p2++;
        }

        return ans;
    }
};