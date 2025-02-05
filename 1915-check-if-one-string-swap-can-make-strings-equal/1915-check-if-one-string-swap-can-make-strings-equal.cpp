class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int s1Hash[26] = {}, s2Hash[26] = {};
        int count = 0, n = s1.length();
        for (int i = 0; i < n; i++) {
            s1Hash[s1[i] - 'a']++;
            s2Hash[s2[i] - 'a']++;
            if (s1[i] != s2[i]) count++;
        }

        if (count != 0 && count != 2) return false;

        for (int i = 0; i < 26; i++) {
            if (s1Hash[i] != s2Hash[i]) return false;
        }

        return true;
    }
};