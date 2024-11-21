class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int ana_one[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            ana_one[s[i]-'a']++;
            ana_one[t[i]-'a']--;
        }

        for (int count : ana_one)
            if (count != 0)
                return false;

        return true;
    }
};