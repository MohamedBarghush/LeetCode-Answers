class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        unordered_map<string, int> count_map;
        
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            string current_substring = "";
            
            for (int length = 1; i + length <= n; length++) {
                current_substring += ch;
                if (s.substr(i, length) == current_substring) {
                    count_map[current_substring]++;
                } else {
                    break;
                }
            }
        }
        
        int max_len = -1;
        for (const auto& entry : count_map) {
            if (entry.second >= 3) {
                max_len = max(max_len, static_cast<int>(entry.first.length()));
            }
        }
        
        return max_len;
    }
};