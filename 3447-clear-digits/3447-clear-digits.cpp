class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i]) && ans != "")
                ans.pop_back();
            else
                ans+=s[i];
        }

        return ans;
    }
};