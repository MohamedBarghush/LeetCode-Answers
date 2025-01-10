class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> frequencies(26, 0);
        int count = 0;
        vector<string> ans;
        for (int i = 0; i < words2.size(); i++) {
            vector<int> temp(26,0);
            for (int j = 0; j < words2[i].length(); j++) {
                int idx = words2[i][j] - 'a';
                temp[idx]++;
                frequencies[idx] = max(frequencies[idx], temp[idx]);
            }
        }

        for (int i = 0; i < words1.size(); i++) {
            vector<int> temp = frequencies;
            for (int j = 0; j < words1[i].length(); j++) {
                if (temp[words1[i][j] - 'a'] > 0) {
                    temp[words1[i][j] - 'a']--;
                }
            }
            bool flag = true;
            for (int j = 0; j < 26; j++) {
                if (temp[j] > 0) { flag = false; break; }
            }
            if (flag) {
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};