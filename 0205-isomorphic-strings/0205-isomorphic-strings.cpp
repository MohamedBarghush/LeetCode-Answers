class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> iso;
        unordered_map<char,int> taken;
        for (int i = 0; i < s.length(); i++) {
            if (iso[s[i]]) {
                if (iso[s[i]] == t[i]) {
                    continue;
                } else {
                    return false;
                }
            } else {
                if (taken[t[i]] < 1) {
                    iso[s[i]] = t[i];
                    taken[t[i]]++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};