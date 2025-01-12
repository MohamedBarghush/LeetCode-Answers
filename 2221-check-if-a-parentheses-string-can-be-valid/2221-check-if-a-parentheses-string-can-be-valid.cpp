class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n % 2) return false;
        int min = 0, max = 0;
        for(int i = 0; i < n; i++){
            if(locked[i] == '1'){
                if(s[i] == '('){
                    min++;
                    max++;
                }else{
                    min--;
                    max--;
                }
            }else{
                min--;
                max++;
            }
            if(min < 0) min=0;
            if(max < 0) return false;
        }
        return (min == 0);
    }
};