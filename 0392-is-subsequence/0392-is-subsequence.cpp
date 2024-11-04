class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() == 0) return true;
        if (t.length() == 0) return false;
        int p1 = 0, p2 = 0;
        while (p1 < s.length() && p2 < t.length()) {
            if (s[p1] == t[p2]) {
                p1++;
                p2++;
            } else 
                p2++;
                
            if (p1 == s.length()) return true;
        }
        return false;
    }
};