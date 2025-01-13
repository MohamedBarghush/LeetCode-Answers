class Solution {
public:
    int minimumLength(string s) {
        int chars[26] = {}; // my arr
        int n = s.length();
        int count = 0;
        for (int i = 0; i < n; i++)
            chars[s[i] - 'a']++;

        for (int i = 0; i < 26; i++) {
            count += (chars[i] % 2 == 1 ? 1 : (chars[i] != 0 ? 2 : 0));
        }

        return count;
    }
};