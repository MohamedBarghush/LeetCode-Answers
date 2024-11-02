class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> loopDetector;
        while (n != 1) {
            string k = to_string(n);
            n = 0;
            for (char ch : k) n += (ch-'0')*(ch-'0');
            loopDetector[n]++;
            if (loopDetector[n] > 1) return false;
        }
        return true;
    }
};