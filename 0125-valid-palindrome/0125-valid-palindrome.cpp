class Solution {
public:
    bool isPalindrome(string s) {
        char *p1 = &s[0];
        char *p2 = &s[s.length()-1];
        while (p2 >= p1) {
            if ((*p1) < 48 || ((*p1) > 57 && (*p1) < 65) || ((*p1) > 90 && (*p1) < 97) || (*p1) > 122) {
                p1++;
                continue;
            }
            if ((*p2) < 48 || ((*p2) > 57 && (*p2) < 65) || ((*p2) > 90 && (*p2) < 97) || (*p2) > 122) {
                p2--;
                continue;
            }
            if ((char)tolower(*p1) == (char)tolower(*p2)) {
                p1++;
                p2--;
            } else {
                return false;
            }
        }
        return true;
    }
};