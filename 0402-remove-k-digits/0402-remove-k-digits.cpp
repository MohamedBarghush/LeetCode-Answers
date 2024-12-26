class Solution {
public:
    string removeKdigits(string num, int k) {
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
        
        string res(monoShit.begin(), monoShit.end());

        int lastZero = 0;
        while (lastZero < res.size() && res[lastZero] == '0')
            lastZero++;
        res = res.substr(lastZero);

        return res.empty() ? "0" : res;
    }
};