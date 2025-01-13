class Solution {
public:
    int minimumLength(string s) {
        int chars[26] = {};
        int n = s.length();
        int count = n;
        for (int i = 0; i < n; i++)
            chars[s[i] - 'a']++;

        for (int i = 0; i < 26; i++) {
            while (chars[i] >= 3) {
                chars[i]-=2;
                count -= 2;
            }
        }

        return count;
    }
};