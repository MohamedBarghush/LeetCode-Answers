class Solution {
public:
    int minimumLength(string s) {
        int chars[26] = {};
        int n = s.length();
        for (int i = 0; i < n; i++)
            chars[s[i] - 'a']++;

        for (int i = 0; i < 26; i++) {
            while (chars[i] >= 3) chars[i]-=2;
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            count += chars[i];
        }

        return count;
    }
};