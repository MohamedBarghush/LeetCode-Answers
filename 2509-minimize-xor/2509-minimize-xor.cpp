class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int countOnesNum2 = bitset<32>(num2).count();
        int countOnesNum1 = bitset<32>(num1).count();

        int result = num1;

        if (countOnesNum1 > countOnesNum2) {
            for (int i = 0; i < 32 && countOnesNum1 > countOnesNum2; i++) {
                if (result & (1 << i)) {
                    result &= ~(1 << i);
                    countOnesNum1--;
                }
            }
        } else if (countOnesNum1 < countOnesNum2) {
            for (int i = 0; i < 32 && countOnesNum1 < countOnesNum2; i++) {
                if (!(result & (1 << i))) {
                    result |= (1 << i);
                    countOnesNum1++;
                }
            }
        }

        return result;
    }
};