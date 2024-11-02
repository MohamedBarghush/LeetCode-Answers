class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> loopDetector;
        while (n != 1) {
            string k = to_string(n);
            // if (k.length() == 1) return false;
            long sum = 0;
            for (char ch : k) {
                int k = ch - '0';
                sum += k*k;
            }
            loopDetector[sum]++;
            if (loopDetector[sum] > 1) return false;
            n = sum;
        }
        return true;
    }
};