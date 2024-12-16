class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_to_int = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int res = 0;
        char last = 'A';
        for (int i = s.length(); i >= 0; i--) {
            if (s[i] == 'I') {
                if (last == 'V' || last == 'X') {
                    res -= roman_to_int[s[i]];
                    last = s[i];
                    continue;
                }
            } else if (s[i] == 'X') {
                if (last == 'L' || last == 'C') {
                    res -= roman_to_int[s[i]];
                    last = s[i];
                    continue;
                }
            } else if (s[i] == 'C') {
                if (last == 'D' || last == 'M') {
                    res -= roman_to_int[s[i]];
                    last = s[i];
                    continue;
                }
            }
            res += roman_to_int[s[i]];
            last = s[i];
        }

        return res;
    }
};