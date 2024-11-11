class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> pattern_to_string;
        unordered_map<string, char> string_to_pattern;
        string word;
        int pattern_index = 0;

        for (int i = 0; i < s.length(); i++) {
            if (i == s.length() - 1) word = word + s[i];
            if (s[i] == ' ' || i == s.length() - 1) {
                if (pattern_to_string.count(pattern[pattern_index]) > 0) {
                    if (pattern_to_string[pattern[pattern_index]] != word) {
                        if (string_to_pattern[word] != pattern[pattern_index]) {
                            return false;
                        } else {
                            pattern_to_string[pattern[pattern_index]] = word;
                            // cout << pattern[pattern_index] << " to " << word << endl;
                            string_to_pattern[word] = pattern[pattern_index];
                            // cout << word << " to " << pattern[pattern_index] << endl;
                        }
                    }
                } else {
                    if (string_to_pattern.count(word) > 0) {
                        return false;
                    } else {
                        pattern_to_string[pattern[pattern_index]] = word;
                        // cout << pattern[pattern_index] << " to " << word << endl;
                        string_to_pattern[word] = pattern[pattern_index];
                        // cout << word << " to " << pattern[pattern_index] << endl;
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