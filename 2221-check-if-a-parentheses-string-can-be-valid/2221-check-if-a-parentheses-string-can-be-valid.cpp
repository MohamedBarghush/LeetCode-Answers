class Solution {
public:
    bool canBeValid(string s, string locked) {
        int ul = 0, ur = 0, open = 0, close = 0, n = s.length();
        if(n % 2) return false; // will never work

        for(int i = 0; i<n; i++) {
            if(locked[i] == '0') ul++;
            else if(s[i] == '(') open++;
            else {
                if(open > 0) open--;
                else if(ul > 0) ul--;
                else return false;
            }

            if(locked[n-i-1] == '0') ur++;
            else if(s[n-i-1] == ')') close++;
            else {
                if(close > 0) close--;
                else if(ur > 0) ur--;
                else return false;
            }
        }

        return true;
    }
};