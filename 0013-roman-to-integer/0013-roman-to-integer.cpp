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
        }; // prestore
        int res = 0;
        char last = 'A';
        for (int i = s.length(); i >= 0; i--) {
            if (roman_to_int[s[i]] < roman_to_int[last])
                res -= roman_to_int[s[i]];
            else 
                res += roman_to_int[s[i]];
            last = s[i];
        }

        return res;
    }
};