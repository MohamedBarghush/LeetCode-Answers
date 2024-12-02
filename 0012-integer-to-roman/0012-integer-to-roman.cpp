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
            int actual = (val[i] - '0') * pow(10, val.length() - (i+1));
            if (vals.count(actual) > 0) {
                ans = vals[actual] + ans;
            } else {
                int toAddSingular = 0;
                if ((val[i] - '0') > 5) {
                    toAddSingular = (val[i] - '0') - 5;
                } else {
                    toAddSingular = val[i] - '0';
                }
                for (int j = 0; j < toAddSingular; j++)
                    ans = vals[actual / (val[i] - '0')] + ans;

                if ((val[i] - '0') > 5) {
                    ans = vals[(val[i] - '0' - toAddSingular) * pow(10, val.length() - (i+1))] + ans;
                }
            }
        }

        return ans;
    }
};