class Solution {
public:
    string addBinary(string a, string b) {
        // 2 pointers
        int p1 = a.length()-1;
        int p2 = b.length()-1;
        string result;
        int carry = 0;

        while (p1 >= 0 || p2 >= 0 || carry) {
            int sum = carry;

            if (p1 >= 0) {
                sum += a[p1] - '0';
                p1--;
            }

            if (p2 >= 0) {
                sum += b[p2] - '0';
                p2--;
            }

            result += (sum%2) + '0';
            carry = sum / 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
