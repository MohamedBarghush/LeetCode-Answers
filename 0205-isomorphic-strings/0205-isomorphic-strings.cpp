class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> s_to_t(256, -1);
        vector<int> t_to_s(256, -1);
        for (int i = 0; i < s.length(); i++) {
            // if s ! map to t
            if (s_to_t[s[i]] == -1) {
                if (t_to_s[t[i]] == -1) {
                    s_to_t[s[i]] = t[i];
                    t_to_s[t[i]] = s[i];
                } else {
                    return false;
                }
            } else {
                if (s_to_t[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};