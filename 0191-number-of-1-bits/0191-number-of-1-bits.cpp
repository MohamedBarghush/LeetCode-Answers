class Solution {
public:
    int hammingWeight(int n) {
        int setBits;
        while (n > 0) {
            setBits += n % 2;
            n /= 2;
        }

        return setBits;
    }
};