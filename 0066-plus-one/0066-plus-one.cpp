class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits[digits.size()-1] == 9) {
            if (digits.size() == 1) {
                digits[0] = 0;
                digits.insert(digits.begin(), 1);
                return digits;
            }
            // bool flag = false;
            for (int i = digits.size()-1; i >= 0; i--) {
                if (digits[i] == 9) {
                    digits[i] = 0;
                    if (i == 0) {
                        digits.insert(digits.begin(),1);
                        return digits;
                    }
                    continue;
                }
                digits[i]++;
                return digits;
            }
        }
        digits[digits.size()-1]++;
        return digits;
    }
};