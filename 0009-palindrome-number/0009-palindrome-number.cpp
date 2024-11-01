class Solution {
public:
    bool isPalindrome(int x) {
        string pali = to_string(x);
        for (int i = 0; i < pali.length()/2; i++) {
            if (pali[i] != pali[pali.length()-1-i]) return false;
        }
        return true;
    }
};