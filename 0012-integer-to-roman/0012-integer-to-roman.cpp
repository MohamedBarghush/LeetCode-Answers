class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> vals = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string ans = "";
        for (pair<int, string>& value : vals) {
            while (num >= value.first) {
                ans += value.second;
                num -= value.first;
            }
        }

        return ans;
    }
};