class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size())
            return "0";

        vector<char> monoShit;

        for (int i = 0; i < num.length(); i++) {
            while (!monoShit.empty() && num[i] < monoShit.back() && k > 0) {
                monoShit.pop_back();
                k--;
            }
            monoShit.push_back(num[i]);
        }

        while (k > 0 && !monoShit.empty()) {
            monoShit.pop_back();
            k--;
        }
        
        string res = "";
        for (char c : monoShit) {
            if (res.empty() && c=='0')
                continue;
            res.push_back(c);
        }

        return res.empty() ? "0" : res;
    }
};