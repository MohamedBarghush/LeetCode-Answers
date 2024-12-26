class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size())
            return "0";
            
        stack<char> monoShit;

        for (int i = 0; i < num.length(); i++) {
            while (!monoShit.empty() && num[i] < monoShit.top() && k > 0) {
                monoShit.pop();
                k--;
            }
            monoShit.push(num[i]);
        }

        while (k > 0 && !monoShit.empty()) {
            monoShit.pop();
            k--;
        }
        
        string res = "";
        while (!monoShit.empty()) {
            res.push_back(monoShit.top());
            monoShit.pop();
        }

        for (int i = res.length()-1; i >= 0; i--) {
            if (res[i] != '0')
                break;
            res.pop_back();
        }
            
        reverse(res.begin(), res.end());

        return res.empty() ? "0" : res;
    }
};