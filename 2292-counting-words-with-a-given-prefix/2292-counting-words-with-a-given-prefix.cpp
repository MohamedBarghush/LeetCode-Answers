class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            bool flag = false;
            for (int j = 0, k = 0; j < pref.length(); j++) {
                if (words[i][j] != pref[k]) {
                    flag = true;
                    break;
                }
                k++;
            }
            if (!flag) count++;

        }

        return count;
    }
};