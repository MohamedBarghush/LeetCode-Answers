class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> loopDetector;
        while (n != 1) {
            string k = to_string(n);
            n = 0;
            for (char ch : k)  {
                int k = ch - '0';
                n += k*k; //
            }
            loopDetector[n]++;
            if (loopDetector[n] > 1) return false;
        }
        return true;
    }
};