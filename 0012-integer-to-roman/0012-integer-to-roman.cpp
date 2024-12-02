class Solution {
public:
    string intToRoman(int num) {
        string val = to_string(num);
        string ans;
        unordered_map<int, string> vals = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        for (int i = val.length()-1; i >= 0; i--) {
            int value = val[i] - '0';
            int actual = value * pow(10, val.length() - (i+1));
            if (vals.count(actual) > 0) {
                ans = vals[actual] + ans;
            } else {
                int toAddSingular = 0;
                if (value > 5) {
                    toAddSingular = value - 5;
                } else {
                    toAddSingular = value;
                }
                for (int j = 0; j < toAddSingular; j++)
                    ans = vals[actual / value] + ans;

                if (value > 5) {
                    ans = vals[(value - toAddSingular) * pow(10, val.length() - (i+1))] + ans;
                }
            }
        }

        return ans;
    }
};