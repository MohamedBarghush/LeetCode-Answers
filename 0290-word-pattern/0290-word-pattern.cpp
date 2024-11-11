class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // maps front to back
        // maps back to front
        unordered_map<char, string> pattern_to_string;
        unordered_map<string, char> string_to_pattern;
        string word;
        int pattern_index = 0;

        for (int i = 0; i < s.length(); i++) {
            if (i == s.length() - 1) 
                if (pattern_index == pattern.length() - 1)
                    word = word + s[i];
                else 
                    return false;
            if (s[i] == ' ' || i == s.length() - 1) {
                if (pattern_to_string.count(pattern[pattern_index]) > 0) {
                    if (pattern_to_string[pattern[pattern_index]] != word) {
                        if (string_to_pattern[word] != pattern[pattern_index]) {
                            return false;
                        } else {
                            pattern_to_string[pattern[pattern_index]] = word;
                            string_to_pattern[word] = pattern[pattern_index];
                        }
                    }
                } else {
                    if (string_to_pattern.count(word) > 0) {
                        return false;
                    } else {
                        pattern_to_string[pattern[pattern_index]] = word;
                        string_to_pattern[word] = pattern[pattern_index];
                    }
                }
                pattern_index++;
                word = "";
                continue;
            }
            word = word + s[i];
        }
        return true;
    }
};