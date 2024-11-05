class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> iso;
        unordered_set<char> mapped_chars;
        for (int i = 0; i < s.length(); i++) {
            if (iso.count(s[i])) {
                if (iso[s[i]] != t[i]) return false;
            } else {
                if (mapped_chars.count(t[i])) return false;
                iso[s[i]] = t[i];
                mapped_chars.insert(t[i]);
            }
        }
        return true;
    }
};