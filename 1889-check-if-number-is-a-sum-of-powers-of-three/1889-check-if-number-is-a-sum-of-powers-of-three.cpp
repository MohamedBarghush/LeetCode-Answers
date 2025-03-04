class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 1) {
            int remain = n % 3;
            n = n / 3;
            if (remain > 1) return false;
        }
        return true;
    }
};