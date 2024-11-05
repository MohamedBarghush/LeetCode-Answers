class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> iso;
        unordered_map<char, char> reverseIso;
        for (int i = 0; i < s.length(); i++) {
            if (iso.count(s[i])) {
                if (iso[s[i]] != t[i]) return false;
            } else {
                if (reverseIso.count(t[i]) && reverseIso[t[i]] != s[i]) return false;
                iso[s[i]] = t[i];
                reverseIso[t[i]] = s[i];
            }
        }
        return true;
    }
};