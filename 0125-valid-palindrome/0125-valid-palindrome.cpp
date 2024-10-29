class Solution {
public:
    bool isPalindrome(string s) {
        char *p1 = &s[0];
        char *p2 = &s[s.length()-1];
        while (p2 >= p1) {
            if (!isalnum(*p1)) {
                p1++;
                continue;
            }
            if (!isalnum(*p2)) {
                p2--;
                continue;
            }
            if ( (char)tolower(*p1) == (char)tolower(*p2) ) {
                p1++;
                p2--;
            } else {
                return false;
            }
        }
        return true;
    }
};