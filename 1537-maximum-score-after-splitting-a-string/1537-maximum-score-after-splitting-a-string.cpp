class Solution {
public:
    int maxScore(string s) {
        int zeros_L = 0;
        int maxi = 0;
        vector<int> prefix(s.length(), 0);
        prefix[0] = s[0] - '0';
        for (int i = 1; i < s.length(); i++)
            prefix[i] = prefix[i-1] + (s[i] - '0');

        for (int i = 0; i < s.length()-1; i++) {
            if (s[i] == '0')
                zeros_L ++;
            maxi = max(maxi, zeros_L + prefix.back() - prefix[i]);
        }

        return maxi;
    }
};