class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size()-1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
                continue;
            }
            digits[i]++;
            return digits;
        }
        if (digits[0] == 0) {
            digits.insert(digits.begin(),1);
            return digits;
        }
        digits[digits.size()-1]++;
        return digits;
    }
};