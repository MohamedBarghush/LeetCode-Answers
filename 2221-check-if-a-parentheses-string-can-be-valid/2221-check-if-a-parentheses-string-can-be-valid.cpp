class Solution {
public:
    bool canBeValid(string s, string locked) {
        int unlocked_bitch = 0, unlocked_whore = 0; 
        int open = 0, close = 0;
        int n = s.length();
        if(n % 2 == 1) return false;

        for(int i = 0; i<n; i++) {
            if(locked[i] == '0') unlocked_bitch++;
            else if(s[i] == '(') open++;
            else {
                if(open > 0) open--;
                else if(unlocked_bitch > 0) unlocked_bitch--;
                else return false;
            }

            if(locked[n-i-1] == '0') unlocked_whore++;
            else if(s[n-i-1] == ')') close++;
            else {
                if(close > 0) close--;
                else if(unlocked_whore > 0) unlocked_whore--;
                else return false;
            }
        }

        return true;
    }
};